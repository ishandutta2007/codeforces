#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, p[300005], b[300005], a[300005], used[300005];

void dfs(int v)
{
    used[v] = 1;

    if(used[a[v]] == 0)
        dfs(a[v]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;

            b[(p[i] - i + n) % n]++;
        }

        vector <int> ans;

        for(int i = 0; i < n; i++)
            if(b[i] * 3 >= n)
            {
                for(int j = 0; j < n; j++)
                    a[j] = p[(j - i + n) % n];

                int k = 0;

                for(int j = 0; j < n; j++)
                    used[j] = 0;

                for(int j = 0; j < n; j++)
                    if(used[j] == 0)
                    {
                        k++;
                        dfs(j);
                    }

                if(k >= n - m)
                    ans.pb((n - i) % n);
            }

        sort(ans.begin(), ans.end());

        cout << ans.size() << ' ';

        for(auto to:ans)
            cout << to << ' ';

        cout << "\n";
    }
}