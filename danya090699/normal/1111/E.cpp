#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sz2=310, mod=1e9+7;
vector <int> sv[sz];
int up[sz][20], h[sz], si[sz], tin[sz], timer=0, lev[sz];
void dfs(int v, int pr)
{
    up[v][0]=pr, tin[v]=timer++, si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            h[ne]=h[v]+1, dfs(ne, v), si[v]+=si[ne];
        }
    }
}
int lca(int u, int v)
{
    if(tin[v]<tin[u]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        int ne=up[v][i];
        if(tin[ne]>tin[u]) v=ne;
    }
    if(tin[v]>tin[u]) v=up[v][0];
    return v;
}
bool comp(int a, int b){return h[a]<h[b];}

int dot[sz*4];
void push(int nu)
{
    if(dot[nu]!=-1)
    {
        dot[nu*2]=dot[nu];
        dot[nu*2+1]=dot[nu];
        dot[nu]=-1;
    }
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu]=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
    }
}
int p;
int que(int nu, int l, int r)
{
    if(l==r) return dot[nu];
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        if(p<=mid) return que(nu*2, l, mid);
        else return que(nu*2+1, mid+1, r);
    }
}
int tr[sz2][sz2], fact[sz2];
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
int main()
{
    fact[0]=1;
    for(int a=1; a<sz2; a++) fact[a]=(1ll*fact[a-1]*a)%mod;

    for(int a=0; a<sz2; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
    }

    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    h[0]=0, dfs(0, 0);
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++) up[a][i]=up[up[a][i-1]][i-1];
    }
    for(int a=0; a<n*4; a++) dot[a]=-1;

    for(int a=0; a<q; a++)
    {
        int k, m, r;
        scanf("%d%d%d", &k, &m, &r);
        r--, m=min(m, k);
        vector <int> sp, sp2;
        for(int b=0; b<k; b++)
        {
            int v;
            scanf("%d", &v);
            v--;
            int lc=lca(v, r);
            if(lc==v) sp.push_back(v);
            else sp2.push_back(v);
        }
        sort(sp.begin(), sp.end(), comp);
        sort(sp2.begin(), sp2.end(), comp);
        int f[m+1];
        for(int b=1; b<=m; b++) f[b]=1;
        for(int b=0; b<sp.size(); b++)
        {
            for(int c=1; c<=m; c++)
            {
                if(b<c) f[c]=(1ll*f[c]*(c-b))%mod;
                else f[c]=0;
            }
        }
        dot[1]=0;
        for(int b=0; b<sp2.size(); b++)
        {
            int v=sp2[b], le;
            p=tin[v];
            int prle=que(1, 0, n-1);
            if(prle) le=prle+1;
            else
            {
                int lc=lca(r, v);
                le=sp.size()-(lower_bound(sp.begin(), sp.end(), lc, comp)-sp.begin())+1;
            }

            lg=tin[v], rg=tin[v]+si[v]-1, va=le, cha(1, 0, n-1);

            for(int c=1; c<=m; c++)
            {
                if(le<=c) f[c]=(1ll*f[c]*(c-le+1))%mod;
                else f[c]=0;
            }
        }
        int an=0;
        for(int b=1; b<=m; b++)
        {
            for(int c=1; c<b; c++)
            {
                f[b]-=(1ll*f[c]*tr[b][c])%mod;
                if(f[b]<0) f[b]+=mod;
            }
            an=(an+1ll*f[b]*po(fact[b], mod-2))%mod;
        }
        printf("%d\n", an);
    }
}