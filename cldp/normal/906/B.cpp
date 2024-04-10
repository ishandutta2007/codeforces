#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int N, M;
vector<vector<int> > x;
set<int> S;

bool dfs(int t) {
    if (t == N * M) return true;
    int a = t / M, b = t % M;
    for (auto iter = S.begin(); iter != S.end(); ++iter) {
        if (a > 0) {
            int diff = abs(*iter - x[a - 1][b]);
            if (diff == 1 || diff == M) continue;
        }
        if (b > 0) {
            int diff = abs(*iter - x[a][b - 1]);
            if (diff == 1 || diff == M) continue;
        }
        x[a][b] = *iter;
        S.erase(x[a][b]);
        if (dfs(t + 1)) return true;
        S.insert(x[a][b]);
        iter = S.find(x[a][b]);
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    x = vector<vector<int> >(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) S.insert(i * M + j + 1);
    }
    if (dfs(0)) {
        cout << "YES" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) cout << x[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}