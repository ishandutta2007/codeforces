#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <list>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "m"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgashqt
#define free afdshjioeyqtw
#define next qpowityqwopqw

typedef unsigned int unt;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll INF64 = 1e18;
const ld EPS = 1e-16;
const int N = 200100;
const int M = 6;

int n, k;
ll ans, dp[N][M], d[M], sum[N][M];
vector < int > g[N];

void dfs(int v, int p) {
    for (int u : g[v])
        if (u != p) {
            dp[v][1]++;
            sum[v][1]++;
            dfs(u, v);
            for (int i = 1; i <= k; i++) {
                ll q = i + 1, w = 0;
                while (q > k) {
                    q -= k;
                    w++;
                }
                dp[v][q] += dp[u][i];
                sum[v][q] += sum[u][i] + w * dp[u][i];
            }
        }
    for (int i = 1; i <= k; i++)
        ans += sum[v][i] * 2;
    for (int u : g[v])
        if (u != p) {
            dp[v][1]--;
            sum[v][1]--;
            for (int i = 1; i <= k; i++) {
                ll q = i + 1, w = 0;
                while (q > k) {
                    q -= k;
                    w++;
                }
                dp[v][q] -= dp[u][i];
                sum[v][q] -= sum[u][i] + w * dp[u][i];
            }
            for (int i = 1; i <= k; i++)
                for (int j = 0; j <= k; j++)
                    if (dp[v][i] && dp[u][j]) {
                        ll ww = sum[u][j], kk = dp[u][j], q = i + j + 1, w = 0;
                        while (q > k) {
                            w++;
                            q -= k;
                        }
                        ans += dp[v][i] * ww + sum[v][i] * kk + dp[v][i] * kk * (w - 1);
                    }
            dp[v][1]++;
            sum[v][1]++;
            for (int i = 1; i <= k; i++) {
                ll q = i + 1, w = 0;
                while (q > k) {
                    q -= k;
                    w++;
                }
                dp[v][q] += dp[u][i];
                sum[v][q] += sum[u][i] + w * dp[u][i];
            }
        }
    dp[v][0] = 1;
    sum[v][0] = 1;
    /*
    cout << "=========  " << v << endl;
    forn(i, k + 1)
        cout << i << "  ----  " << dp[v][i] << ' ' << sum[v][i] << endl;
    cout << "=-=-=-=-=  " << ans << endl;
     */
}

int main() {
    cin >> n >> k;
    forn(i, n - 1) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 1);
    cout << ans / 2;
    return 0;
}



/*



*/