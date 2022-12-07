#include <bits/stdc++.h>
#define int long long
using namespace std;
int dot[1<<19], ar[1<<18];
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
int p;
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
int d=0;
int lg, rg;
int que(int i, int nu, int nu2, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu2];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        if(d&(1<<i))
        {
            return que(i-1, nu*2, nu2*2+1, l, mid)+que(i-1, nu*2+1, nu2*2, mid+1, r);
        }
        else
        {
            return que(i-1, nu*2, nu2*2, l, mid)+que(i-1, nu*2+1, nu2*2+1, mid+1, r);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<(1<<n); a++) scanf("%lld", &ar[a]);
    build(1, 0, (1<<n)-1);
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%lld", &ty);
        if(ty==1)
        {
            scanf("%lld", &p);
            p--, p^=d;
            scanf("%lld", &ar[p]);
            cha(1, 0, (1<<n)-1);
        }
        if(ty==2)
        {
            int i;
            scanf("%lld", &i);
            d^=((1<<i)-1);
        }
        if(ty==3)
        {
            int i;
            scanf("%lld", &i);
            d^=(1<<i);
        }
        if(ty==4)
        {
            scanf("%lld%lld", &lg, &rg);
            lg--, rg--;
            printf("%lld\n", que(n-1, 1, 1, 0, (1<<n)-1));
        }
    }
}