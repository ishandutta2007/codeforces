#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, d[100005], h[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
        cin >> d[i] >> h[i];

    int ans = max(h[0] + d[0] - 1, h[m - 1] + (n - d[m - 1]));

    for(int i = 1; i < m; i++)
    {
        if(abs(h[i] - h[i - 1]) > d[i] - d[i - 1])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }

        ans = max(ans, max(h[i], h[i - 1]) + (d[i] - d[i - 1] - abs(h[i] - h[i - 1])) / 2);
    }

    cout << ans;
}