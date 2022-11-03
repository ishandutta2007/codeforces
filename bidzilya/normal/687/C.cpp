#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int LIM = 501;

bool dp[LIM][LIM];

int main() {
    /*
    freopen("input2.txt", "w", stdout);
    const int N = 500;
    cout << N << " " << N << endl;
    for (int i = 1; i <= N; ++i) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
    freopen("input2.txt", "r", stdin);
    */
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        int cur = c[i];
        for (int x = k; x >= 0; --x) {
            for (int y = k - x; y >= 0; --y) {
                if (!dp[x][y]) {
                    continue;
                }
                if (x + cur <= k) {
                    dp[x + cur][y] = true;
                }
                if (y + cur <= k) {
                    dp[x][y + cur] = true;
                }
            }
        }
    }

    vector<bool> good(k + 1, false);
    for (int i = 0; i <= k; ++i) {
        int j = k - i;

        if (dp[i][j]) {
            good[i] = true;
        }
    }

    vector<int> result;
    for (int i = 0; i <= k; ++i) {
        if (good[i]) {
            result.push_back(i);
        }
    }
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}