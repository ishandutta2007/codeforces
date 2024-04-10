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

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

int GetBinaryPow(int x, int pw) {
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

int GetInv(int x) {
    return GetBinaryPow(x, MOD - 2);
}

const int MAX_FACT = 1e5 + 100;

vector<int> fact;
vector<int> invFact;

void BuildFact() {
    fact.resize(MAX_FACT);
    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; ++i) {
        fact[i] = fact[i - 1];
        ModMul(fact[i], i);
    }
    invFact.resize(MAX_FACT);
    for (int i = 0; i < MAX_FACT; ++i) {
        invFact[i] = GetInv(fact[i]);
    }
}

int GetC(int n, int k) {
    if (k > n) {
        return 0;
    }
    int result = fact[n];
    ModMul(result, invFact[n - k]);
    ModMul(result, invFact[k]);
    return result;
}

int main() {
    // freopen("input.txt", "r", stdin);

    BuildFact();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int prob;
    int nonProb;
    {
        int a, b;
        cin >> a >> b;

        prob = GetModMul(a, GetInv(b));
        nonProb = GetModMul(b - a, GetInv(b));
    }

    int k;
    cin >> k;

    vector<int> probPow(k + 1);
    vector<int> nonProbPow(k + 1);

    probPow[0] = 1;
    nonProbPow[0] = 1;
    for (int i = 1; i <= k; ++i) {
        probPow[i] = probPow[i - 1];
        nonProbPow[i] = nonProbPow[i - 1];

        ModMul(probPow[i], prob);
        ModMul(nonProbPow[i], nonProb);
    }

    vector<int> f(max(k, m) + 1, 0);
    for (int i = 0; i <= k; ++i) {
        f[i] = GetC(k, i);
        ModMul(f[i], probPow[i]);
        ModMul(f[i], nonProbPow[k - i]);
    }

    vector<vector<int>> baseDp(m, vector<int>(m));
    for (int l = 0; l < m; ++l) {
        for (int r = l; r < m; ++r) {
            baseDp[l][r] = f[l];
            ModMul(baseDp[l][r], f[m - r - 1]);
        }
    }

    vector<int> suffix[2];
    vector<int> prefix[2];

    int curPtr = 0;
    suffix[curPtr].resize(m);
    prefix[curPtr].resize(m);

    suffix[curPtr][m - 1] = baseDp[m - 1][m - 1];
    for (int i = m - 2; i >= 0; --i) {
        suffix[curPtr][i] = suffix[curPtr][i + 1];

        const int l = i;
        for (int r = l; r < m; ++r) {
            ModSum(suffix[curPtr][i], baseDp[l][r]);
        }
    }

    prefix[curPtr][0] = baseDp[0][0];
    for (int i = 1; i < m; ++i) {
        prefix[curPtr][i] = prefix[curPtr][i - 1];

        const int r = i;
        for (int l = 0; l <= r; ++l) {
            ModSum(prefix[curPtr][i], baseDp[l][r]);
        }
    }

    auto calcSuffixSuffix = [&f, m] (vector<int>& suffixSuffix, const vector<int>& suffix) {
        suffixSuffix.assign(m, 0);

        int sum = 0;
        for (int i = m - 2; i >= 0; --i) {
            ModSum(sum, GetModMul(f[m - i - 1], suffix[i + 1]));
            suffixSuffix[i] = suffixSuffix[i + 1];
            ModSum(suffixSuffix[i], GetModMul(sum, f[i]));
        }
    };

    vector<int> suffixSuffix[2];
    calcSuffixSuffix(suffixSuffix[curPtr], suffix[curPtr]);

    auto calcPrefixSuffix = [&f, m] (vector<int>& prefixSuffix, const vector<int>& prefix) {
        prefixSuffix.assign(m, 0);

        int sum = 0;
        for (int i = m - 1; i >= 0; --i) {
            ModSum(sum, f[m - i - 1]);
            if (i + 1 < m) {
                prefixSuffix[i] = prefixSuffix[i + 1];
            }
            if (i > 0) {
                ModSum(prefixSuffix[i], GetModMul(GetModMul(prefix[i - 1], f[i]), sum));
            }
        }
    };

    vector<int> prefixSuffix[2];
    calcPrefixSuffix(prefixSuffix[curPtr], prefix[curPtr]);

    auto calcSuffixPrefix = [&f, m] (vector<int>& suffixPrefix, const vector<int>& suffix) {
        suffixPrefix.assign(m, 0);

        int sum = 0;
        for (int i = 0; i < m; ++i) {
            ModSum(sum, f[i]);
            if (i > 0) {
                suffixPrefix[i] = suffixPrefix[i - 1];
            }
            if (i + 1 < m) {
                ModSum(suffixPrefix[i], GetModMul(GetModMul(f[m - i - 1], suffix[i + 1]), sum));
            }
        }
    };

    vector<int> suffixPrefix[2];
    calcSuffixPrefix(suffixPrefix[curPtr], suffix[curPtr]);

    auto calcPrefixPrefix = [&f, m] (vector<int>& prefixPrefix, const vector<int>& prefix) {
        prefixPrefix.assign(m, 0);

        int sum = 0;
        for (int i = 1; i < m; ++i) {
            ModSum(sum, GetModMul(prefix[i - 1], f[i]));
            prefixPrefix[i] = prefixPrefix[i - 1];
            ModSum(prefixPrefix[i], GetModMul(sum, f[m - i - 1]));
        }
    };

    vector<int> prefixPrefix[2];
    calcPrefixPrefix(prefixPrefix[curPtr], prefix[curPtr]);

    vector<int> baseSuffixDp = suffix[curPtr];
    vector<int> basePrefixDp = prefix[curPtr];

    for (int i = 1; i < n; ++i) {
        int nxtPtr = 1 - curPtr;

        suffix[nxtPtr].assign(m, 0);
        prefix[nxtPtr].assign(m, 0);

        for (int i = m - 1; i >= 0; --i) {
            int s1 = baseSuffixDp[i];
            ModMul(s1, suffix[curPtr][0]);

            int s2 = suffixSuffix[curPtr][i];
            if (s2 != 0) {
                s2 = MOD - s2;
            }

            int s3 = prefixSuffix[curPtr][i];
            if (s3 != 0) {
                s3 = MOD - s3;
            }

            ModSum(suffix[nxtPtr][i], s1);
            ModSum(suffix[nxtPtr][i], s2);
            ModSum(suffix[nxtPtr][i], s3);
        }

        for (int i = 0; i < m; ++i) {
            int s1 = basePrefixDp[i];
            ModMul(s1, suffix[curPtr][0]);

            int s2 = suffixPrefix[curPtr][i];
            if (s2 != 0) {
                s2 = MOD - s2;
            }

            int s3 = prefixPrefix[curPtr][i];
            if (s3 != 0) {
                s3 = MOD - s3;
            }

            ModSum(prefix[nxtPtr][i], s1);
            ModSum(prefix[nxtPtr][i], s2);
            ModSum(prefix[nxtPtr][i], s3);
        }

        calcSuffixSuffix(suffixSuffix[nxtPtr], suffix[nxtPtr]);
        calcPrefixSuffix(prefixSuffix[nxtPtr], prefix[nxtPtr]);

        calcSuffixPrefix(suffixPrefix[nxtPtr], suffix[nxtPtr]);
        calcPrefixPrefix(prefixPrefix[nxtPtr], prefix[nxtPtr]);

        swap(curPtr, nxtPtr);
    }

    cout << suffix[curPtr][0] << endl;

    return 0;
}