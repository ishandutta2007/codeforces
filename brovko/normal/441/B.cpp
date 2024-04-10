#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, v, a[3005], b[3005], k[3005], c[3005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> v;

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    for(int i = 0; i < n; i++)
        k[a[i]] += b[i];

    int ans = 0;

    for(int i = 0; i < 3002; i++)
    {
        int x = min(k[i] + c[i], v);

        ans += x;
        c[i + 1] = max(0ll, min(k[i] + c[i] - x, k[i]));
    }

    cout << ans;
}