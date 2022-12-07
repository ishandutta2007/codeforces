#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int n, m;
int pr[sz], tin[sz], tout[sz], si[sz], timer=0, timer2=0;
int up[sz][18], pr2[sz], up2[sz][18], an[sz];
int dot[sz*4], p, lg, rg;
int za[sz][2];
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]++;
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
vector <int> sv[sz], sp[sz];
vector <pair <int, int> > sp2[sz];
bool is_pr(int v, int u){return (tin[v]>=tin[u] and tout[v]<=tout[u]);}
int lca(int u, int v)
{
    if(tin[u]>tin[v]) swap(u, v);
    for(int i=17; i>=0; i--)
    {
        int ne=up[v][i];
        if(!is_pr(u, ne)) v=ne;
    }
    return pr[v];
}
pair <int, int> go(int u, int v)
{
    int s=0;
    for(int i=17; i>=0; i--)
    {
        int ne=up2[v][i];
        if(!is_pr(u, ne))
        {
            v=ne, s+=(1<<i);
        }
    }
    return make_pair(v, s);
}
void dfs(int v)
{
    si[v]=1;
    tin[v]=timer, timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        dfs(sv[v][a]), si[v]+=si[sv[v][a]];
    }
    tout[v]=timer2, timer2++;
}
void dfs2(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs2(ne);
        if(tin[pr2[ne]]<tin[pr2[v]]) pr2[v]=pr2[ne];
    }
}
void dfs3(int v)
{
    for(int a=0; a<sp2[v].size(); a++)
    {
        int nu=sp2[v][a].first;
        int v2=za[nu][1];
        lg=tin[v2], rg=tin[v2]+si[v2]-1;
        sp2[v][a].second=que(1, 0, n-1);
    }
    for(int a=0; a<sp[v].size(); a++)
    {
        int v2=sp[v][a];
        p=tin[v2], cha(1, 0, n-1);
    }
    for(int a=0; a<sv[v].size(); a++) dfs3(sv[v][a]);
    for(int a=0; a<sp2[v].size(); a++)
    {
        int nu=sp2[v][a].first;
        int v2=za[nu][1];
        lg=tin[v2], rg=tin[v2]+si[v2]-1;
        int re=que(1, 0, n-1);
        if(re>sp2[v][a].second) an[nu]--;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    pr[0]=0, up[0][0]=0;
    for(int a=1; a<n; a++)
    {
        scanf("%d", &pr[a]);
        pr[a]--;
        sv[pr[a]].push_back(a);
        up[a][0]=pr[a];
    }
    dfs(0);
    for(int i=1; i<18; i++)
    {
        for(int a=0; a<n; a++) up[a][i]=up[up[a][i-1]][i-1];
    }
    cin>>m;
    for(int a=0; a<n; a++) pr2[a]=a;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        if(tin[u]>tin[v]) swap(u, v);
        sp[u].push_back(v);
        int u2=lca(u, v);
        if(tin[pr2[u]]>tin[u2]) pr2[u]=u2;
        if(tin[pr2[v]]>tin[u2]) pr2[v]=u2;
    }
    dfs2(0);
    for(int a=0; a<n; a++) up2[a][0]=pr2[a];
    for(int i=1; i<18; i++)
    {
        for(int a=0; a<n; a++) up2[a][i]=up2[up2[a][i-1]][i-1];
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        if(tin[u]>tin[v]) swap(u, v);
        if(is_pr(v, u))
        {
            pair <int, int> re=go(u, v);
            if(pr2[re.first]==re.first) an[a]=-1;
            else an[a]=re.second+1;
        }
        else
        {
            int u2=lca(u, v);
            pair <int, int> re=go(u2, u), re2=go(u2, v);
            if(pr2[re.first]==re.first or pr2[re2.first]==re2.first) an[a]=-1;
            else
            {
                an[a]=re.second+re2.second+2;
                za[a][0]=re.first, za[a][1]=re2.first;
                sp2[za[a][0]].push_back(make_pair(a, -1));
            }
        }
    }
    dfs3(0);
    for(int a=0; a<q; a++) printf("%d\n", an[a]);
}