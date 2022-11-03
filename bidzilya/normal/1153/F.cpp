#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <random>

#include <cassert>
using namespace std;

const int MOD = 998244353;

inline void ModSum(int& x, int y)
{
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline int GetModSum(int x, int y)
{
    ModSum(x, y);
    return x;
}

inline void ModMul(int& x, int y)
{
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y)
{
    ModMul(x, y);
    return x;
}

inline int GetBinaryPow(int x, int pw)
{
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

inline int GetInv(int x)
{
    auto inv = GetBinaryPow(x, MOD - 2);
    assert(GetModMul(x, inv) == 1);
    return inv;
}

const int MAX_N = 2000;

vector<vector<int>> cs;
vector<int> allResult;

void Prepare()
{
    cs.assign(MAX_N + 1, vector<int>(MAX_N + 1));
    for (int i = 0; i <= MAX_N; ++i) {
        cs[i][0] = 1;
    }
    for (int i = 1; i <= MAX_N; ++i) {
        cs[0][i] = 0;
    }
    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = 1; j <= MAX_N; ++j) {
            cs[i][j] = cs[i - 1][j];
            ModSum(cs[i][j], cs[i - 1][j - 1]);
        }
    }

    vector<int> factorial(2 * MAX_N + 1 + 1);
    factorial[0] = 1;
    for (int i = 1; i < (int) factorial.size(); ++i) {
        factorial[i] = GetModMul(factorial[i - 1], i);
    }

    allResult.resize(MAX_N + 1);
    for (int i = 0; i <= MAX_N; ++i) {
        allResult[i] = GetBinaryPow(2, i);
        ModMul(allResult[i], factorial[i]);
        ModMul(allResult[i], factorial[i]);
        ModMul(allResult[i], GetInv(factorial[2 * i + 1]));
    }
}

int GetSign(int x)
{
    if (abs(x) % 2 == 0) {
        return 1;
    }
    return MOD - 1;
}

int GetResult(int n, int k)
{
    int result = 0;
    for (int k0 = k; k0 <= n; ++k0) {
        for (int k1 = k0; k1 <= n; ++k1) {
            int currentResult = cs[n][k1];
            ModMul(currentResult, allResult[k1]);
            ModMul(currentResult, cs[k1][k0]);
            ModMul(currentResult, GetSign(k1 - k0));
            ModSum(result, currentResult);
        }
    }
    return result;
}

int n, k, l;

void Solve()
{
    cout << GetModMul(GetResult(n, k), l % MOD) << endl;
}

bool Read()
{
    if (!(cin >> n >> k >> l)) {
        return false;
    }
    return true;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Prepare();

    while (Read()) {
        Solve();
    }

    return 0;
}