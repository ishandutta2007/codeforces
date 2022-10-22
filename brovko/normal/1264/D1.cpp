#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 998244353;

int fact[2005];

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

    int p = binpow(x, y / 2);

    return mul(p, p);
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int C(int x, int y)
{
    if(y < 0 || y > x)
        return 0;

    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 2005; i++)
        fact[i] = mul(fact[i - 1], i);

    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;

    for(int k = 1; k <= n / 2; k++)
    {
        vector <int> A(n), B(n), psq(n + 1);

        for(int i = 0; i < n; i++)
            psq[i + 1] = psq[i] + (s[i] == '?');

        int c = 0, d = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] != ')')
                A[i] = C(c, k - 1 - d);

            if(s[i] == '?')
                c++;

            if(s[i] == '(')
                d++;
        }

        c = 0, d = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] != '(')
                B[i] = C(c, k - 1 - d);

            if(s[i] == '?')
                c++;

            if(s[i] == ')')
                d++;
        }

//        int ans = 0;
//
//        for(int i = 0; i < n; i++)
//            for(int j = i + 1; j < n; j++)
//                ans = add(ans, mul(A[i], mul(B[j], binpow(2, psq[j] - psq[i + 1]))));

        for(int i = 0; i < n; i++)
            A[i] = mul(A[i], binpow(inv(2), psq[i + 1]));

        for(int j = 0; j < n; j++)
            B[j] = mul(B[j], binpow(2, psq[j]));

        vector <int> psA(n + 1);

        for(int i = 0; i < n; i++)
            psA[i + 1] = add(psA[i], A[i]);

        for(int j = 0; j < n; j++)
            ans = add(ans, mul(B[j], psA[j]));
    }

    cout << ans;
}