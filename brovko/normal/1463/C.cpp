#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair

using namespace std;

int t, n, a[100005], b[100005];

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
            cin >> a[i] >> b[i];

        int ans = 0, x = -1, y = 0;
        a[n] = 1e18;

        for(int i = 0; i < n; i++)
        {
            if(x == -1 || a[i] >= a[x] + abs(y - b[x]))
            {
                if(x > -1)
                    y = b[x];

                x = i;
            }
            {
                if(y < b[x] && b[i] >= min(b[x], y + a[i] - a[x]) && b[i] <= min(b[x], y + a[i + 1] - a[x]) ||
                    y > b[x] && b[i] <= max(b[x], y - a[i] + a[x]) && b[i] >= max(b[x], y - a[i + 1] + a[x]) || y == b[x])
                        ans++;
            }
        }

        cout << ans << "\n";
    }
}