#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;

struct EDGE {
    int v, w, c, ID;
    EDGE() {}
    EDGE(int _v, int _w, int _c, int _ID): v(_v), w(_w), c(_c), ID(_ID) {}
};

int V[MAXN], W[MAXN], D[MAXN], f[MAXN][20], ff[MAXN][20], E[MAXN][20];
vector<EDGE> X[MAXN];
bool Z[MAXN];

int MST(int N) {
    int dis[N + 1];
    bool Z[N + 1];
    set<pair<int, int> > S;
    for (int i = 2; i <= N; ++i) {
        dis[i] = INF;
        S.insert(make_pair(INF, i));
    }
    dis[1] = 0;
    f[1][0] = -1;
    D[1] = 0;
    memset(Z, 0, sizeof(Z));
    S.insert(make_pair(0, 1));

    for (int i = 1; i <= N; ++i) {
        int a = S.begin()->second;
        S.erase(S.begin());
        Z[a] = true;
        for (int j = 0; j < X[a].size(); ++j) {
            int b = X[a][j].v, c = X[a][j].w;
            if (Z[b]) continue;
            if (c < dis[b]) {
                S.erase(make_pair(dis[b], b));
                dis[b] = c;
                S.insert(make_pair(dis[b], b));
                f[b][0] = a;
                ff[b][0] = c;
                E[b][0] = X[a][j].ID;
                D[b] = D[a] + 1;
                W[b] = X[a][j].c;
            }
        }
    }

    return 0;
}

int Build(int N) {
    for (int t = 1; t < 20; ++t) {
        for (int i = 1; i <= N; ++i) {
            if (f[i][t - 1] == -1) continue;
            int b = f[i][t - 1];
            f[i][t] = f[b][t - 1];
            if (ff[i][t - 1] > ff[b][t - 1]) {
                ff[i][t] = ff[i][t - 1];
                E[i][t] = E[i][t - 1];
            } else {
                ff[i][t] = ff[b][t - 1];
                E[i][t] = E[b][t - 1];
            }
        }
    }
    return 0;
}

int LCA(int a, int b, int &c) {
    if (D[a] > D[b]) return LCA(b, a, c);

    int DA = D[a], DB = D[b], res = -1;
    for (int i = 19; i >= 0; --i) {
        if (DB - DA >= (1 << i)) {
            if (ff[b][i] > res) {
                res = ff[b][i];
                c = E[b][i];
            }
            DB -= (1 << i);
            b = f[b][i];
        }
    }
    if (a == b) return res;

    for (int i = 19; i >= 0; --i) {
        if (f[a][i] == f[b][i]) continue;
        if (ff[a][i] > res) {
            res = ff[a][i];
            c = E[a][i];
        }
        if (ff[b][i] > res) {
            res = ff[b][i];
            c = E[b][i];
        }
        a = f[a][i];
        b = f[b][i];
    }
    if (ff[a][0] > res) {
        res = ff[a][0];
        c = E[a][0];
    }
    if (ff[b][0] > res) {
        res = ff[b][0];
        c = E[b][0];
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) cin >> V[i];
    for (int i = 1; i <= M; ++i) cin >> W[i];
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(EDGE(b, V[i], W[i], i));
        X[b].push_back(EDGE(a, V[i], W[i], i));
    }

    MST(N);
    Build(N);

    int K, cnt = 2;
    cin >> K;
    long long ans = 0;
    for (int i = 2; i <= N; ++i) {
        ans += ff[i][0];
        if (W[i] < W[cnt]) cnt = i;
    }

    long long tree = ans;
    ans -= K / W[cnt];

    int rmv = -1, add = -1, val = -1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < X[i].size(); ++j) {
            int temp;
            int dist = LCA(i, X[i][j].v, temp);
            if (tree - dist + X[i][j].w - K / X[i][j].c < ans) {
                ans = tree - dist + X[i][j].w - K / X[i][j].c;
                rmv = temp;
                add = X[i][j].ID;
                val = X[i][j].c;
            }
        }
    }
    
    cout << ans << endl;

    if (rmv == -1) {
        for (int i = 2; i <= N; ++i) {
            cout << E[i][0] << " ";
            if (cnt == i) cout << ff[i][0] - K / W[cnt] << endl; else cout << ff[i][0] << endl;
        }
    } else {
        for (int i = 2; i <= N; ++i) {
            if (E[i][0] == rmv) continue;
            cout << E[i][0] << " " << ff[i][0] << endl;
        }
        cout << add << " " << V[add] - K / val << endl;
    }

    return 0;
}