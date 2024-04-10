#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 300005

int t[MAXN],p[MAXN],c,d[MAXN],k;
bool mk[MAXN];
vector<int> g[MAXN];

void dfs(int u)
{
    mk[u]=1;
    if(!t[u])
        d[u]=0;
    else
        d[u]=MAXN;
    for(auto y : g[u])
        if(!mk[y])
        {
            dfs(y);
            if(!t[u])
                d[u]+=d[y];
            else
                d[u]=min(d[u],d[y]);
        }
    if(g[u].size()==1 && u)
        d[u]=1,k++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> t[i];
    for(int i=0;i<n-1;i++)
    {
        cin >> p[i+1];
        p[i+1]--;
        g[i+1].push_back(p[i+1]);
        g[p[i+1]].push_back(i+1);
    }

    dfs(0);

    db(k-d[0]+1)

    return 0;
}