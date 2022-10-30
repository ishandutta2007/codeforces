#include <bits/stdc++.h>
using namespace std;
//#define compute
#ifdef compute
#define dbg(x...)                           \
    do                                      \
    {                                       \
        cout << "\033[32;1m" << #x << "->"; \
        err(x);                             \
    } while (0)
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... A>
void err(T<t> a, A... x)
{
    for (auto v : a)
        cout << v << ' ';
    err(x...);
}
template <typename T, typename... A>
void err(T a, A... x)
{
    cout << a << ' ';
    err(x...);
}
#else
#define dbg(...)
#endif
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 55;
const int maxt = 2550;
ll a[maxn][maxt];
ll b[maxn][maxn][maxt];
ll w[maxn][maxn][maxn][4];
ll fac[maxn];
int t[maxn], g[maxn];
int tot;
int cnt[3];
void db()
{
    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
}
int main()
{
    db();
    int n, T;
    cin >> n >> T;
    a[0][0] = 1;
    b[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &t[i], &g[i]);
        g[i]--;
        cnt[g[i]]++;
        if (!g[i])
        {
            for (int c = cnt[0]; c >= 1; c--)
                for (int j = T; j >= t[i]; j--)
                {
                    a[c][j] = (a[c - 1][j - t[i]] + a[c][j]) % mod;
                    dbg(c, j, a[c][j]);
                }
            tot += t[i];
        }
        else
        {
            for (int c1 = cnt[1]; c1 >= (g[i] == 1); c1--)
                for (int c2 = cnt[2]; c2 >= (g[i] == 2); c2--)
                    for (int j = T; j >= t[i]; j--)
                        b[c1][c2][j] = (b[c1 - (g[i] == 1)][c2 - (g[i] == 2)][j - t[i]] + b[c1][c2][j]) % mod;
        }
    }
    w[0][0][0][3] = 1;
    for (int c0 = 0; c0 <= cnt[0]; c0++)
    {
        for (int c1 = 0; c1 <= cnt[1]; c1++)
        {
            for (int c2 = 0; c2 <= cnt[2]; c2++)
            {
                for (int nxt = 0; nxt < 3; nxt++)
                {
                    for (int pre = 0; pre < 4; pre++)
                    {
                        if (nxt == pre)
                            continue;
                        if (nxt == 0 && !c0)
                            continue;
                        if (nxt == 1 && !c1)
                            continue;
                        if (nxt == 2 && !c2)
                            continue;
                        if (pre == 3)
                        {
                            if ((c0 + c1 + c2) != 1)
                                continue;
                        }
                        w[c0][c1][c2][nxt] = (w[c0 - (nxt == 0)][c1 - (nxt == 1)][c2 - (nxt == 2)][pre] + w[c0][c1][c2][nxt]) % mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int t0 = 0; t0 <= tot; t0++)
    {
        for (int c0 = 0; c0 <= cnt[0]; c0++)
        {
            for (int c1 = 0; c1 <= cnt[1]; c1++)
            {
                for (int c2 = 0; c2 <= cnt[2]; c2++)
                {
                    ll tmp = a[c0][t0] * b[c1][c2][T - t0] % mod;
                    tmp = tmp * fac[c0] % mod * fac[c1] % mod * fac[c2] % mod;
                    ll way = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        if (j == 0 && !c0)
                            continue;
                        if (j == 1 && !c1)
                            continue;
                        if (j == 2 && !c2)
                            continue;
                        way = (way + w[c0][c1][c2][j]) % mod;
                    }
                    ans = (ans + way * tmp % mod) % mod;
                    dbg(t0, c0, c1, c2, ans);
                }
            }
        }
    }
    cout << ans << endl;
}