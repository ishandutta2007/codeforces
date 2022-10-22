#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<int> X[MAXN];

bool dfs(int a) {
    bool ans = true;
    int cnt = 0;
    for (int i = 0; i < X[a].size(); ++i) {
        int b = X[a][i];
        if (X[b].size() == 0) ++cnt; else ans &= dfs(b);
    }
    return ans && cnt >= 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, a;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        cin >> a;
        X[a].push_back(i);
    }
    if (dfs(1)) cout << "Yes" << endl; else cout << "No" << endl;
    return 0;
}