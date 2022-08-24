#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;
int dp[101][101][2];
int sz[101];
vector<int> g[101];

pair<pair<int, int>, int> pr[101][101][2];

void dfs(int v, int p = -1) {
    sz[v] = 1;
    dp[v][0][0] = dp[v][0][0] = 0;
    dp[v][1][0] = dp[v][1][1] = 1;
    pr[v][1][0] = pr[v][1][1] = mp(mp(-1, -1), -1);
    for (int to : g[v]) if (to != p) {
        dfs(to, v);

        for (int sz1 = sz[v]; sz1 >= 1; --sz1) {
            for (int sz2 = 1; sz2 <= sz[to]; ++sz2) {
                
                if (dp[v][sz1][0] + dp[to][sz2][0] + 1 < dp[v][sz1 + sz2][0]) {
                    dp[v][sz1 + sz2][0] = dp[v][sz1][0] + dp[to][sz2][0] + 1;

                    pr[v][sz1 + sz2][0] = mp(mp(sz1, 0), to);
                }

                if (dp[v][sz1 + sz2][1] > dp[v][sz1][0] + dp[to][sz2][1]) {
                    dp[v][sz1 + sz2][1] = dp[v][sz1][0] + dp[to][sz2][1];
                    pr[v][sz1 + sz2][1] = mp(mp(sz1, 0), to);
                }

                if (dp[v][sz1 + sz2][1] > dp[v][sz1][1] + dp[to][sz2][0] + 1) {
                    dp[v][sz1 + sz2][1] = dp[v][sz1][1] + dp[to][sz2][0] + 1;
                    pr[v][sz1 + sz2][1] = mp(mp(sz1, 1), to);
                }
            }
        }

        sz[v] += sz[to];
    }
}

vector<int> restore(int v, int k, int c) {
   // cout << "AAAA" <<  v << ' ' << k << ' ' << c << ' ' << dp[v][k][c] << endl;

    vector<vector<int>> anses;
    vector<vector<int>> kek;
    vector<int> ans;

    while (1) {
        auto now = pr[v][k][c];
        if (now.y == -1) {
            break;
        }
      //  cout << v << ' ' << k << ' ' << c << "====" << now.x.x << ' ' << now.x.y << ' ' << now.y << endl;
        int cc = 0;
        if (c == 1) {
            if (now.x.y == 0) cc = 1;
        }
    //    cout << "SUKA" << cc << endl;
        if (cc == 0)
        anses.emplace_back(restore(now.y, k - now.x.x, cc));
        else 
        kek.emplace_back(restore(now.y, k - now.x.x, cc));
        k = now.x.x;
        c = now.x.y;
    }

//    cout << "UUU" << anses.size() << ' ' << kek.size() << endl;


    ans.pb(v);
    for (auto& c : anses) {
        for (int x : c) ans.pb(x);
        ans.pb(v);
    }

    for (auto& c : kek) {
    //    cout <<" ASDASD" << c.size() << endl;
        for (int x : c) ans.pb(x);
    }

    return ans;
}

int main(){
#ifdef LOCAL
  	freopen("G_input.txt", "r", stdin);
  	//freopen("G_output.txt", "w", stdout);
#endif
  	ios_base::sync_with_stdio(0);
  	cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> k;
        for (int i = 0; i < 101; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            int x; cin >> x; --x;
            g[i].pb(x);
            g[x].pb(i);
        }

        for (int i = 0; i < 101; ++i) for (int j = 0; j < 101; ++j) dp[i][j][0] = dp[i][j][1] = 1e9;

        dfs(0);
    
        vector<int> ans;
        if (dp[0][k][0] < dp[0][k][1]) {
            ans = restore(0, k, 0);
        } else {
            ans = restore(0, k, 1);
        }
        cout << ans.size() - 1 << "\n";
        for (int x : ans) cout << x + 1 << ' ';
        cout << "\n";

      //  cout << min(dp[0][k][0], dp[0][k][1]) << "\n";
    }
}