#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

const int CHARS_COUNT = 26;

inline int GetChar(char c) {
    return c - 'a';
}

const int MAX_N = 5000;

int n;
string s;

int a[MAX_N];

int revNxt[MAX_N];

int dp[2][MAX_N];
int dps[2][MAX_N];
int dpas[2][MAX_N];

void Solve() {
    for (int i = 0; i < n; ++i) {
        a[i] = GetChar(s[i]);
    }

    {
        for (int i = 0; i < n; ++i) {
            revNxt[i] = -1;
        }
        vector<int> buf(CHARS_COUNT, -1);
        for (int i = 0; i < n; ++i) {
            revNxt[i] = buf[a[i]];
            buf[a[i]] = i;
        }
    }

    int curPtr = 0;
    memset(dp[curPtr], 0, sizeof(int) * n);
    dp[curPtr][0] = 1;
    for (int i = 0; i < n; ++i) {
        dps[curPtr][i] = (revNxt[i] == -1 ? 0 : dps[curPtr][revNxt[i]]);
        ModSum(dps[curPtr][i], dp[curPtr][i]);
    }
    for (int i = 0; i < n; ++i) {
        dpas[curPtr][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        const int nxtPtr = 1 - curPtr;
        memset(dp[nxtPtr], 0, sizeof(int) * n);

        for (int j = 0; j < n; ++j) {
            dp[nxtPtr][j] = dpas[curPtr][j];

            const int y = revNxt[j];
            if (y != -1) {
                ModSum(dp[nxtPtr][j], -dps[nxtPtr][y]);
            }

            dps[nxtPtr][j] = (y == -1 ? 0 : dps[nxtPtr][y]);
            ModSum(dps[nxtPtr][j], dp[nxtPtr][j]);

            dpas[nxtPtr][j] = (j > 0 ? dpas[nxtPtr][j - 1] : 0);
            ModSum(dpas[nxtPtr][j], dp[nxtPtr][j]);
        }

        curPtr = nxtPtr;
    }

    cout << dpas[curPtr][n - 1] << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    cin >> s;
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}