#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, sz2=1e6+10;
int q[sz2], ar[sz], p, lg, rg;
long long dot[sz*4];
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
long long que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=1; a<sz2; a++)
    {
        for(int b=a; b<sz2; b+=a) q[b]++;
    }
    set <int> av;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(ar[a]!=q[ar[a]]) av.insert(a);
    }
    build(1, 0, n-1);
    for(int a=0; a<m; a++)
    {
        int ty;
        scanf("%d%d%d", &ty, &lg, &rg);
        lg--, rg--;
        if(ty==1)
        {
            vector <set <int>::iterator> ve;
            for(auto it=av.lower_bound(lg); it!=av.end(); it++)
            {
                p=*it;
                if(p>rg) break;
                ar[p]=q[ar[p]];
                cha(1, 0, n-1);
                if(ar[p]==q[ar[p]]) ve.push_back(it);
            }
            for(int b=0; b<ve.size(); b++) av.erase(ve[b]);
        }
        else
        {
            printf("%lld\n", que(1, 0, n-1));
        }
    }
}