#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int MAX_K = 3e5;

const int MOD = 1e9 + 7;

inline void ModMult(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMult(int x, int y) {
    ModMult(x, y);
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
    if (pw == 0) {
        return 1;
    }
    if (pw & 1) {
        return GetModMult(x, GetBinaryPow(x, pw - 1));
    }
    return GetBinaryPow(GetModMult(x, x), pw >> 1);
}

inline int GetInv(int x) {
    return GetBinaryPow(x, MOD - 2);
}

vector<int> fact;
vector<int> invFact;

void BuildFact() {
    fact.resize(MAX_K + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAX_K; ++i) {
        fact[i] = GetModMult(fact[i - 1], i);
    }
    invFact.resize(MAX_K + 1);
    for (int i = 0; i <= MAX_K; ++i) {
        invFact[i] = GetInv(fact[i]);
    }
}

vector<pair<int, int>> Factorize(int x) {
    vector<pair<int, int>> result;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            result.push_back(make_pair(i, 0));
            while (x % i == 0) {
                ++result.back().second;
                x /= i;
            }
        }
    }
    if (x > 1) {
        result.push_back(make_pair(x, 1));
    }
    return result;
}

vector<bool> isPrime;

void BuildIsPrime() {
    isPrime.assign(MAX_K + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_K; ++i) {
        for (int j = i * i; j <= MAX_K; j += i) {
            isPrime[j] = false;
        }
    }
}

vector<int> maxPower;

void BuildMaxPower() {
    maxPower.assign(MAX_K + 1, 0);
    for (int i = 0; i <= MAX_K; ++i) {
        if (isPrime[i]) {
            long long x = i;
            while (x <= MAX_K) {
                ++maxPower[i];
                x *= i;
            }
        }
    }
}

inline int GetC(int n, int k) {
    if (k > n) {
        return 0;
    }
    if (n < 0) {
        return 0;
    }
    return GetModMult(fact[n], GetModMult(invFact[k], invFact[n - k]));
}

vector<int> sumC;

void BuildCs(int n) {
    sumC.resize(n + 1);
    sumC[0] = GetC(n - 1, 0);
    for (int i = 1; i <= n; ++i) {
        sumC[i] = sumC[i - 1];
        ModSum(sumC[i], GetC(n - 1, i));
    }
}

inline int GetSumC(int x) {
    if (x < 0) {
        return 0;
    }
    return sumC[x];
}

int GetResult(const vector<int>& counts, int mult) {
    int k = counts.size();
    int curCount = 0;
    int s = 0;
    int result = 0;
    for (int i = 0; i < k; ++i) {
        int curS = GetModMult(curCount, i);
        ModSum(curS, s);
        ModSum(result, GetModMult(curS, GetModSum(sumC[curCount + counts[i]], -sumC[curCount])));
        ModSum(s, GetModMult(counts[i], -i));
        curCount += counts[i];
    }
    s = 0;
    curCount = 0;
    for (int i = k - 1; i >= 0; --i) {
        int curS = GetModMult(curCount, -i);
        ModSum(curS, s);
        ModSum(result, GetModMult(curS, GetModSum(GetSumC(curCount + counts[i] - 1), -GetSumC(curCount - 1))));
        ModSum(s, GetModMult(counts[i], i));
        curCount += counts[i];
    }
    return result;
}

int main() {
    BuildFact();
    BuildIsPrime();
    BuildMaxPower();

    vector<vector<int>> counts(MAX_K + 1);
    for (int i = 0; i <= MAX_K; ++i) {
        if (isPrime[i]) {
            counts[i].assign(maxPower[i] + 1, 0);
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    BuildCs(n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vector<pair<int, int>> f = Factorize(a[i]);
        for (const pair<int, int>& x : f) {
            ++counts[x.first][x.second];
        }
    }

    int result = 0;
    for (int i = 2; i <= MAX_K; ++i) {
        if (isPrime[i]) {
            counts[i][0] = n;
            for (int j = 1; j < (int) counts[i].size(); ++j) {
                counts[i][0] -= counts[i][j];
            }
            int r = GetResult(counts[i], i);
            if (r != 0) {
//                cout << i << ": " << r << endl;
                ModSum(result, r);
            }
        }
    }
    cout << result << endl;

    return 0;
}