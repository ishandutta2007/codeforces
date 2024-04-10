#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % MOD;
}

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int dv(int a, int b)
{
    return mul(a, pw(b, MOD - 2));
}

const int N = (int) 2e5 + 7;
int n;
int k;
int a[N];
int b[N];
int f[N];

int comb(int n, int k)
{
    int x = f[n];
    int y = mul(f[k], f[n - k]);
    return dv(x, y);
}

int smart(int cnt)
{
    if (cnt == 0)
    {
        return 0;
    }
    int ans = pw(2, cnt - 1);
    if (cnt % 2 == 0)
    {
        ans = add(ans, -dv(comb(cnt, cnt / 2), 2));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

 //   freopen ("input", "r", stdin);


    f[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = mul(f[i - 1], i);
    }

    cin >> n >> k;
    if (k == 1)
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = (a[(i + 1) % n]);
    }

    int distinct = 0;
    int eq = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            eq++;
        }
        else
        {
            distinct++;
        }
    }
    int ans = 0;
    for (int l = 1; l <= distinct; l++)
    {
        int ways = comb(distinct, l);
        int cnt = smart(l);
        int cur = mul(cnt, ways);
        cur = mul(cur, pw(k - 2, distinct - l));
        ans = add(ans, cur);
    }
    ans = mul(ans, pw(k, eq));
    cout << ans << "\n";


}