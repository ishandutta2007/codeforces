#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const long long inf=2147483647ll*10000000ll;
vector<int> row[110000];
int a[110000],b[110000],c[110000],d[110000],h[110000];
int w[110000];
struct node
{
    int b,c,d,h;
};
vector<node> G[110000];
vector<pair<int,long long> > g[110000];
map<int,long long> f[110000];
int n,m,k;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)row[i].clear();
        row[1].pb(1); row[n].pb(m);
        for(int i=1;i<=n;i++)scanf("%d",&w[i]);
        for(int i=1;i<=k;i++)scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&h[i]);
        for(int i=1;i<=k;i++)row[a[i]].pb(b[i]),row[c[i]].pb(d[i]);
        for(int i=1;i<=n;i++)sort(row[i].begin(),row[i].end());
       
        for(int i=1;i<=n;i++)
        {
            f[i].clear();
            for(auto p:row[i])f[i][p]=inf;
        }
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=k;i++)
        {
            node t;
            t.b=b[i]; t.c=c[i]; t.d=d[i]; t.h=h[i];
            G[a[i]].pb(t);
        }
        f[1][1]=0;
        for(int i=1;i<=n;i++)
        {
            if (row[i].size()==0)continue;
            for(auto p:row[i])g[p].clear();
            for(int j=0;j<row[i].size()-1;j++)
            {
                g[row[i][j]].pb(mp(row[i][j+1],1ll*w[i]*abs(row[i][j]-row[i][j+1])));
                g[row[i][j+1]].pb(mp(row[i][j],1ll*w[i]*abs(row[i][j]-row[i][j+1])));
            }
            static priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > Q; 
            static long long dist[110000];
            static int v[110000];
            while (!Q.empty())Q.pop();
            for(auto p:row[i])
                if (f[i][p]!=inf)Q.push(mp(f[i][p],p));
            for(auto p:row[i])dist[p]=f[i][p],v[p]=i;;
            while (!Q.empty())
            {
                auto t=Q.top(); Q.pop();
                if (v[t.second]!=i)continue;
                v[t.second]=-1;
                for(auto p:g[t.second])
                    if (t.first+p.second<dist[p.first])
                    {
                        dist[p.first]=t.first+p.second;
                        Q.push(mp(dist[p.first],p.first));
                    }
            }
            for(auto p:row[i])f[i][p]=dist[p];
            for(auto p:G[i])
                if (f[i][p.b]!=inf)f[p.c][p.d]=min(f[p.c][p.d],f[i][p.b]-p.h);
        }
        if (f[n][m]==inf)puts("NO ESCAPE");
        else printf("%lld\n",f[n][m]);
    }
}