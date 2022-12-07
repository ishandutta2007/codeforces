#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10, inf=1e18;
int n, q, su=0, ar[sz], dot[sz*4];
int p, va, lg, rg;
set <int> hi, lo;
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=va;
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[nu]=min(dot[nu*2], dot[nu*2+1]);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)>>1;
        return min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
void ins(int i, bool ty)
{
    if(i>0 and i<n-1)
    {
        int x=-ar[i-1], y=ar[i];
        if(x>y) swap(x, y);
        if(x>=0)
        {
            if(ty) hi.insert(i);
            else hi.erase(i);
        }
        else if(y<0)
        {
            if(ty) lo.insert(i);
            else lo.erase(i);
        }
        else
        {
            p=i, va=-x;
            if(ty==0) va=inf;
            cha(1, 0, n-1);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int pr, x;
    cin>>n>>pr;
    for(int a=0; a<n-1; a++)
    {
        scanf("%lld", &x);
        ar[a]=pr-x, pr=x, su+=abs(ar[a]);
    }
    for(int a=0; a<n*4; a++) dot[a]=inf;
    for(int a=1; a<n-1; a++) ins(a, 1);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%lld%lld%lld%lld", &ty, &lg, &rg, &x);
        lg--, rg--;
        if(ty==1)
        {
            int an=-inf;
            if(lg==0)
            {
                an=max(an, abs(ar[0]+x)-abs(ar[0])), lg++;
            }
            if(rg==n-1)
            {
                an=max(an, abs(ar[n-2]-x)-abs(ar[n-2])), rg--;
            }
            if(lg<=rg)
            {
                auto it=hi.lower_bound(lg);
                if(it!=hi.end()) if((*it)<=rg) an=2*x;
                if(an<2*x)
                {
                    it=lo.lower_bound(lg);
                    if(it!=lo.end())
                    {
                        if((*it)<=rg)
                        {
                            int p=*it;
                            an=max(an, abs(ar[p-1]-x)+abs(ar[p]+x)-abs(ar[p-1])-abs(ar[p]));
                        }
                    }
                    int d=que(1, 0, n-1);
                    if(d!=inf)
                    {
                        x=max(x-d, 0ll);
                        an=max(an, x*2);
                    }
                }
            }
            printf("%lld\n", su+an);
        }
        else
        {
            ins(lg-1, 0), ins(lg, 0), ins(rg, 0), ins(rg+1, 0);
            if(lg!=0)
            {
                su-=abs(ar[lg-1]);
                ar[lg-1]-=x;
                su+=abs(ar[lg-1]);
            }
            if(rg!=n-1)
            {
                su-=abs(ar[rg]);
                ar[rg]+=x;
                su+=abs(ar[rg]);
            }
            ins(lg-1, 1), ins(lg, 1), ins(rg, 1), ins(rg+1, 1);
        }
    }
}