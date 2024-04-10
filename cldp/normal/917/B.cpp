#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int INF = 1000000007;
const double PI = acos(-1.0);

int ans[MAXN][MAXN][26];
vector<pair<int, int> > x[MAXN];

bool compare(const pair<int, int> &A, const pair<int, int> &B) {
    return A.second > B.second;
}

int dp(int a, int b, int c) {
    if (ans[a][b][c] > 0) return ans[a][b][c];

    if (x[a].size() == 0) return ans[a][b][c] = 2;
    ans[a][b][c] = 2;

    for (int i = 0; i < x[a].size(); ++i) {
        if (x[a][i].second < c) break;
        if (dp(b, x[a][i].first, x[a][i].second) == 2) {
            ans[a][b][c] = 1;
            break;
        }
    }
    return ans[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        x[a].push_back(make_pair(b, c - 'a'));
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= N; ++i) {
        ans[i][i][0] = 2;
        sort(x[i].begin(), x[i].end(), compare);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp(i, j, 0);
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (ans[i][j][0] == 1) cout << "A"; else cout << "B";
        }
        cout << endl;
    }

    return 0;
}