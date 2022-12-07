//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10, inf=1e18;
int n, q, tin[sz], si[sz], pr[sz], di[sz], re[sz*2][3], timer=0, lg, rg, add;
vector <pair <int, int> > sv[sz];
void dfs(int v, int pre, int le)
{
    tin[v]=timer, timer++;
    di[tin[v]]=le+pr[v], si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, nle=sv[v][a].second;
        if(ne!=pre)
        {
            dfs(ne, v, le+nle);
            si[v]+=si[ne];
        }
    }
}
struct el
{
    int mi, add=0;
};
el dot[sz*4];
void push(int nu)
{
    dot[nu*2].add+=dot[nu].add;
    dot[nu*2+1].add+=dot[nu].add;
    dot[nu].add=0;
}
void recalc(int nu)
{
    dot[nu].mi=min(dot[nu*2].mi+dot[nu*2].add, dot[nu*2+1].mi+dot[nu*2+1].add);
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu].mi=di[l];
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
    if(l>=lg and r<=rg) dot[nu].add+=add;
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
    if(l>=lg and r<=rg) return dot[nu].mi+dot[nu].add;
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)/2;
        push(nu);
        int an=min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
        recalc(nu);
        return an;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int a=0; a<n-1; a++)
    {
        for(int b=0; b<3; b++) scanf("%lld", &re[a][b]);
        re[a][0]--, re[a][1]--;
        int u=re[a][0], v=re[a][1];
        sv[u].push_back(make_pair(v, re[a][2]));
        sv[v].push_back(make_pair(u, re[a][2]));
    }
    pr[0]=0;
    for(int a=n-1; a<n*2-2; a++)
    {
        for(int b=0; b<3; b++) scanf("%lld", &re[a][b]);
        re[a][0]--, re[a][1]--;
        pr[re[a][0]]=re[a][2];
    }
    dfs(0, -1, 0);
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%lld", &ty);
        if(ty==1)
        {
            int nu, le;
            scanf("%lld%lld", &nu, &le);
            nu--;
            if(nu<n-1)
            {
                int u=re[nu][0], v=re[nu][1];
                if(tin[u]>tin[v]) swap(u, v);
                lg=tin[v], add=le-re[nu][2];
                rg=lg+si[v]-1;
                cha(1, 0, n-1);
                re[nu][2]=le;
            }
            else
            {
                int u=re[nu][0];
                lg=tin[u], rg=tin[u], add=le-pr[u];
                cha(1, 0, n-1);
                pr[u]=le;
            }
        }
        else
        {
            int u, v;
            scanf("%lld%lld", &u, &v);
            u--, v--;
            int an;
            if(tin[v]>=tin[u] and tin[v]<tin[u]+si[u])
            {
                lg=tin[v], rg=tin[v], an=que(1, 0, n-1)-pr[v];
                lg=tin[u], rg=tin[u], an-=que(1, 0, n-1)-pr[u];
            }
            else
            {
                lg=tin[u], rg=tin[u]+si[u]-1;
                an=que(1, 0, n-1);
                rg=tin[u], an-=que(1, 0, n-1)-pr[u];
                lg=tin[v], rg=tin[v];
                an+=que(1, 0, n-1)-pr[v];
            }
            printf("%lld\n", an);
        }
    }
}