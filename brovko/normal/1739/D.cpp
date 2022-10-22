#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 2e5 + 5;

int used[N], d[N], p[N];
vector <int> g[N];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            d[to] = d[v] + 1;
            dfs(to);
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            g[i].clear();
            d[i] = p[i] = 0;
        }

        for(int i = 0; i < n - 1; i++)
        {
            cin >> p[i + 1];
            p[i + 1]--;
            g[p[i + 1]].pb(i + 1);
        }

        dfs(0);

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.pb({d[i], i});

        sort(v.rbegin(), v.rend());

        int L = 0, R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            for(int i = 0; i < n; i++)
                used[i] = 0;

            int ans = 0;

            for(auto P:v)
            {
                int x = P.s;

                if(used[x] == 0)
                {
                    int cur = x;

                    for(int i = 0; i < M - 1; i++)
                        cur = p[cur];

                    if(p[cur])
                        ans++;

                    dfs(cur);
                }
            }

            if(ans <= k)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}