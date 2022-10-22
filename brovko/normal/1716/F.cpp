#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int MOD = 998244353;
const int N = 2005;

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

int s[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    s[0][0] = 1;

    for(int i = 1; i < N; i++)
        for(int j = 1; j < N; j++)
            s[i][j] = add(s[i - 1][j - 1], mul(j, s[i - 1][j]));

    int t;
    cin >> t;

    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        int ans = 0, B = 1;

        int mx = min(n, k);

        int pw1[mx + 1], pw2[mx + 1];



        pw1[1] = (m + 1) / 2;
        pw2[mx] = binpow(m, n - mx);

        for(int i = 2; i <= mx; i++)
            pw1[i] = mul(pw1[i - 1], (m + 1) / 2);

        for(int i = mx - 1; i >= 1; i--)
            pw2[i] = mul(pw2[i + 1], m);

        for(int i = 1; i <= mx; i++)
        {
            B = mul(B, n - i + 1);
            ans = add(ans, mul(B, mul(s[k][i], mul(pw1[i], pw2[i]))));
        }

        cout << ans << "\n";
    }
}