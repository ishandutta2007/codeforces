#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 300010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int IN[MAXN], f[MAXN][26];
vector<int> x[MAXN]; 

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    string P;
    cin >> P;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        ++IN[b];
    }
    queue<int> Q;
    for (int i = 1; i <= N; ++i) {
        if (IN[i] == 0) {
            Q.push(i);
            f[i][P[i - 1] - 'a'] = 1;
        }
    }
    int ans = 1, cnt = 0;
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        ++cnt;
        for (int i = 0; i < x[a].size(); ++i) {
            int b = x[a][i];
            --IN[b];
            if (IN[b] == 0) Q.push(b);
            for (int j = 0; j < 26; ++j) {
                if (j == P[b - 1] - 'a') f[b][j] = max(f[b][j], f[a][j] + 1); else f[b][j] = max(f[b][j], f[a][j]);
                ans = max(ans, f[b][j]);
            }
        }
    }
    if (cnt != N) ans = -1;
    cout << ans << endl;
    return 0;
}