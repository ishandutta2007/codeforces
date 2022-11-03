#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 20;
const int MAX_MASK = (1 << MAX_N);

int dp[2][MAX_MASK][MAX_N + 1];

void Clear(int id) {
    for (int mask = 0; mask < MAX_MASK; ++mask) {
        for (int i = 0; i <= MAX_N; ++i) {
            dp[id][mask][i] = 0;
        }
    }
}

void Relax(int id) {
    for (int mask = 0; mask < MAX_MASK; ++mask) {
        for (int i = MAX_N - 1; i >= 0; --i) {
            dp[id][mask][i] += dp[id][mask][i + 1];
        }
    }
}

int cost[MAX_MASK];

const int MAX_M = 1e6 + 100;

char s[MAX_M];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> masks(m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);

        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                masks[j] += (1 << i);
            }
        }
    }

    int curPtr = 0;
    Clear(curPtr);
    for (int j = 0; j < m; ++j) {
        ++dp[curPtr][masks[j]][n];
    }

    Relax(curPtr);

    for (int k = 1; k <= n; ++k) {
        int nxtPtr = 1 - curPtr;
        Clear(nxtPtr);

        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = n - 1; i >= 0; --i) {
                int newMask = mask ^ (1 << i);

                dp[nxtPtr][mask][i] += dp[curPtr][newMask][i + 1];
            }
        }

        swap(curPtr, nxtPtr);

        Relax(curPtr);

        int mul = min(k, n - k);
        for (int mask = 0; mask < (1 << n); ++mask) {
            cost[mask] += mul * dp[curPtr][mask][0];
        }
    }

    int result = n * m;
    for (int mask = 0; mask < (1 << n); ++mask) {
        result = min(result, cost[mask]);
    }
    cout << result << endl;

    return 0;
}