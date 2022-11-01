#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
const int mak = 1024 * 512, mak2 = 16;

int n, m, b, c[6000], d[6000];
vector<int> dp[6000][2];
vector<int> e[6000];

void dfs(int nu) {
    dp[nu][0].push_back(0);
    dp[nu][0].push_back(c[nu]);
    dp[nu][1].push_back(b + 1);
    dp[nu][1].push_back(d[nu]);
    int k1, k2;
    for (int v : e[nu]) {
        dfs(v);
        int szk = sz(dp[nu][0]);
        forn (j, sz(dp[v][0]) - 1) {
            dp[nu][0].push_back(b + 1);
            dp[nu][1].push_back(b + 1);
        }
        for (int i = szk - 1; i >= 0; i--) {
            for (int j = sz(dp[v][0]) - 1; j >= 0; j--) {
                k1 = dp[v][0][j] + dp[nu][0][i], k2 = min(dp[v][1][j], dp[v][0][j]) + dp[nu][1][i];
                dp[nu][0][i + j] = min(dp[nu][0][i + j], k1);
                dp[nu][1][i + j] = min(dp[nu][1][i + j], k2);
            }
        }
    }
    /*cout << nu << "\n";
    forn (i, sz(dp[nu][0])) {
        cout << dp[nu][0][i] << " " << dp[nu][1][i] << "\n";
    }*/
}

int main()
{
    iostream::sync_with_stdio(0);
    //cin >> n >> b;
    scanf("%d%d", &n, &b);
    forn (i, n) {
        scanf("%d%d", &c[i], &d[i]);
        d[i] = c[i] - d[i];
        if (i) {
            int k;
            scanf("%d", &k);
            k--;
            e[k].push_back(i);
        }
    }
    dfs(0);
    int ans = 0;
    forn (i, sz(dp[0][0])) {
        if (dp[0][0][i] <= b) ans = i;
    }
    forn (i, sz(dp[0][1])) {
        if (dp[0][1][i] <= b && ans < i) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}