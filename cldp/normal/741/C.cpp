#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100010;

int A[MAXN], B[MAXN], f[MAXN + MAXN];
vector<int> x[MAXN + MAXN];

int dfs(int a, int b) {
    if (f[a] == 0) {
        f[a] = b;
        for (int i = 0; i < x[a].size(); ++i) dfs(x[a][i], 3 - b);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        --A[i];
        --B[i];
        x[A[i]].push_back(B[i]);
        x[B[i]].push_back(A[i]);
        x[i + i].push_back(i + i + 1);
        x[i + i + 1].push_back(i + i);
    }
    for (int i = 0; i < N + N; ++i) {
        if (f[i]) continue;
        dfs(i, 1);
    }
    for (int i = 0; i < N; ++i) cout << f[A[i]] << " " << f[B[i]] << endl;

    return 0;
}