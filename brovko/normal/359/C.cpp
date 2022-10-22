#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int n, x, a[100005];
map <int, int> m;

int mul(int x, int y)
{
    return x * y % MOD;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int z = binpow(x, y / 2);

    return mul(z, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    for(int i = 0; i < n; i++)
    {
        int j = s - a[i];
        m[j]++;

        while(m[j] == x)
        {
            m[j] = 0;
            m[j + 1]++;
            j++;
        }
    }

    int j = 0;

    for(auto x:m)
        if(x.y > 0)
        {
            j = x.x;
            break;
        }

    int ans = binpow(x, min(j, s));

    ans = ans * (j < s ? __gcd(m[j], x) : 1) % MOD;

    cout << ans;
}