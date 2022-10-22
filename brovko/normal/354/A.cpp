#include <bits/stdc++.h>
//#define int long long
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

    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int S = 0, s = 0;

    for(int i = 0; i < n; i++)
        S += a[i];

    int ans = 1e9;

    for(int i = 0; i <= n; i++)
    {
        if(i > 0)
            s += a[i - 1];

        ans = min(ans, s * l + (S - s) * r + ql * max(0, i - (n - i) - 1) + qr * max(0, n - i - i - 1));
    }

    cout << ans;
}