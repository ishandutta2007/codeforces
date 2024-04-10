#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool y[4010][4010];
bool z[MAXN];
vector<int> x[MAXN];
int d[MAXN], f[MAXN];

int N, M, cnt;

void dfs(int a) {
    z[a] = true;
    ++cnt;
    for (int i = 1; i <= N; ++i) {
        if (y[a][i] && !z[i]) dfs(i);
    }
}


int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (d[x] > d[y]) f[y] = f[x]; else f[x] = f[y];
    d[x] += d[y];
    d[y] = d[x];
    return 0;
}

void dfsbig(int a) {
    z[a] = true;
    set<int> S;
    for (int i = 0; i < x[a].size(); ++i) S.insert(x[a][i]);
    for (int i = 1; i <= N; ++i) {
        if (S.find(i) != S.end()) continue;
        Union(a, i);
        if (!z[i]) dfsbig(i);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    
    if (N <= 4000) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) y[i][j] = true;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < x[i].size(); ++j) {
                int a = i;
                int b = x[i][j];
                y[a][b] = y[b][a] = false;
            }
        }
        int ans = 0;
        vector<int> ansT;
        for (int i = 1; i <= N; ++i) {
            if (!z[i]) {
                cnt = 0;
                dfs(i);
                ansT.push_back(cnt);
                ++ans;
            }
        }
        cout << ans << endl;
        sort(ansT.begin(), ansT.end());
        for (int i = 0; i < ansT.size(); ++i) cout << ansT[i] << " ";
        cout << endl;
        return 0;
    }

    int K = 1;
    for (int i = 2; i <= N; ++i) {
        if (x[i].size() < x[K].size()) K = i;
    }

    for (int i = 1; i <= N; ++i) {
        f[i] = i;
        d[i] = 1;
    }

    for (int i = 0; i < x[K].size(); ++i) z[x[K][i]] = true;
    for (int i = 1; i <= N; ++i) {
        if (!z[i]) Union(K, i);
    }

//    cout << K << endl;
//    for (int i = 1; i <= N; ++i) cout << i << " " << z[i] << " " << find(i) << endl;

    memset(z, 0, sizeof(z));
    vector<int> X;
    for (int i = 1; i <= N; ++i) {
        if (find(i) != find(K)) {
            X.push_back(i);
        } else {
            z[i] = true;
        }
    }

//    for (int i = 0; i < X.size(); ++i) cout << X[i] << " ";
//    cout << endl;

 //   for (int i = 1; i <= N; ++i) cout << z[i] << " ";
 //   cout << endl;

    for (int i = 0; i < X.size(); ++i) {
        dfsbig(X[i]);
    }

    memset(z, 0, sizeof(z));
    vector<int> ansT;
    for (int i = 1; i <= N; ++i) {
        if (z[find(i)]) continue;
        z[find(i)] = true;
        ansT.push_back(d[find(i)]);
    }
    cout << ansT.size() << endl;
    sort(ansT.begin(), ansT.end());
    for (int i = 0; i < ansT.size(); ++i) cout << ansT[i] << " ";
    cout << endl;

    return 0;
}