#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5002;
const int INF = 1000000007;
const double PI = acos(-1.0);

int f[MAXN][MAXN], x[MAXN], y[MAXN];
bool g[MAXN][MAXN];
bool z[MAXN];

struct node {
    int a, b, c;
    node() {}
    node(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
};

int VK0(int N, int K, int V) {
    vector<node> ans;
    for (int i = 1; i < N; ++i) {
        ans.push_back(node(y[i] + 1, i + 1, 1));
        x[0] += x[i];
        y[0] += y[i];
    }
    y[0] += x[0] / K;
    x[0] %= K;
    if (y[0] < V / K) {
        cout << "NO" << endl;
        return 0;
    }
    if (V / K > 0) ans.push_back(node(V / K, 1, 2));
    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, K, V;
    cin >> N >> K >> V;

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        y[i] += x[i] / K;
        x[i] %= K;
        sum += y[i];
    }
    if (V % K == 0) return VK0(N, K, V);

    g[0][0] = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            g[i + 1][j] = g[i][j];
            f[i + 1][j] = -1;
        }
        if (x[i] == 0) continue;
        for (int j = 0; j < K; ++j) {
            if (!g[i][j]) continue;
            g[i + 1][(j + x[i]) % K] = true;
            f[i + 1][(j + x[i]) % K] = i;
        }
    }

    if (!g[N][V % K]) {
        cout << "NO" << endl;
        return 0;
    }

    int a = N, b = V % K;
    vector<int> X;
    while (a != 0) {
        if (f[a][b] == -1) {
            --a;
            continue;
        }
        X.push_back(f[a][b]);
        b = (b + K - x[f[a][b]]) % K;
        --a;
    }

    vector<node> ansT;
    sort(X.begin(), X.end());
    
    a = X[0];
    z[a] = true;
    for (int i = 1; i < X.size(); ++i) {
        int b = X[i];
        z[b] = true;
        x[a] += x[b];
        y[a] += y[b];
        ansT.push_back(node(y[b] + 1, b + 1, a + 1));
        x[b] = y[b] = 0;
    }

    b = (a + 1) % N;
    for (int i = 0; i < N; ++i) {
        if (!z[i] && i != b) {
            ansT.push_back(node(y[i] + 1, i + 1, b + 1));
            x[b] += x[i];
            y[b] += y[i];
            x[i] = y[i] = 0;
        }
    }

    y[a] += x[a] / K;
    x[a] %= K;
    y[b] += x[b] / K;
    y[b] %= K;

    if (y[a] < V / K) {
        if (y[a] + y[b] < V / K) {
            cout << "NO" << endl;
            return 0;
        }
        ansT.push_back(node(V / K - y[a], b + 1, a + 1));
    } else 
    if (y[a] > V / K) {
        ansT.push_back(node(y[a] - V / K, a + 1, b + 1));
    }
    cout << "YES" << endl;
    for (int i = 0; i < ansT.size(); ++i) cout << ansT[i].a << " " << ansT[i].b << " " << ansT[i].c << endl;

    return 0;
}