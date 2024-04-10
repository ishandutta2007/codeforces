#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[400005], b[400005], c[400005], used[400005];

void dfs(int x)
{
    used[x] = 1;

    if(used[c[x]] == 0)
        dfs(c[x]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < n; i++)
            c[a[i]] = b[i];

        for(int i = 1; i <= n; i++)
            used[i] = 0;

        int ans = 1;

        for(int i = 1; i <= n; i++)
            if(used[i] == 0)
            {
                ans = ans * 2 % 1000000007;
                dfs(i);
            }

        cout << ans << "\n";
    }
}