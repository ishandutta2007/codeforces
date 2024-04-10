#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline int GetBinaryPow(int x, int pw) {
    int r = 1;
    while (pw > 0) {
        if (pw & 1) {
            ModMul(r, x);
        }
        ModMul(x, x);
        pw >>= 1;
    }
    return r;
}

inline int GetInv(int x) {
    return GetBinaryPow(x, MOD - 2);
}

const int MAX_FACT = 1e6;

int fact[MAX_FACT];
int invFact[MAX_FACT];

void BuildFact() {
    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; ++i) {
        fact[i] = fact[i - 1];
        ModMul(fact[i], i);
    }
    for (int i = 0; i < MAX_FACT; ++i) {
        invFact[i] = GetInv(fact[i]);
    }
}

inline int GetC(int n, int k) {
    if (k > n) {
        return 0;
    }
    int r = fact[n];
    ModMul(r, invFact[k]);
    ModMul(r, invFact[n - k]);
    return r;
}

inline int GetF(int x, int y) {
    return GetC(x + y, x);
}

int main() {
    BuildFact();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back(make_pair(h, w));

    sort(a.begin(), a.end(), [] (const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
    });

    vector<int> result(a.size());
    for (int i = 0; i < (int) a.size(); ++i) {
        result[i] = GetF(a[i].first - 1, a[i].second - 1);

        for (int j = 0; j < i; ++j) {
            if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
                ModSum(result[i], -GetModMul(GetF(a[i].first - a[j].first, a[i].second - a[j].second), result[j]));
            }
        }
    }

    cout << result.back() << endl;

    return 0;
}