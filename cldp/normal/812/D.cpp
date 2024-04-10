#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int own[MAXN];
vector<int> w[MAXN];
vector<int> X[MAXN];
int s[MAXN], f[MAXN][20], d[MAXN];

void dfs(int a, int depth) {
    s[a] = 1;
    d[a] = depth;
    for (int i = 0; i < X[a].size(); ++i) {
        dfs(X[a][i], depth + 1);
        f[X[a][i]][0] = a;
        s[a] += s[X[a][i]];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        w[b].push_back(a);
    }

    for (int i = 1; i <= M; ++i) {
        if (w[i].size() < 2) continue;
        for (int j = 0; j + 1 < w[i].size(); ++j) {
            X[w[i][j]].push_back(w[i][j + 1]);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (s[i] != 0) continue;
        f[i][0] = i;
        dfs(i, 0);
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= N; ++j) f[j][i] = f[f[j][i - 1]][i - 1];
    }

    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        if (w[b].size() == 0) {
            cout << 0 << endl;
            continue;
        }
        b = w[b].back();
        if (d[a] >= d[b]) {
            cout << 0 << endl;
            continue;
        }
        for (int j = 19; j >= 0; --j) {
            if (d[a] + (1 << j) <= d[b]) b = f[b][j];
        }
        if (a != b) {
            cout << 0 << endl;
        } else {
            cout << s[a] << endl;
        }
    }


    return 0;
}