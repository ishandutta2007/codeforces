#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

inline int GetGcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

inline long long GetGcdEx(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long nx;
    long long ny;
    long long g = GetGcdEx(b, a % b, nx, ny);
    x = ny;
    y = nx - ny * (a / b);
    return g;
}

inline int GetInv(int x, int m) {
    long long a;
    long long b;
    long long g = GetGcdEx(x, m, a, b);
    // assert(g == 1);
    a %= m;
    if (a < 0) {
        a += m;
    }
    return a;
}

const int MAX_A = 2e5 + 1;

int minDel[MAX_A];

void BuildInfo() {
    for (int i = 2; i < MAX_A; ++i) {
        minDel[i] = -1;
    }
    for (int i = 2; i < MAX_A; ++i) {
        if (minDel[i] == -1) {
            minDel[i] = i;
            if (1LL * i * i < MAX_A) {
                for (int j = i * i; j < MAX_A; j += i) {
                    minDel[j] = i;
                }
            }
        }
    }
}

int n, m;
vector<int> a;
vector<bool> bad;
vector<vector<int>> bs;

inline int GetCost(int x) {
    return bs[x].size();
}

vector<int> dp;
vector<int> pr;

void Solve() {
    bs.clear();
    bs.resize(m + 1);
    bad.assign(m, false);
    for (int i : a) {
        bad[i] = true;
    }
    for (int i = 0; i < m; ++i) {
        if (!bad[i]) {
            bs[GetGcd(i, m)].push_back(i);
        }
    }
    dp.resize(m + 1);
    pr.resize(m + 1);
    dp[1] = GetCost(1);
    pr[1] = -1;
    for (int i = 2; i <= m; ++i) {
        dp[i] = GetCost(i) + dp[1];
        pr[i] = 1;
        int x = i;
        while (x != 1) {
            const int d = minDel[x];
            while (x % d == 0) {
                x /= d;
            }
            int newCost = dp[i / d] + GetCost(i);
            if (newCost > dp[i]) {
                dp[i] = newCost;
                pr[i] = i / d;
            }
        }
    }
    int maxI = 1;
    for (int i = 2; i <= m; ++i) {
        if (dp[i] > dp[maxI]) {
            maxI = i;
        }
    }
    vector<int> c;
    for (int i = maxI; i != -1; i = pr[i]) {
        for (int x : bs[i]) {
            c.push_back(x);
        }
    }
    reverse(c.begin(), c.end());
    /*
    for (int i = 0; i + 1 < (int) c.size(); ++i) {
        const int gi = GetGcd(c[i], m);
        const int gin = GetGcd(c[i + 1], m);
        assert(gin % gi == 0);
    }
    */
    vector<int> b;
    if (!c.empty()) {
        b.push_back(c[0]);
        for (int i = 1; i < (int) c.size(); ++i) {
            const int g = GetGcd(c[i - 1], m);
            const int cc = c[i] / g;
            const int pc = c[i - 1] / g;
            const int cm = m / g;
            b.push_back((1LL * GetInv(pc, cm) * cc) % cm);
        }
    }
    /*
    {
        int cur = 1 % m;
        for (int i = 0; i < (int) b.size(); ++i) {
            cur = (1LL * cur * b[i]) % m;
            assert(cur == c[i]);
            assert(!bad[cur]);
        }
    }
    */
    cout << b.size() << endl;
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n >> m)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return true;
}

int main() {
    BuildInfo();

    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}