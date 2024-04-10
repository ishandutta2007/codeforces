#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], p[100005], d[100005], used[200005], k[20000005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
            {
                dfs(to);
                d[v] = d[to] + 1;
            }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        cin >> p[i];
        p[i]--;

        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }

    dfs(0);
    int x = 0;

    /*for(int i = 0; i < n; i++)
        cout << d[i] << ' ';
    cout << "\n";*/

    for(int i = 0; i < n; i++)
    {
        if(d[i] % 2 == 0)
            x ^= a[i];
        else k[a[i]]++;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(d[i] % 2 == 0)
            ans += k[x ^ a[i]];
    }

    int k1 = 0, k2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(d[i] % 2 == 0)
            k1++;
        else k2++;
    }

    if(x == 0)
        ans += k1 * (k1 - 1) / 2 + k2 * (k2 - 1) / 2;

    cout << ans;
}