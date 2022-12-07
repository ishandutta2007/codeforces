#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 1005;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

#define pi pair<int, int>

vector<vector<pi>> parent(MAXN, vector<pi>(MAXN));
vector<vector<int>> sz(MAXN, vector<int>(MAXN, 1));
int n, m, arr[MAXN][MAXN];

pi find(pi x) {
    if(x.first==parent[x.first][x.second].first && x.second==parent[x.first][x.second].second) return x;
    return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void unite(pi a, pi b) {
    pi c = find(a);
    pi d = find(b);
    if(d.first != c.first || d.second != c.second) {
        if(sz[d.first][d.second] > sz[d.first][d.second]) swap(d, c); 
        parent[d.first][d.second] = c;
        sz[c.first][c.second] += sz[d.first][d.second];
    }
}

vector<vector<int>> b(16);

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {
    cin >> n >> m;
    forn(i, 0, n) {
        forn(j, 0, m) {
            cin >> arr[i][j];
            parent[i][j] = {i, j};
        }
    }
    forn(i, 0, 16) {
        int x = i;
        forn(j, 0, 4) {
            b[i].push_back(x % 2);
            x /= 2;
        }
        reverse(b[i].begin(), b[i].end());
    }
    forn(i, 0, n) {
        forn(j, 0, m) {
            forn(k, 0, 4) {
                if(b[arr[i][j]][k] == 0) {
                    unite({i, j}, {i + dir[k][0], j + dir[k][1]});
                }
            }
        }
    }
    vector<vector<int>> r(n, vector<int>(m, 0));
    forn(i, 0, n) {
        forn(j, 0, m) {
            pi x = find({i, j});
            r[x.first][x.second]++;
        }
    }
    vector <int> ans;
    forn(i, 0, n) forn(j, 0, m) if(r[i][j] > 0) ans.push_back(r[i][j]);
    sort(ans.begin(), ans.end(), greater<int>());
    for(auto i : ans) cout << i << " ";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}