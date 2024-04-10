#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#define count count123123

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

int mod, phi;

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % mod;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    if (x < 0) {
        x += mod;
    }
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

inline int GetBinaryPow(int x, int pw) {
    int r = 1 % mod;
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
    return GetBinaryPow(x, phi - 1);
}

void SetPhi() {
    phi = mod;
    int n = mod;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            phi -= (phi / i);
        }
    }
    if (n > 1) {
        phi -= (phi / n);
        n = 1;
    }
}

void CheckPhi() {
    for (mod = 1; mod <= 1000; ++mod) {
        SetPhi();

        for (int i = 1; i < mod; ++i) {
            if (GetGcd(i, mod) == 1) {
                if (GetModMul(i, GetInv(i)) != 1) {
                    cout << "FAIL" << endl;
                }
            }
        }
    }
    exit(0);
}

const int MAX_POWER = 1e5 + 100;

vector<int> pw10;
vector<int> invPw10;

void BuildPw() {
    pw10.resize(MAX_POWER);
    invPw10.resize(MAX_POWER);

    pw10[0] = invPw10[0] = 1 % mod;

    const int inv10 = GetInv(10);
    const int mod10 = 10 % mod;
    for (int i = 1; i < MAX_POWER; ++i) {
        pw10[i] = pw10[i - 1];
        ModMul(pw10[i], mod10);

        invPw10[i] = invPw10[i - 1];
        ModMul(invPw10[i], inv10);
    }
}

struct TEdge {
    int From;
    int To;
    int Cost;
};

int n;
vector<vector<TEdge>> g;

vector<int> usedCentroid;

long long result;

vector<int> count;

void BuildCount(int v, int pr) {
    count[v] = 1;
    for (const TEdge& e : g[v]) {
        int u = e.To;
        if (usedCentroid[u] || u == pr) {
            continue;
        }

        BuildCount(u, v);

        count[v] += count[u];
    }
}

int GetCentroid(int cn, int v, int pr) {
    int bad = -1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i].To;
        if (usedCentroid[u] || u == pr) {
            continue;
        }

        if (count[u] * 2 > cn) {
            bad = i;
            break;
        }
    }
    if (bad == -1) {
        return v;
    } else {
        return GetCentroid(cn, g[v][bad].To, v);
    }
}

inline int GetNeg(int x) {
    return x == 0 ? 0 : mod - x;
}

vector<pair<int, int>> values;
map<int, int> val;
map<int, int> valPw10;

inline int Get(map<int, int>& mp, int key) {
    auto itr = mp.find(key);
    return itr == mp.end() ? 0 : itr->second;
}

void CalcResultForPart(int v, int pr, int curVal, int revCurVal, int curHeight) {
    int curValPw10 = curVal;
    ModMul(curValPw10, invPw10[curHeight]);

    result += Get(val, curValPw10);
    result += Get(valPw10, GetNeg(revCurVal));

    values.push_back(make_pair(GetNeg(revCurVal), curValPw10));

    for (const TEdge& e : g[v]) {
        int u = e.To;
        if (u == pr || usedCentroid[u]) {
            continue;
        }

        int newVal = curVal;
        ModMul(newVal, pw10[1]);
        ModSum(newVal, e.Cost);

        int newRevVal = pw10[curHeight];
        ModMul(newRevVal, e.Cost);
        ModSum(newRevVal, revCurVal);

        CalcResultForPart(u, v, newVal, newRevVal, curHeight + 1);
    }
}

void BuildResult(int v) {
    BuildCount(v, -1);

    if (count[v] == 1) {
        return;
    }

    int centroid = GetCentroid(count[v], v, -1);

    val.clear();
    valPw10.clear();
    values.clear();
    usedCentroid[centroid] = true;
    for (const TEdge& e : g[centroid]) {
        int u = e.To;
        if (!usedCentroid[u]) {
            int valuesSize = values.size();
            CalcResultForPart(u, -1, e.Cost, e.Cost, 1);
            for (int i = valuesSize; i < (int) values.size(); ++i) {
                ++val[values[i].first];
                ++valPw10[values[i].second];
            }
        }
    }

    for (const auto& v : values) {
        if (v.first == 0) {
            ++result;
        }
        if (v.second == 0) {
            ++result;
        }
    }

    for (const TEdge& e : g[centroid]) {
        int u = e.To;
        if (!usedCentroid[u]) {
            BuildResult(u);
        }
    }
}

int main() {
    scanf("%d%d", &n, &mod);
    SetPhi();

    BuildPw();

    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2, c;
        scanf("%d%d%d", &v1, &v2, &c);
        while (c >= mod) {
            c -= mod;
        }
        g[v1].push_back(TEdge{v1, v2, c});
        g[v2].push_back(TEdge{v2, v1, c});
    }

    usedCentroid.assign(n, false);
    result = 0;
    count.resize(n);
    BuildResult(0);

    printf("%lld\n", result);

    return 0;
}