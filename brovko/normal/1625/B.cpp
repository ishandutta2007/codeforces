#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[150005];

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

        map <int, int> q;

        int ans = 1e18;

        for(int i = 0; i < n; i++)
        {
            if(q[a[i]] > 0)
                ans = min(ans, i - q[a[i]] + 1);

            q[a[i]] = i + 1;
        }

        if(ans > 1e17)
            cout << "-1\n";
        else cout << n - ans << "\n";
    }
}