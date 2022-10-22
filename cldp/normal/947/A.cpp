#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool z[MAXN];
vector<int> X;
vector<int> y[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 2; i < MAXN; ++i) {
        if (z[i]) continue;
        X.push_back(i);
        for (int j = i + i; j < MAXN; j += i) {
            z[j] = true;
            y[j].push_back(i);
        }
    }

    int N;
    cin >> N;
    int temp = y[N][y[N].size() - 1];
    int ans = INF;
    for (int i = temp * (N / temp - 1) + 1; i <= N - 1; ++i) {
        ans = min(ans, i);
        if (y[N].size() == 0) continue;
        for (int j = 0; j < y[i].size(); ++j) {
            int t2 = y[i][j];
            ans = min(ans, t2 * (i / t2 - 1) + 1);
        }
    }
    cout << ans << endl;

    return 0;
}