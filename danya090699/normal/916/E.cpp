#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, q, r=0;
int tin[sz], tout[sz], si[sz], timer=0;
vector <int> sv[sz];
long long dot[sz*4], add[sz*4], va[sz];
int lg, rg, x;
int up[17][sz];
void dfs(int v, int pre)
{
    tin[v]=timer, timer++;
    up[0][v]=pre;
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pre)
        {
            dfs(ne, v);
            si[v]+=si[ne];
        }
    }
}
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu, int lq, int rq)
{
    dot[nu]=dot[nu*2]+add[nu*2]*lq+dot[nu*2+1]+add[nu*2+1]*rq;
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=va[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu, mid-l+1, r-mid);
    }
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=x;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu, mid-l+1, r-mid);
    }
}
long long que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu]+add[nu]*(r-l+1);
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        long long re=que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
        recalc(nu, mid-l+1, r-mid);
        return re;
    }
}
int lca(int u, int v)
{
    if(tin[u]>tin[v]) swap(u, v);
    for(int a=16; a>=0; a--)
    {
        int ne=up[a][v];
        if(tin[ne]>tin[u]) v=ne;
    }
    if(v!=u) v=up[0][v];
    return v;
}
int find_pr(int v, int u)
{
    for(int a=16; a>=0; a--)
    {
        int ne=up[a][v];
        if(tin[ne]>tin[u]) v=ne;
    }
    return v;
}
long long cou(int v, int r)
{
    long long re;
    if(tin[r]>=tin[v] and tin[r]<tin[v]+si[v])
    {
        re=dot[1]+add[1]*n;
        if(v!=r)
        {
            v=find_pr(r, v);
            lg=tin[v], rg=tin[v]+si[v]-1;
            re-=que(1, 0, n-1);
        }
    }
    else
    {
        lg=tin[v], rg=tin[v]+si[v]-1;
        re=que(1, 0, n-1);
    }
    return re;
}
void ins(int v, int r)
{
    if(tin[r]>=tin[v] and tin[r]<tin[v]+si[v])
    {
        add[1]+=x;
        if(v!=r)
        {
            v=find_pr(r, v);
            lg=tin[v], rg=tin[v]+si[v]-1, x=-x;
            cha(1, 0, n-1);
        }
    }
    else
    {
        lg=tin[v], rg=tin[v]+si[v]-1;
        cha(1, 0, n-1);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    for(int a=1; a<17; a++)
    {
        for(int b=0; b<n; b++) up[a][b]=up[a-1][up[a-1][b]];
    }
    for(int a=0; a<n; a++) va[tin[a]]=ar[a];
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            scanf("%d", &r);
            r--;
        }
        if(ty==2)
        {
            int u, v;
            scanf("%d%d%d", &u, &v, &x);
            u--, v--;
            int v1=lca(u, v), v2=lca(u, r), v3=lca(v, r);
            if(v2==v3) ins(v1, r);
            else
            {
                if(tin[v2]>tin[v3]) ins(v2, r);
                else ins(v3, r);
            }
        }
        if(ty==3)
        {
            int v;
            cin>>v;
            v--;
            printf("%lld\n", cou(v, r));
        }
    }
}