#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if(k > n + m - 2)
    {
        cout << -1;
        return 0;
    }

    int x = min(k, n - 1);
    int y = max(0ll, k - x);

    int ans = n / (x + 1) * (m / (y + 1));

    y = min(k, m - 1);
    x = max(0ll, k - y);

    ans = max(ans, n / (x + 1) * (m / (y + 1)));



    cout << ans;
}