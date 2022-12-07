//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, m, q, pri[sz], cle, qq;
long long di[sz], inf=1e18;
vector <pair <int, int> > sv[sz];
vector <int> qu[sz];
bool us[sz];
void dfs(int v)
{
    us[v]=1, di[v]+=cle;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first;
        if(us[ne]==0)
        {
            int nu=sv[v][a].second;
            long long x=di[v]+pri[nu]-di[ne];
            if(x==cle) dfs(ne);
            else if(x>=0 and x<=qq) qu[x].push_back(ne);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>q;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d%d", &u, &v, &pri[a]);
        u--, v--;
        sv[u].push_back(make_pair(v, a));
    }
    set <pair <long long, int> > se;
    di[0]=0, se.insert(make_pair(0, 0));
    for(int a=1; a<n; a++) di[a]=inf;
    while(se.size()>0)
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].first, nu=sv[v][a].second;
            if(di[ne]>di[v]+pri[nu])
            {
                se.erase(make_pair(di[ne], ne));
                di[ne]=di[v]+pri[nu];
                se.insert(make_pair(di[ne], ne));
            }
        }
    }
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int v;
            scanf("%d", &v);
            if(di[v-1]!=inf) printf("%lld\n", di[v-1]);
            else printf("-1\n");
        }
        else
        {
            scanf("%d", &qq);
            for(int b=0; b<qq; b++)
            {
                int x;
                scanf("%d", &x);
                pri[x-1]++;
            }
            for(int b=0; b<n; b++) us[b]=0;
            cle=0;
            qu[0].push_back(0);
            for(int b=0; b<sz; b++)
            {
                int q2=qu[b].size();
                if(q2==0) break;
                for(int c=0; c<q2; c++)
                {
                    int v=qu[b][c];
                    if(us[v]==0) dfs(v);
                }
                cle++;
            }
            for(int a=0; a<=qq; a++) qu[a].clear();
        }
    }
}