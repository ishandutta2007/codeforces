#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int e[MAXN], in[MAXN];
vector<int> x[MAXN];
int f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> e[i];
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        x[b].push_back(a);
        ++in[a];
    }
    queue<int> Q;
    for (int i = 0; i < N; ++i) {
        if (in[i] == 0) Q.push(i);
    }
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        if (e[a] == 1) f[a] = max(f[a], 1);
        for (int i = 0; i < x[a].size(); ++i) {
            int b = x[a][i];
            --in[b];
            if (in[b] == 0) Q.push(b);
            if (e[a] == e[b]) {
                f[b] = max(f[a], f[b]);
                continue;
            }
            if (e[a] == 0) {
                f[b] = max(f[a] + 1, f[b]);
            } else {
                f[b] = max(f[a], f[b]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}