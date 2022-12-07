#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=5e5+10, inf=1e18;
vector <pair <int, int> > sv[sz];
int n, q, h[sz], si[sz];
int dot[sz*4], add[sz*4];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=min(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        if(sv[l].size()==0) dot[nu]=h[l];
        else dot[nu]=inf;
    }
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
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu]+add[nu];
    else if(l>rg or r<lg) return inf;
    else
    {
        push(nu);
        int mid=(l+r)>>1;
        int re=min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
        recalc(nu);
        return re;
    }
}

void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, l=sv[v][a].second;
        h[ne]=h[v]+l, dfs(ne), si[v]+=si[ne];
    }
}
vector <int> sp[sz];
int an[sz], zap[sz][2];
void dfs2(int v)
{
    for(int a=0; a<sp[v].size(); a++)
    {
        int nu=sp[v][a];
        lg=zap[nu][0], rg=zap[nu][1];
        an[nu]=que(1, 0, n-1)+h[v];
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, l=sv[v][a].second;
        lg=ne, rg=ne+si[ne]-1, va=-2*l, cha(1, 0, n-1);
        dfs2(ne);
        lg=ne, rg=ne+si[ne]-1, va=2*l, cha(1, 0, n-1);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int a=1; a<n; a++)
    {
        int pr, w;
        scanf("%lld%lld", &pr, &w);
        pr--, sv[pr].push_back({a, w});
    }
    for(int a=0; a<q; a++)
    {
        int v;
        scanf("%lld%lld%lld", &v, &zap[a][0], &zap[a][1]);
        v--, zap[a][0]--, zap[a][1]--;
        sp[v].push_back(a);
    }
    dfs(0);
    build(1, 0, n-1);
    dfs2(0);
    for(int a=0; a<q; a++) printf("%lld\n", an[a]);
}