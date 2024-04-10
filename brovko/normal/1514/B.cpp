#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MOD = 1e9 + 7;

int t, n, k;

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * y % MOD;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    //if(y % 2)
        return mul(x, binpow(x, y - 1));

    int z = mul(x, y / 2);

    return mul(z, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        cout << binpow(n, k) << "\n";
    }
}