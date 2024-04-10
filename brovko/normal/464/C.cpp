#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int q, l[10], m[10];
string s, t[100005];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
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

    cin >> s >> q;

    for(int i = 1; i <= q; i++)
        cin >> t[i];

    t[0] = "0->" + s;

    for(int i = 0; i < 10; i++)
    {
        l[i] = 1;
        m[i] = i;
    }

    for(int i = q; i >= 0; i--)
    {
        int L = 0, M = 0;

        for(int j = 3; j < t[i].size(); j++)
        {
            L = (L + l[t[i][j] - '0']) % (MOD - 1);
            M = add(mul(M, binpow(10, l[t[i][j] - '0'])), m[t[i][j] - '0']);
        }

        int x = t[i][0] - '0';

        l[x] = L;
        m[x] = M;
    }

    cout << m[0];
}