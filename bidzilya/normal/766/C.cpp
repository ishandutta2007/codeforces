#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;

const int MOD = 1e9 + 7;

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

const int CHARS_COUNT = 26;

inline int GetChar(char c) {
    return c - 'a';
}

int n;
string s;
vector<int> a;

vector<int> dpCount;

vector<bool> suff, pref;

vector<int> minPref;

vector<vector<bool>> good;

void Solve() {
    good.assign(n, vector<bool>(n, false));
    vector<bool> hasChar;
    for (int i = 0; i < n; ++i) {
        hasChar.assign(CHARS_COUNT, false);
        int maxLen = n;
        for (int j = i; j < n; ++j) {
            hasChar[GetChar(s[j])] = true;
            maxLen = min(maxLen, a[GetChar(s[j])]);

            if (j - i + 1 <= maxLen) {
                good[i][j] = true;
            }
        }
    }
    dpCount.assign(n + 1, 0);
    dpCount[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (good[i][j]) {
                ModSum(dpCount[j + 1], dpCount[i]);
            }
        }
    }
    cout << dpCount[n] << endl;

    pref.assign(n + 1, false);
    pref[0] = true;
    for (int i = 0; i < n; ++i) {
        if (!pref[i]) {
            continue;
        }
        for (int j = i; j < n; ++j) {
            if (good[i][j]) {
                pref[j + 1] = true;
            }
        }
    }

    suff.assign(n + 1, false);
    suff[0] = true;
    for (int i = 0; i < n; ++i) {
        if (!suff[i]) {
            continue;
        }
        const int ri = n - i - 1;
        for (int j = i; j < n; ++j) {
            const int rj = n - j - 1;
            if (good[rj][ri]) {
                suff[j + 1] = true;
            }
        }
    }
    reverse(suff.begin(), suff.end());

    int maxSubs = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (good[i][j] && pref[i] && suff[j + 1]) {
                maxSubs = max(maxSubs, j - i + 1);
            }
        }
    }
    cout << maxSubs << endl;

    minPref.assign(n + 1, INF);
    minPref[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (minPref[i] == INF) {
            continue;
        }
        for (int j = i; j < n; ++j) {
            if (good[i][j]) {
                minPref[j + 1] = min(minPref[j + 1], minPref[i] + 1);
            }
        }
    }
    cout << minPref[n] << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    cin >> s;
    a.resize(CHARS_COUNT);
    for (int i = 0; i < CHARS_COUNT; ++i) {
        cin >> a[i];
    }
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