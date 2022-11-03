#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ll;

const int N=50000;
const int K=501;

ll c[N][K],ans=0;
int n,k;
vector<vector<int> > g;

void dfs(int v,int pr=-1)
{
    for (int i=0; i<=k; i++)c[v][i]=0;
    c[v][0]=1;
    for (int i=0; i<g[v].size(); i++)
    {
        int u=g[v][i];
        if (u!=pr)
        {
            dfs(u,v);
            for (int j=0; j<k; j++)
                ans += c[v][j]*c[u][k-j-1];
            for (int j=1; j<=k; j++)
                c[v][j] += c[u][j-1];
        }
    }
}

int main()
{
    cin >> n >> k;
    g.resize(n);
    for (int i=0; i<n-1; i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        v1--;v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}