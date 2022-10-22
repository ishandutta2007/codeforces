#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;

vector<int> X[MAXN];
int Y[MAXN], D[MAXN], C[MAXN], E[MAXN];

int dfs(int a, int MM) {
 //   cout << a << " " << MM << endl;
    D[a] = MM;
    ++C[MM];
    for (int i = 0; i < X[a].size(); ++i) {
        int b = X[a][i];
        if (D[b] > 0) continue;
        dfs(b, MM);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= K; ++i) cin >> Y[i];
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    for (int i = 1; i <= K; ++i) { 
        dfs(Y[i], i);
    }

    for (int i = 1; i <= N; ++i) {
        E[D[i]] += X[i].size();
    }
    int dd = 0, res = N;
    for (int i = 1; i <= K; ++i) {
        dd = max(dd, C[i]);
        res -= C[i];
      //  cout << Y[i] << " " << D[Y[i]] << " " << C[i] << " " << E[i] << endl;
    }

    int ans = 0;
    for (int i = 1; i <= K; ++i) {
        if (dd == C[i]) {
            dd = -1;
            C[i] += res;
            ans += C[i] * (C[i] - 1) / 2 - E[i] / 2 - E[0] / 2;
        } else {
            ans += C[i]* (C[i] - 1) / 2 - E[i] / 2;
        }
    }

    cout << ans << endl;

    return 0;
}