#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int t, n, m;

int mul(int x, int y)
{
    return x * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        int y = 0;

        for(int i = 0; i < m; i++)
        {
            int l, r, x;
            cin >> l >> r >> x;

            y |= x;
        }

        int p = 1;

        for(int i = 0; i < n - 1; i++)
            p = mul(p, 2);

        cout << mul(y, p) << "\n";
    }
}