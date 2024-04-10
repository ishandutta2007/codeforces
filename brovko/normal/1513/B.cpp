#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
const int MOD = 1e9 + 7;

int t, n, a[200005], fact[200005];

int mul(int x, int y)
{
    return x * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 200005; i++)
        fact[i] = mul(fact[i - 1], i);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int x = a[0];

        for(int i = 0; i < n; i++)
            x = (x & a[i]);

        int k = 0;

        for(int i = 0; i < n; i++)
            if(a[i] == x)
                k++;

        cout << mul(k, mul(k - 1, fact[n - 2])) << "\n";
    }
}