#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int N = 306;

int a[N][N], b[N][N], k[N][N];

struct DSU {
    int par[N*N];
    vector<pii> record;
    bool is_record=0;
    void setup(int sz) {
        memset(par, -1, sizeof(par[0])*(sz+5));
    }

    int FIND(int u) {
        if (par[u] == -1) return u;
        int nxt = FIND(par[u]);
        if (is_record && nxt != par[u]) {
            record.emplace_back(u, par[u]);
        }
        return par[u] = nxt;
    }

    int UNION(int u, int v) {
        if (FIND(u) == FIND(v)) return 0;
        //cerr << " UNION " << u << " " << v << endl;
        if (is_record) {
            record.emplace_back(FIND(u), par[FIND(u)]);
        }
        par[FIND(u)] = FIND(v);
        return 1;
    }

    void revert() {
        for (int i=record.size()-1; i>=0; --i) {
            pii p = record[i];
            par[p.first] = p.second;
        }
        record.clear();
    }
};

int n, m;

DSU dsu;
DSU side;

int difx[] = {0, 1, 0, -1};
int dify[] = {1, 0, -1, 0};

vector<int> extra, conn;

void solve(vector<pii> qu, int c) {
    int z = qu.size();
    for (auto it=qu.rbegin(); it!=qu.rend(); ++it) {
        auto &p = *it;
        b[p.first][p.second] = z--;
    }
    dsu.setup(n*m);
    side.setup(n*m);

    int merges = 0;

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            for (int v=0; v<2; ++v) {
                int nx = i+difx[v];
                int ny = j+dify[v];
                if (nx<n && ny<m && a[i][j] == a[nx][ny] && !b[i][j] && !b[nx][ny]) {
                    merges += dsu.UNION(i*m+j, nx*m+ny);
                }
            }
        }
    }

    //cerr << "^^"<<endl;

    extra.clear();
    int ex = 0;
    for (int i=qu.size()-1; i>=0; --i) {
        auto p = qu[i];
        int x = p.first, y = p.second;
        extra.push_back(ex);
        if (b[x][y] != i+1) {
            continue;
        }
        for (int v=0; v<4; ++v) {
            int nx = x+difx[v];
            int ny = y+dify[v];
            if (nx>=0 && nx<n && ny>=0 && ny<m && a[x][y] == a[nx][ny] && (b[nx][ny] > i+1 || b[nx][ny] == 0)) {
                ex += dsu.UNION(x*m+y, nx*m+ny);
            }
        }
    }

    conn.clear();

    int ey = 0;
    for (int i=0; i<qu.size(); ++i) {
        int x = qu[i].first, y = qu[i].second;
        //cerr << " :: " << ey << endl;
        if (!k[x][y]) {
            k[x][y] = 1;
            for (int v=0; v<4; ++v) {
                int nx = x + difx[v];
                int ny = y + dify[v];
                if (nx>=0 && nx<n && ny>=0 && ny<m && k[x][y] == k[nx][ny]) {
                    ey += side.UNION(x*m+y, nx*m+ny);
                }
            }
        }
        conn.push_back(ey);
    }
    
    reverse(extra.begin(), extra.end());
    for (int i=0; i<extra.size(); ++i) {
        cout << n*m-merges-extra[i]-conn[i] << "\n";
        //cerr << "  " << n*m << " - " << merges << " - " << extra[i] << " - " << conn[i] << endl;
    }

    for (auto& p : qu) {
        b[p.first][p.second] = 0;
        k[p.first][p.second] = 0;
        a[p.first][p.second] = c;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> n >> m >> q;
    int lc = -1;
    vector<pii> cur;
    for (int i=1; i<=q; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x; --y;
        if (c != lc) {
            solve(cur, lc);
            cur.clear();
            lc = c;
        }
        cur.emplace_back(x, y);

    }
    solve(cur, lc);

    return 0;
}