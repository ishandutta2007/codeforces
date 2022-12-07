#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int dot[sz*4], add[sz*4][10], ar[sz], n, mod, dq, phi;
vector <int> de, ste[10];
int ef(int x)
{
    int re=x;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            while(x%a==0) x/=a;
            re-=re/a;
        }
    }
    if(x!=1) re-=re/x;
    return re;
}
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
int st(int i, int q)
{
    while(q>=ste[i].size())
    {
        int x=1;
        if(ste[i].size()) x=(1ll*ste[i].back()*de[i])%mod;
        ste[i].push_back(x);
    }
    return ste[i][q];
}
void get(int x, int *to)
{
    for(int a=0; a<dq; a++)
    {
        to[a]=0;
        while(x%de[a]==0) x/=de[a], to[a]++;
    }
    to[dq]=x%mod;
}
int val(int *x)
{
    int re=1;
    for(int a=0; a<dq; a++) re=(1ll*re*st(a, x[a]))%mod;
    re=(1ll*re*x[dq])%mod;
    return re;
}
void mul(int *x, int *y)
{
    for(int a=0; a<dq; a++) x[a]+=y[a];
    x[dq]=(1ll*x[dq]*y[dq])%mod;
}
void div(int *x, int *y)
{
    for(int a=0; a<dq; a++) x[a]-=y[a];
    x[dq]=(1ll*x[dq]*po(y[dq], phi-1))%mod;
}
void cl(int *x)
{
    for(int a=0; a<dq; a++) x[a]=0;
    x[dq]=1;
}
void push(int nu)
{
    mul(add[nu*2], add[nu]);
    mul(add[nu*2+1], add[nu]);
    cl(add[nu]);
}
void recalc(int nu)
{
    dot[nu]=(1ll*dot[nu*2]*val(add[nu*2])+1ll*dot[nu*2+1]*val(add[nu*2+1]))%mod;
}
void build(int nu, int l, int r)
{
    cl(add[nu]);
    if(l==r) dot[nu]=1, get(ar[l], add[nu]);
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int p, va[10];
void cha(int nu, int l, int r)
{
    if(l==r) div(add[nu], va);
    else
    {
        push(nu);
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int lg, rg;
void cha2(int nu, int l, int r)
{
    if(l>=lg and r<=rg) mul(add[nu], va);
    else if(!(l>rg or r<lg))
    {
        push(nu);
        int mid=(l+r)>>1;
        cha2(nu*2, l, mid);
        cha2(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return (1ll*dot[nu]*val(add[nu]))%mod;
    else if(l>rg or r<lg) return 0;
    else
    {
        push(nu);
        int mid=(l+r)>>1;
        int re=(que(nu*2, l, mid)+que(nu*2+1, mid+1, r))%mod;
        recalc(nu);
        return re;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>mod;
    phi=ef(mod);
    int x=mod;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            de.push_back(a);
            while(x%a==0) x/=a;
        }
    }
    if(x>1) de.push_back(x);
    dq=de.size();

    for(int a=0; a<n; a++) scanf("%d", &ar[a]);

    build(1, 0, n-1);

    int qq;
    cin>>qq;
    for(int a=0; a<qq; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int x;
            scanf("%d%d%d", &lg, &rg, &x);
            lg--, rg--, get(x, va);
            cha2(1, 0, n-1);
        }
        else if(ty==2)
        {
            int x;
            scanf("%d%d", &p, &x);
            p--, get(x, va);
            cha(1, 0, n-1);
        }
        else
        {
            scanf("%d%d", &lg, &rg);
            lg--, rg--;
            printf("%d\n", que(1, 0, n-1));
        }
    }
}