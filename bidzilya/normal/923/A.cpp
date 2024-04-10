#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const int INF = 1e9;

const int LIM = 1e6;

int pmin[LIM + 1];

void Build() {
    for (int i = 0; i <= LIM; ++i) {
        pmin[i] = -1;
    }
    for (int i = 2; i <= LIM; ++i) {
        if (pmin[i] != -1) {
            continue;
        }
        pmin[i] = i;
        if (1LL * i * i <= LIM) {
            for (int j = i * i; j <= LIM; j += i) {
                if (pmin[j] == -1) {
                    pmin[j] = i;
                }
            }
        }
    }
}

void FillFact(int value, vector<int>& f) {
    f.clear();
    while (value > 1) {
        f.push_back(pmin[value]);
        value /= pmin[value];
    }
}

int n;

void Solve() {
    vector<int> nfact;
    FillFact(n, nfact);
    vector<int> fact;
    int result = INF;
    for (int i = 2; i <= n; ++i) {
        bool ok = false;
        for (int p : nfact) {
            if (p != n && n - i < p) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            continue;
        }

        FillFact(i, fact);
        for (int p : fact) {
            if (p != i) {
                result = min(result, i - p + 1);
            }
        }
    }
    assert(result != INF);
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    return true;
}

int main() {
    Build();

    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}