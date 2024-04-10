#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

const int INF = 1e9;

const int MAX_K = 90;

const int MAX_N = 4e3;

int n;
vector<int> a;
vector<int> sa;

inline int GetSum(int l, int r) {
    l = max(l, 0);
    r = min(r, n - 1);
    if (l > r) {
        return 0;
    }
    return (l == 0 ? sa[r] : sa[r] - sa[l - 1]);
}

int result[MAX_N + 1][MAX_K + 1][2 * MAX_K + 1];

int GetResult(int firstLen, int startLen, int deltaLen) {
    if (result[firstLen][startLen][deltaLen + MAX_K] != INF) {
        return result[firstLen][startLen][deltaLen + MAX_K];
    }
    int& r = result[firstLen][startLen][deltaLen + MAX_K];

    const int secondLen = firstLen + deltaLen;

    const int remains = n - (firstLen + secondLen);

    if (remains < startLen) {
        return r = 0;
    }

    r = -INF;

    for (int firstStep = startLen; firstStep <= startLen + 1; ++firstStep) {
        if (firstStep > remains) {
            continue;
        }

        int newRemains = remains - firstStep;

        if (newRemains < firstStep) {
            r = max(r, GetSum(firstLen, firstLen + firstStep - 1));
            continue;
        }

        int curResult = INF;
        for (int secondStep = firstStep; secondStep <= firstStep + 1; ++secondStep) {
            if (secondStep > newRemains) {
                continue;
            }

            int newFirstLen = firstLen + firstStep;
            int newSecondLen = secondLen + secondStep;

            int cost = GetSum(firstLen, newFirstLen - 1) -
                GetSum(n - newSecondLen, n - secondLen - 1);

            cost += GetResult(newFirstLen, secondStep, newSecondLen - newFirstLen);

            curResult = min(curResult, cost);
        }

        r = max(r, curResult);
    }

    return r;
}

void Solve() {
    sa.resize(n);
    sa[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sa[i] = sa[i - 1] + a[i];
    }

    for (int j = 0; j <= MAX_N; ++j) {
        for (int t = 1; t <= MAX_K; ++t) {
            for (int l = 0; l <= 2 * MAX_K; ++l) {
                result[j][t][l] = INF;
            }
        }
    }

    cout << GetResult(0, 1, 0) << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
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