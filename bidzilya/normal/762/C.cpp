#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int CHARS_COUNT = 26;

inline int GetChar(char c) {
    return c - 'a';
}

string s, t;

vector<vector<int>> nxt, prv;

vector<int> pref, suff;

void Solve() {
    const int n = s.length();

    nxt.assign(n, vector<int>(CHARS_COUNT, -1));
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) {
            nxt[i] = nxt[i + 1];
        }
        nxt[i][GetChar(s[i])] = i;
    }
    prv.assign(n, vector<int>(CHARS_COUNT, -1));
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            prv[i] = prv[i - 1];
        }
        prv[i][GetChar(s[i])] = i;
    }

    const int m = t.length();
    pref.resize(m);
    for (int i = 0; i < m; ++i) {
        pref[i] = (i == 0 ? 0 : min(pref[i - 1] + 1, n));

        if (pref[i] != n) {
            int value = nxt[pref[i]][GetChar(t[i])];
            if (value != -1) {
                pref[i] = value;
            } else {
                pref[i] = n;
            }
        }
    }

    suff.resize(m);
    for (int i = m - 1; i >= 0; --i) {
        suff[i] = (i == m - 1 ? n - 1 : max(-1, suff[i + 1] - 1));

        if (suff[i] != -1) {
            int value = prv[suff[i]][GetChar(t[i])];
            if (value != -1) {
                suff[i] = value;
            } else {
                suff[i] = -1;
            }
        }
    }

    if (pref[m - 1] < n) {
        cout << t << endl;
        return;
    }

    int result = 0;
    int resultStart;
    int resultFinish;

    auto update = [&] (int s, int f) {
        int curResult = m - (f - s + 1);
        if (curResult > result) {
            result = curResult;
            resultStart = s;
            resultFinish = f;
        }
    };

    for (int i = 0, j = 0; i < m; ++i) {
        if (j < i) {
            j = i;
        }
        int prev = (i == 0 ? 0 : pref[i - 1] + 1);
        while (j + 1 < m && suff[j + 1] < prev) {
            ++j;
        }
        if ((j == m - 1 && prev <= n) || j < m - 1) {
            update(i, j);
        }
    }

    if (result == 0) {
        cout << "-";
    } else {
        for (int i = 0; i < resultStart; ++i) {
            cout << t[i];
        }
        for (int i = resultFinish + 1; i < m; ++i) {
            cout << t[i];
        }
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> s >> t)) {
        return false;
    } else {
        return true;
    }
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