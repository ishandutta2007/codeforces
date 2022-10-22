#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, u[3005], V[3005], l[3005], r[3005], used[1005];
vector <int> g[1005];

void dfs(int v, int lf, int rg)
{
//    cout << "dfs " << v << endl;
    used[v] = 1;

    for(auto e:g[v])
    {
        if(l[e] <= lf && r[e] >= rg && used[u[e] + V[e] - v] == 0)
            dfs(u[e] + V[e] - v, lf, rg);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> V[i] >> l[i] >> r[i];

        u[i]--;
        V[i]--;

        g[u[i]].pb(i);
        g[V[i]].pb(i);
    }

    vector <int> rg;

    for(int i = 0; i < m; i++)
        rg.pb(r[i]);

    sort(rg.begin(), rg.end());

//    cout << rg[0] << endl;

    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        int L = -1, R = m;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            for(int j = 0; j < n; j++)
                used[j] = 0;

            dfs(0, l[i], rg[M]);

            if(used[n - 1])
                L = M;
            else R = M;
        }

//        cout << L << endl;

        if(L >= 0)
            ans = max(ans, rg[L] - l[i] + 1);
    }

    if(ans == 0)
        cout << "Nice work, Dima!";
    else cout << ans;
}