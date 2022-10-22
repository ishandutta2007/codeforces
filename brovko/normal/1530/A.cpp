#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int ans = 0;

        while(n > 0)
        {
            ans = max(ans, n % 10);
            n /= 10;
        }

        cout << ans << "\n";
    }
}