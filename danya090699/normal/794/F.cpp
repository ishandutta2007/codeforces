#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10;
int ar[sz], sum[sz*4][10], add[sz*4][10], lg, rg, fr, to;
void recalc(int nu)
{
    for(int a=0; a<10; a++) sum[nu][a]=0;
    for(int a=0; a<10; a++) sum[nu][add[nu*2][a]]+=sum[nu*2][a];
    for(int a=0; a<10; a++) sum[nu][add[nu*2+1][a]]+=sum[nu*2+1][a];
}
void push(int nu)
{
    for(int a=0; a<10; a++) add[nu*2][a]=add[nu][add[nu*2][a]];
    for(int a=0; a<10; a++) add[nu*2+1][a]=add[nu][add[nu*2+1][a]];
    for(int a=0; a<10; a++) add[nu][a]=a;
}
void build(int nu, int l, int r)
{
    for(int a=0; a<10; a++) add[nu][a]=a;
    if(l==r)
    {
        for(int a=0; a<10; a++) sum[nu][a]=0;
        for(int a=1; a<1e10; a*=10)
        {
            sum[nu][ar[l]%10]+=a;
            ar[l]/=10;
            if(ar[l]==0) break;
        }
    }
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        for(int a=0; a<10; a++) if(add[nu][a]==fr) add[nu][a]=to;
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        int cu=0;
        for(int a=0; a<10; a++) cu+=add[nu][a]*sum[nu][a];
        return cu;
    }
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        push(nu);
        int cu=que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
        recalc(nu);
        return cu;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n; a++) cin>>ar[a];
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%lld%lld%lld", &ty, &lg, &rg);
        lg--, rg--;
        if(ty==1)
        {
            scanf("%lld%lld", &fr, &to);
            cha(1, 0, n-1);
        }
        else cout<<que(1, 0, n-1)<<"\n";
    }
}