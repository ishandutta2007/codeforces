#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define sz(a) a.size()
#define re  return
#define fi first
#define se second

typedef std::pair<int, int> pii;
typedef long long ll;
using namespace std;

void my_assert(bool q) {
    if (!q) while(true);
}

ll n, m, k, p11, qq, cc, q, a[1000][1000], use[1000][1000], app[1000][1000], qp;

void dfs(int i, int j) {
    use[i][j] = qq;
    q++;
    if (i - 1 >= 0 && use[i - 1][j] != qq && a[i - 1][j] >= cc)
        dfs(i - 1, j);
    if (i + 1 < n && use[i + 1][j] != qq && a[i + 1][j] >= cc)
        dfs(i + 1, j);
    if (j + 1 < m && use[i][j + 1] != qq && a[i][j + 1] >= cc)
        dfs(i, j + 1);
    if (j && use[i][j - 1] != qq && a[i][j - 1] >= cc)
        dfs(i, j - 1);
}

void dfs1(int i, int j) {
    use[i][j] = qq;
    if (qp == 0) re;
    qp--;
    app[i][j] = cc;
    if (i - 1 >= 0 && use[i - 1][j] != qq && a[i - 1][j] >= cc)
        dfs1(i - 1, j);
    if (i + 1 < n && use[i + 1][j] != qq && a[i + 1][j] >= cc)
        dfs1(i + 1, j);
    if (j + 1 < m && use[i][j + 1] != qq && a[i][j + 1] >= cc)
        dfs1(i, j + 1);
    if (j && use[i][j - 1] != qq && a[i][j - 1] >= cc)
        dfs1(i, j - 1);
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    cin >> n >> m >> k;
    forn (i, n) {
        forn (j, m)
            cin >> a[i][j];
    }
    ll qq1 = n * m;
    for (int i = n * m; i >= 1; i--) {
        if (k % i == 0 && k / i <= 1000000000) {
            cc = k / i;
            qq++;
            p11 = 0;
            for (int j = 0; j < n; j++) {
                if (p11 >= i) break;
                for (int p = 0; p < m; p++) {
                    if (use[j][p] != qq && a[j][p] == cc) {
                        q = 0;
                        dfs(j, p);
                        p11 = max(p11, q);
                        if (p11 >= i) {
                            qq++;
                            qp = i;
                            dfs1(j, p);
                            break;
                        }
                    }
                }
            }
            if (p11 >= i) {
                    cout << "YES\n";
                forn (i, n) {
                    forn (j, m) cout << app[i][j] << " ";
                    cout << "\n";
                }
                re 0;
            }
        }
    }
    cout << "NO";
    return 0;
}