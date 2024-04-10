#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10, inf=1e18;
int dot[sz*4], add[sz*4], w[sz];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=max(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=w[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
vector <int> we[sz];
vector <pair <int, int> > mo[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, p;
    cin>>n>>m>>p;
    for(int a=0; a<n; a++)
    {
        int p, w;
        scanf("%lld%lld", &p, &w);
        we[p].push_back(w);
    }
    for(int a=0; a<sz; a++) w[a]=-inf;
    for(int a=0; a<m; a++)
    {
        int p, w2;
        scanf("%lld%lld", &p, &w2);
        w[p]=max(w[p], -w2);
    }
    build(1, 0, sz-1);
    for(int a=0; a<p; a++)
    {
        int x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        mo[x].push_back({y, z});
    }
    int an=-inf;
    for(int a=1; a<sz; a++)
    {
        for(int b=0; b<mo[a-1].size(); b++)
        {
            lg=mo[a-1][b].first+1, rg=sz-1, va=mo[a-1][b].second;
            cha(1, 0, sz-1);
        }
        for(int b=0; b<we[a].size(); b++)
        {
            an=max(an, dot[1]+add[1]-we[a][b]);
        }
    }
    cout<<an;
}