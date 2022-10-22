#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD=998244353;

int t, n, m, x, y, ans, used[300005], k[3], c[300005];
vector <int> g[300005];

int add(int x, int y)
{
    return (x+y)%MOD;
}

int mul(int x, int y)
{
    return x*y%MOD;
}

int binpow(int x, int y)
{
    if(y==0)
        return 1;
    if(y%2)
        return mul(x, binpow(x, y-1));
    int z=binpow(x, y/2);
    return mul(z, z);
}

void dfs(int v)
{
    used[v]=1;
    for(auto to:g[v])
    {
        if(used[to]==1 && c[to]==c[v])
            {
                ans=0;
            }
        if(used[to]==0)
        {
            k[3-c[v]]++;
            c[to]=3-c[v];
            dfs(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);


    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);

        }
        ans=1;

        for(int i=0;i<n;i++)
            if(used[i]==0)
        {
            k[1]=1;
            k[2]=0;
            c[i]=1;
            dfs(i);
            ans=mul(ans, add(binpow(2, k[1]), binpow(2, k[2])));
        }

        cout << ans << "\n";

        for(int i=0;i<n;i++)
        {
            g[i].erase(g[i].begin(), g[i].end());
            used[i]=0;
        }
    }
}