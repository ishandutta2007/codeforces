#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include <cassert>
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

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
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

const int LIM = 2e5;

int fact[LIM + 1];
int invFact[LIM + 1];

void Build() {
    fact[0] = 1;
    for (int i = 1; i <= LIM; ++i) {
        fact[i] = GetModMul(fact[i - 1], i);
    }
    for (int i = 0; i <= LIM; ++i) {
        invFact[i] = GetInv(fact[i]);
    }
}

int GetC(int n, int k) {
    if (k > n) {
        return 0;
    }
    return GetModMul(fact[n], GetModMul(invFact[k], invFact[n - k]));
}

int n;
vector<int> s[2];
vector<int> a[2];
vector<int> d;

int Iterate(int cur) {
    const int sz = a[cur].size();
    int nxt = 1 - cur;
    a[nxt].assign(sz + 1, 0);
    a[nxt][0] = a[cur][0];
    for (int j = 1; j < sz; ++j) {
        a[nxt][j] = a[cur][j] + s[cur][j - 1] * a[cur][j - 1];
    }
    a[nxt][sz] = s[cur][sz - 1] * a[cur][sz - 1];
    s[nxt].assign(sz + 1, 0);
    for (int j = 0; j <= sz; ++j) {
        s[nxt][j] = s[cur][0] * ((sz - j) % 2 == 1 ? 1 : -1);
    }
    return nxt;
}

int Initialize(int sz, int s0) {
    a[0].resize(sz);
    int k = sz >> 1;
    for (int i = 0; i < sz; ++i) {
        if ((i & 1) == 0) {
            a[0][i] = GetC(k, i >> 1);
        } else {
            a[0][i] = 0;
        }
    }
    s[0].resize(sz);
    s[0][sz - 1] = ((1LL * sz * (sz - 1) / 2) % 2 == 1 ? -s0 : s0);
    for (int i = sz - 2; i >= 0; --i) {
        s[0][i] = -s[0][i + 1];
    }
    return 0;
}

int GetS0() {
    return (1LL * (n - 1) * n / 2) % 2 == 1 ? 1 : -1;
}

void Solve() {
    if (n == 1) {
        cout << d[0] << endl;
        return;
    }
    int cur = -1;
    for (int sz = n; sz >= 1; --sz) {
        if (sz % 4 == 1) {
            cur = Initialize(sz, GetS0());
            break;
        }
    }
    assert(cur != -1);
    while (a[cur].size() != n) {
        cur = Iterate(cur);
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        ModSum(result, GetModMul(d[i], a[cur][i]));
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    d.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
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