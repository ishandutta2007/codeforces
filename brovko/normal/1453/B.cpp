#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, a[200005];

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

        int ans = 0, Max = 0;

        for(int i = 1; i < n; i++)
        {
            int x = abs(a[i] - a[i - 1]);

            ans += x;

            if(i < n - 1)
                Max = max(Max, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1]));
        }

        Max = max(Max, abs(a[1] - a[0]));
        Max = max(Max, abs(a[n - 1] - a[n - 2]));

        cout << ans - Max << "\n";
    }
}