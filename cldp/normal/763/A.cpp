#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

vector<int> X[MAXN];
int D[MAXN];

bool dfs(int a, int col, int f) {
    if (D[a] != col) return false;
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i] == f) continue;
        if (!dfs(X[a][i], col, a)) return false;
    }
    return true;
}

bool check(int a) {
    for (int i = 0; i < X[a].size(); ++i) {
        if (!dfs(X[a][i], D[X[a][i]], a)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i) cin >> D[i];
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < X[i].size(); ++j) {
            if (D[i] != D[X[i][j]]) {
                if (check(i)) {
                    cout << "YES" << endl << i << endl;
                    return 0;
                }
                if (check(X[i][j])) {
                    cout << "YES" << endl << X[i][j] << endl;
                    return 0;
                }
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl << 1 << endl;
    return 0;
}