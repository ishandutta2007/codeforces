#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;

vector <int> sv[sz], an;
int n, q, pr[sz], ar[sz], ar2[sz], zap[sz][2];

int si[sz], tin[sz], dot[sz*4][2], add[sz*4], timer=0, lg, rg;
void dfs(int v)
{
    tin[v]=timer, timer++;
    ar2[tin[v]]=ar[v];
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), si[v]+=si[ne];
    }
}
void push(int nu)
{
    add[nu*2]^=add[nu];
    add[nu*2+1]^=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    int v1l=dot[nu*2][0], v2l=dot[nu*2][1], v1r=dot[nu*2+1][0], v2r=dot[nu*2+1][1];
    if(add[nu*2]) swap(v1l, v2l);
    if(add[nu*2+1]) swap(v1r, v2r);
    dot[nu][0]=v1l+v1r, dot[nu][1]=v2l+v2r;
}
void build(int nu, int l, int r)
{
    add[nu]=0;
    if(l==r)
    {
        dot[nu][0]=ar2[l], dot[nu][1]=1-ar2[l];
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]^=1;
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
    if(l>=lg and r<=rg) return dot[nu][add[nu]];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        int cu=que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
        recalc(nu);
        return cu;
    }
}
void solve()
{
    an.clear();
    for(int a=1; a<n; a++) sv[pr[a]-1].push_back(a);
    dfs(0);
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ty=zap[a][0], u=zap[a][1]-1;
        lg=tin[u], rg=lg+si[u]-1;
        if(ty==1) cha(1, 0, n-1);
        else an.push_back(que(1, 0, n-1));
    }
    for(int a=0; a<n; a++) sv[a].clear();
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=1; a<n; a++) scanf("%d", &pr[a]);
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        string ty;
        cin>>ty;
        if(ty=="get") zap[a][0]=0;
        else zap[a][0]=1;
        scanf("%d", &zap[a][1]);
    }
    solve();
    for(int a=0; a<an.size(); a++) printf("%d\n", an[a]);
}