#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll MD = 10007;
const double PI = 3.1415926535;
const int MAX_VALUE = (int)1e9;

//**************************************

int n,m;
vvi g;
vll cnt,us,cnt2;
vb norm;

void dfs(int v)
{
     norm[v] = true;
     for (int i=0;i<g[v].size();i++)
     {
         int u = g[v][i];
         if (!norm[u] && us[u]+1==us[v])
            dfs(u);
     }
}

void bfs()
{
     vi q;
     
     q.push_back(0);
     us[0]=0;
     cnt[0]=1;
     
     int ps;
     for (ps=0;q[ps]!=n-1;ps++)
     {
         int u = q[ps];
         for (int i=0;i<g[u].size();i++)
         {
             int v = g[u][i];
             if (us[v]==-1)
             {
                        us[v]=us[u]+1;
                        cnt[v]=cnt[u];
                        q.push_back(v);
             }else
             if (us[v]==us[u]+1)
                                cnt[v] += cnt[u];
         }
     }
}

void bfs2()
{
     vi q,us2;
     
     q.push_back(n-1);
     us2.resize(n,-1);
     cnt2[n-1]=1;
     us2[n-1]=0;
     
     int ps;
     for (ps=0;q[ps]!=0;ps++)
     {
         int u = q[ps];
         for (int i=0;i<g[u].size();i++)
         {
             int v = g[u][i];
             if (us2[v]==-1)
             {
                        us2[v]=us2[u]+1;
                        cnt2[v]=cnt2[u];
                        q.push_back(v);
             }else
             if (us2[v]==us2[u]+1)
                                cnt2[v] += cnt2[u];
         }
     }
}

int main()
{
    cin >> n >> m;
    g.resize(n);
    for (int i=0;i<m;i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        v1--;v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    us.resize(n,-1);
    cnt.resize(n);
    bfs();
    cnt2.resize(n);
    bfs2();
    norm.resize(n,false);
    dfs(n-1);
    cout << setprecision(16);
    ll all_cnt = cnt[n-1];
    double ans = 1.0;
    for (int i=0;i<n;i++)
        if (norm[i] && i!=0 && i!=n-1)
        {
                    ll tec_cnt = 0;
                    for (int j=0;j<g[i].size();j++)
                    {
                        int v = g[i][j];
                        if (norm[v] && us[v]>us[i])
                           tec_cnt += cnt[i]*cnt2[v];
                    }
                    tec_cnt *= 2;
                    ans = max(ans, 1.0*tec_cnt/all_cnt);
        }
    cout << ans;
    return 0;
}

//**************************************