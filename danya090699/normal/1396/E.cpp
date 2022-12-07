#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <pair <int, int> > sv[sz], edges[2];
map <int, int> ma;
int n, si[sz], tin[sz], timer=0;
long long maxx=0, minn=0;
void dfs(int v, int pr)
{
    si[v]=1, tin[v]=timer++;
    ma[tin[v]]=v+1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, i=sv[v][a].second;
        if(ne!=pr)
        {
            dfs(ne, v), si[v]+=si[ne];
            int w=min(si[ne], n-si[ne]);
            maxx+=w, minn+=w&1;
            edges[w&1].push_back({w, i});
        }
    }
}
int w[sz];
void dfs2(int v, int pr, int prw)
{
    set <pair <int, int>, greater <pair <int, int> > > se;
    se.insert({1, tin[v]});
    int su=1-prw;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, i=sv[v][a].second;
        if(ne!=pr)
        {
            dfs2(ne, v, w[i]), su+=w[i];
            se.insert({w[i], tin[ne]});
        }
    }
    for(int a=0; a<su; a+=2)
    {
        pair <int, int> x=(*se.begin());
        se.erase(se.begin());
        pair <int, int> y=(*se.begin());
        se.erase(se.begin());

        auto it=ma.lower_bound(x.second);
        int u=(*it).second;
        ma.erase(it);

        it=ma.lower_bound(y.second);
        int v=(*it).second;
        ma.erase(it);

        printf("\n%d %d", u, v);

        x.first--, se.insert(x);
        y.first--, se.insert(y);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    long long k;
    cin>>n>>k;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back({v, a});
        sv[v].push_back({u, a});
    }
    dfs(0, 0);
    if(k>=minn and k<=maxx and (k&1)==(minn&1))
    {
        k-=minn;
        for(int i=0; i<2; i++) sort(edges[i].begin(), edges[i].end());
        int yk[2]={0, 0};
        for(int a=2; ; a++)
        {
            int i=a&1;
            while(yk[i]<edges[i].size() and edges[i][yk[i]].first<a) yk[i]++;

            if(k<=(edges[i].size()-yk[i])*2)
            {
                for(int b=yk[i]; b<edges[i].size(); b++)
                {
                    if(k) edges[i][b].first=a, k-=2;
                    else edges[i][b].first=a-2;
                }
                for(int b=yk[i^1]; b<edges[i^1].size(); b++)
                {
                    edges[i^1][b].first=a-1;
                }

                for(int i=0; i<2; i++)
                {
                    for(int b=0; b<edges[i].size(); b++)
                    {
                        w[edges[i][b].second]=edges[i][b].first;
                    }
                }
                break;
            }
            else k-=(edges[i].size()-yk[i])*2;
        }
        cout<<"YES";
        dfs2(0, 0, 0);
    }
    else cout<<"NO";
}