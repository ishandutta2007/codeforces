//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=3e3+10, sz2=4e5+10;
vector <int> sv[sz];
int p[sz2], zap[sz2][3], pr[sz], h[sz];
int up[12][sz];
bool st[sz];
bool comp(int a, int b){return (zap[a][0]<zap[b][0]);}
int dfs(int v, int pre, int ty, int he)
{
    h[v]=he;
    st[v]=1;
    if(ty)
    {
        int fup=he;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(h[ne]==-1) fup=min(fup, dfs(ne, v, 1, he+1));
            else if(st[ne]) fup=min(fup, h[ne]);
        }
        st[v]=0;
        return fup;
    }
    else
    {
        pr[v]=pre;
        int fup=1e9;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(fup>he)
            {
                if(h[ne]==-1) fup=min(fup, dfs(ne, v, 0, he+1));
                else if(st[ne]) fup=min(fup, h[ne]);
            }
            else
            {
                if(h[ne]==-1) fup=min(fup, dfs(ne, v, 1, he+1));
                else if(st[ne]) fup=min(fup, h[ne]);
            }
        }
        fup=min(fup, h[v]);
        st[v]=0;
        return fup;
    }
}
int que(int u, int k)
{
    k--;
    if(pr[u]==u or h[u]<k) return -1;
    else
    {
        k=h[u]-k;
        for(int a=11; a>=0; a--)
        {
            if(k>=(1<<a))
            {
                k-=(1<<a), u=up[a][u];
            }
        }
        return u+1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m>>q;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
    }
    for(int a=0; a<n; a++) sort(sv[a].begin(), sv[a].end());
    for(int a=0; a<q; a++)
    {
        p[a]=a;
        for(int b=0; b<3; b++) scanf("%d", &zap[a][b]);
        zap[a][0]--, zap[a][1]--;
    }
    sort(p, p+q, comp);
    int an[q], yk=0;
    while(yk<q)
    {
        int v=zap[p[yk]][0];
        for(int a=0; a<n; a++)
        {
            pr[a]=a, st[a]=0, h[a]=-1;
        }
        dfs(v, v, 0, 0);
        for(int a=0; a<n; a++) up[0][a]=pr[a];
        for(int a=1; a<12; a++)
        {
            for(int b=0; b<n; b++) up[a][b]=up[a-1][up[a-1][b]];
        }
        while(yk<q)
        {
            if(zap[p[yk]][0]==v)
            {
                int u=zap[p[yk]][1], k=zap[p[yk]][2];
                an[p[yk]]=que(u, k);
                yk++;
            }
            else break;
        }
    }
    for(int a=0; a<q; a++) printf("%d\n", an[a]);
}