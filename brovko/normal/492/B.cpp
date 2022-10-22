#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, l, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    ld ans = max(a[0], l - a[n - 1]);

    for(int i = 1; i < n; i++)
        ans = max(ans, (ld)(a[i] - a[i - 1]) / 2);

    cout << setprecision(20) << ans;
}