#include <bits/stdc++.h>
#define int long long

using namespace std;

int q, n, x, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while(q--)
    {
        cin >> n >> x >> t;

        int k = min(n - 1, t / x - 1);

        cout << k * (k + 1) / 2 + (n - k - 1) * (k + 1) << "\n";
    }
}