#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;

int add(int a, int b)
{
        a += b;
        if (a >= MOD)
        {
                a -= MOD;
        }
        if (a < 0)
        {
                a += MOD;
        }
        return a;
}

int mul(int a, int b)
{
        return a * (long long) b % MOD;
}

int expow(int a, int b)
{
        int r = 1;
        while (b)
        {
                if (b & 1)
                {
                        r = mul(r, a);
                }
                a = mul(a, a);
                b >>= 1;
        }
        return r;
}

int dv(int a, int b)
{
        return mul(a, expow(b, MOD - 2));
}

const int N = 100000 + 7;

int n;
int dp[N];

vector <int> prie;
int Limit, rs;

void pinex(int i, int p, int sg)
{
        if (i == prie.size())
        {
                rs += (Limit / p) * sg;
        }
        else
        {
                pinex(i + 1, p, sg);
                pinex(i + 1, p * prie[i], -sg);
        }
}

int get(int y, int lim) /// cate c exista a.i. (y, c) = 1 cu c <= lim
{
        Limit = lim;
        rs = 0;
        prie.clear();
        for (int i = 2; i * i <= y; i++)
        {
                bool g = 0;
                while (y % i == 0)
                {
                        g = 1;
                        y /= i;
                }
                if (g)
                {
                        prie.push_back(i);
                }
        }
        if (y > 1)
        {
                prie.push_back(y);
        }
        pinex(0, 1, 1);
        return rs;
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n;
        dp[1] = 1;
        for (int x = 2; x <= n; x++)
        {
                vector <int> divi;
                for (int j = 1; j * j <= x; j++)
                {
                        if (x % j == 0)
                        {
                                divi.push_back(j);
                                if (j * j != x)
                                {
                                        divi.push_back(x / j);
                                }
                        }
                }
                sort(divi.begin(), divi.end());
                int s = n, kek;
                for (auto &d : divi)
                {
                        int y = x / d;
                        int lim = n / d;
                        int cnt = get(y, lim);
                        if (d == x)
                        {
                                kek = cnt;
                                continue;
                        }
                        s = add(s, mul(cnt, dp[d]));
                }
                dp[x] = dv(s, n - kek);
        }
        int res = 0;
        for (int x = 1; x <= n; x++)
        {
                res = add(res, dp[x]);
        }
        cout << dv(res, n) << "\n";
}
/**

4 8
2 => 4 * 8 / 2 = 16
4 => 4 * 8 /4 = 8

cate au (x, y) = d
=> (x / d, c) = 1 cu c <= n / d

c * d <= n
=> c <= [n / d]

( dp[x] * n - dp[x] * cnt ) / n = s

dp[x] = n * s / (n - cnt)

(dp[n] * n - dp[n] * cnt) / n  = s

dp[2] / 2 =

dp[2] = 1 + dp[1] / 2 + dp[2] / 2
=> dp[2] / 2 = dp[1] / 3

( 2 * dp[2] - dp[2] ) / n = s


**/