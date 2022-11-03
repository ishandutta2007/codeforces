#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

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

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

const int MAX_N = 1e6 + 100;

vector<int> powers;

void BuildPowers() {
    powers.assign(MAX_N, 0);
    powers[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        powers[i] = GetModMul(powers[i - 1], 2);
    }
}

const char EMPTY = 'X';

vector<int> CalcDp(int n, int k, const string& s, char c, char r) {
    vector<int> cSum(n, 0);
    vector<int> eSum(n, 0);
    cSum[0] = (s[0] == c);
    eSum[0] = (s[0] == EMPTY);
    for (int i = 1; i < n; ++i) {
        cSum[i] = cSum[i - 1] + (s[i] == c);
        eSum[i] = eSum[i - 1] + (s[i] == EMPTY);
    }

    auto getSum = [] (const vector<int>& sum, int l, int r) {
        return (l == 0 ? sum[r] : sum[r] - sum[l - 1]);
    };

    vector<int> result(n, 0);
    vector<int> notResult(n, 0);

    if (k == 1) {
        result[0] = (s[0] == c || s[0] == EMPTY ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            result[i] = (s[i] == c || s[i] == EMPTY ? 1 : 0);

            ModMul(result[i], (cSum[i - 1] == 0));
        }
        notResult[0] = (s[0] != c);
        for (int i = 1; i < n; ++i) {
            notResult[i] = (s[i] != c) * notResult[i - 1];
        }
        if (r == 'y') {
            return result;
        } else {
            return notResult;
        }
    }

    notResult[0] = (s[0] == EMPTY ? 2 : 1);
    for (int i = 1; i + 1 < k; ++i) {
        notResult[i] = notResult[i - 1];
        ModMul(notResult[i], (s[i] == EMPTY ? 2 : 1));
    }
    for (int i = 0; i + 1 < k; ++i) {
        result[i] = 0;
    }

    int lastNotCId = -1;
    for (int i = 0; i + 1 < k; ++i) {
        if (s[i] != EMPTY && s[i] != c) {
            lastNotCId = i;
        }
    }

    vector<int> vals(n);
    for (int i = 0; i + 1 < k; ++i) {
        vals[i] = (s[i] != c) * (i == 0 ? 1 : notResult[i - 1]);
    }

    vector<int> valsSum(n);
    valsSum[0] = vals[0];
    for (int i = 1; i + 1 < k; ++i) {
        valsSum[i] = valsSum[i - 1];
        ModSum(valsSum[i], vals[i]);
    }

    auto getModSum = [] (const vector<int>& modSum, int l, int r) {
        if (l == 0) {
            return modSum[r];
        } else {
            int result = modSum[r];
            result -= modSum[l - 1];
            if (result < 0) {
                result += MOD;
            }
            return result;
        }
    };

    for (int i = k - 1; i < n; ++i) {
        int curCSum = getSum(cSum, i - k + 1, i);
        int curESum = getSum(eSum, i - k + 1, i);

        if (curCSum + curESum == k) {
            if (i == k - 1) {
                result[i] = 1;
            } else {
                if (s[i - k] == c) {
                    result[i] = 0;
                } else {
                    result[i] = (i == k ? 1 : notResult[i - (k + 1)]);
                }
            }
        } else {
            result[i] = 0;
        }

        if (s[i] != EMPTY && s[i] != c) {
            lastNotCId = i;
        }

        vals[i] = (s[i] != c) * notResult[i - 1];
        valsSum[i] = valsSum[i - 1];
        ModSum(valsSum[i], vals[i]);

        int lf = max(i - k + 1, lastNotCId);
        int rg = i;

        if (lf <= rg) {
            notResult[i] = getModSum(valsSum, lf, rg);
        } else {
            notResult[i] = 0;
        }
    }

    if (r == 'y') {
        return result;
    } else {
        return notResult;
    }
}

int main() {
    BuildPowers();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> dpLeft = CalcDp(n, k, s, 'B', 'y');

    reverse(s.begin(), s.end());
    vector<int> dpRight = CalcDp(n, k, s, 'W', 'n');
    reverse(dpRight.begin(), dpRight.end());
    reverse(s.begin(), s.end());

    int result = 0;
    {
        int eCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == EMPTY) {
                ++eCount;
            }
            dpRight[i] = powers[eCount] - dpRight[i];
            if (dpRight[i] < 0) {
                dpRight[i] += MOD;
            }
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        ModSum(result, GetModMul(dpLeft[i], dpRight[i + 1]));
    }

    cout << result << endl;

    return 0;
}