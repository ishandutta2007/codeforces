#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int vis[10][10];

void solve(int n) {
    memset(vis, 0, sizeof(vis)); 
    int x = 1, y = 1;  
    vector<pii> ans;
    int k = n;
    while (1) {
        ans.pb({x, y});
        vis[x][y] = 1;
        if (k == 2 && x != 8) {
            ans.pb({8, y});
            ans.pb({8, 8});
            break;
        }
        if (k == 3 && x != 8 && y != 8) {
            ans.pb({8, y});
            ans.pb({8, (y == 1 ? 2 : 1)});
            ans.pb({8, 8});
            break;
        }
        if (k == 1) {
            ans.pb({8, 8});
            break;
        }
        int g = 8 - x;
        if (y == g)
            x++;
        else  {
            bool ok = 0;
            for (int i = 1; i <= 8; i++)
                if (i != g && !vis[x][i]) {
                    ok = 1;
                    y = i;
                    break;
                }
            if (!ok)
                y = g;
        }
        k--;
    }
    assert(SZ(ans) == n + 1);
    for (int i = 0; i < n; i++)
        assert(ans[i].X == ans[i + 1].X || ans[i].Y == ans[i + 1].Y);
    memset(vis, 0, sizeof(vis));
    for (auto [a, b] : ans) {
        // cerr << a << " " << b << endl;
        assert(!vis[a][b]);
        vis[a][b] = 1;
    }
    for (int i = 0; i <= n; i++) {
        cout << (char)(ans[i].Y - 1 + 'a') << ans[i].X;
        if (i != n)
            cout << " ";
        else
            cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    // for (int i = 2; i <= 63; i++)
    //     solve(i);
}