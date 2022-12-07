#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)
#define pi pair<int, int>

const int MAXN = 1010;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, m;
int c[MAXN][MAXN];
vector<vector<int>> ans;
int adj[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {1, -1}, {0, 1}, {1, 0}, {1, 1}};

bool check(int i, int j) {
    map<int, int> z;
    z[c[i][j]]++;
    z[c[i+1][j]]++;
    z[c[i][j+1]]++;
    z[c[i+1][j+1]]++;
    int cnt = 0;
    for(auto i : z) {
        if(i.first == 0) continue;
        cnt++;
    }
    if(cnt > 1) return false;
    return true;
}

void paint(int i, int j) {
    int find = 0;
    forn(a, 0, 2) {
        forn(b, 0, 2) {
            if(c[i+a][j+b] != 0) find = c[i+a][j+b]; 
        }
    }
    c[i][j] = 0;
    c[i+1][j] = 0;
    c[i][j+1] = 0;
    c[i+1][j+1] = 0;
    ans.push_back({i + 1, j + 1, find});
}

void bfs() {
    queue<pi> q;
    forn(i, 0, n - 1) {
        forn(j, 0, m - 1) {
            if(check(i, j)) {
                q.push({i, j});
                paint(i, j);
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        // cout << x << " " << y << endl;
        q.pop();
        for(int k = 0; k < 8; k++) {
            int i = x + adj[k][0];
            int j = y + adj[k][1];
            if(i < 0 || j < 0 || i + 1 >= n || j + 1 >= m) continue;
            if(c[i][j] == 0 && c[i+1][j] == 0 && c[i][j+1] == 0 && c[i+1][j+1] == 0) continue;
            if(check(i, j)) {
                q.push({i, j});
                paint(i, j);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) {
        forn(j, 0, m) {
            cin >> c[i][j];
        }
    }
    bfs();
    int cnt = 0;
    forn(i, 0, n) {
        forn(j, 0, m) {
            if(c[i][j] == 0) cnt++;
        }
    }
    if(cnt != n * m) cout << -1 << endl;
    else {
        cout << (int)ans.size() << endl;
        reverse(ans.begin(), ans.end());
        forn(i, 0, ans.size()) {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
    }
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