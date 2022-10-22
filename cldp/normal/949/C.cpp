#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int u[MAXN];
int f[MAXN], d[MAXN];

vector<int> x[MAXN], y[MAXN];

int NN;
bool z[MAXN];
int list[MAXN];
vector<int> xx[MAXN];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return ;
    f[x] = f[y] = (d[x] > d[y] ? f[x] : f[y]);
    d[x] = d[y] = d[x] + d[y];
}

void back(int a) {
    z[a] = true;
    for (int i = 0; i < y[a].size(); ++i) {
        if (z[y[a][i]]) continue;
        back(y[a][i]);
        Union(a, y[a][i]);
    }
}

void dfs(int a) {
    z[a] = true;
    for (int i = 0; i < x[a].size(); ++i) 
     if (!z[x[a][i]]) dfs(x[a][i]);
    list[NN--] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, H;
    cin >> N >> M >> H;
    for (int i = 1; i <= N; ++i) cin >> u[i];
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if ((u[a] + 1) % H == u[b] % H) {
            x[a].push_back(b);
            y[b].push_back(a);
        }
        if ((u[b] + 1) % H == u[a] % H) {
            x[b].push_back(a);
            y[a].push_back(b);
        }
    }
    memset(z, 0, sizeof(z));
    NN = N;
    for (int i = 1; i <= N; ++i) if (!z[i]) dfs(i);
    memset(z, 0, sizeof(z));
    for (int i = 1; i <= N; ++i) {
        f[i] = i;
        d[i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        if (z[list[i]]) continue;
        back(list[i]);
    }

    for (int i = 1; i <= N; ++i) {
        int a = find(i);
        for (int j = 0; j < x[i].size(); ++j) {
            int b = find(x[i][j]);
            if (a != b) xx[a].push_back(b);
        }
    }

    int ans = N + 1, temp = -1;
    for (int i = 1; i <= N; ++i) {
        int a = find(i);
        if (xx[a].size() == 0) {
            if (d[a] < ans) {
                ans = d[a];
                temp = a;
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= N; ++i) {
        if (find(i) == temp) cout << i << " ";
    }
    cout << endl;

    return 0;
}