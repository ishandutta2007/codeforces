#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=4e5+10, sz2=300, mod=1e9+7;
vector <int> pri;
int bnu[sz2+1], rev[sz2+1];
int dot[2][sz*4], add[2][sz*4];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
void push(int i, int nu)
{
    if(i)
    {
        add[1][nu*2]=(add[1][nu*2]*add[1][nu])%mod;
        add[1][nu*2+1]=(add[1][nu*2+1]*add[1][nu])%mod;
        add[1][nu]=1;
    }
    else
    {
        add[0][nu*2]|=add[0][nu];
        add[0][nu*2+1]|=add[0][nu];
        add[0][nu]=0;
    }
}
void recalc(int i, int nu, int l, int r)
{
    int mid=(l+r)>>1;
    if(i)
    {
        int lva=(dot[1][nu*2]*po(add[1][nu*2], mid-l+1))%mod;
        int rva=(dot[1][nu*2+1]*po(add[1][nu*2+1], r-mid))%mod;
        dot[1][nu]=(lva*rva)%mod;
    }
    else
    {
        dot[0][nu]=(dot[0][nu*2]|add[0][nu*2])|(dot[0][nu*2+1]|add[0][nu*2+1]);
    }
}
int ar[2][sz];
void build(int i, int nu, int l, int r)
{
    add[1][nu]=i;
    if(l==r) dot[i][nu]=ar[i][l];
    else
    {
        int mid=(l+r)>>1;
        build(i, nu*2, l, mid);
        build(i, nu*2+1, mid+1, r);
        recalc(i, nu, l, r);
    }
}
int lg, rg, va;
void cha(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if(i) add[1][nu]=(add[1][nu]*va)%mod;
        else add[0][nu]|=va;
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(i, nu);
        cha(i, nu*2, l, mid);
        cha(i, nu*2+1, mid+1, r);
        recalc(i, nu, l, r);
    }
}
int que(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if(i) return (dot[1][nu]*po(add[1][nu], r-l+1))%mod;
        else return dot[0][nu]|add[0][nu];
    }
    else if(l>rg or r<lg) return i;
    else
    {
        int mid=(l+r)>>1;
        push(i, nu);
        int lva=que(i, nu*2, l, mid);
        int rva=que(i, nu*2+1, mid+1, r);
        int re;
        if(i) re=(lva*rva)%mod;
        else re=lva|rva;
        recalc(i, nu, l, r);
        return re;
    }
}
int get_mask(int x)
{
    int mask=0;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            mask+=(1ll<<bnu[a]);
            while(x%a==0) x/=a;
        }
    }
    if(x>1) mask+=(1ll<<bnu[x]);
    return mask;
}
main()
{
    for(int a=2; a<=sz2; a++)
    {
        int pr=1;
        for(int b=2; b<a; b++) if(a%b==0) pr=0;
        if(pr)
        {
            rev[a]=po(a, mod-2);
            bnu[a]=pri.size();
            pri.push_back(a);
        }
    }
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[1][a]);
        ar[0][a]=get_mask(ar[1][a]);
    }
    for(int i=0; i<2; i++) build(i, 1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        char ty[10];
        scanf("%s", ty);
        if(ty[0]=='T')
        {
            scanf("%lld%lld", &lg, &rg);
            lg--, rg--;
            int mask=que(0, 1, 0, n-1), an=que(1, 1, 0, n-1);
            for(int i=0; i<pri.size(); i++)
            {
                if(mask&(1ll<<i))
                {
                    int x=pri[i];
                    an=(an*rev[x])%mod;
                    an=(an*(x-1))%mod;
                }
            }
            printf("%lld\n", an);
        }
        else
        {
            int x;
            scanf("%lld%lld%lld", &lg, &rg, &x);
            lg--, rg--, va=x;
            cha(1, 1, 0, n-1);
            va=get_mask(x);
            cha(0, 1, 0, n-1);
        }
    }
}