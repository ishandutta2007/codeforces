#include <bits/stdc++.h>
using namespace std;

const int kFibSize = 86;
vector<long long> fib;

vector<int> GetRepr(long long n)
{
    vector<int> res(kFibSize);
    for (int i = kFibSize - 1; i >= 0; --i) {
        if (n >= fib[i]) {
            n -= fib[i];
            res[i] = 1;
        } else {
            res[i] = 0;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<vector<int> > dp(2, vector<int>(kFibSize));

long long GetAnswer(long long n)
{
    vector<int> r = GetRepr(n);
    dp[0].assign(kFibSize + 1, 0);
    dp[1].assign(kFibSize + 1, 0);
    dp[0][0] = 1;
    dp[1][0] = 0;
    for (int i = 0; i < kFibSize; ++i) {
        dp[0][i + 1] += dp[0][i];
        if (r[i] == 0) {
            dp[0][i + 1] += dp[1][i];
        }
        if (i + 2 < kFibSize && r[i + 1] == 0) {
            dp[1][i + 2] += dp[1][i];
            if (r[i] == 1) {
                dp[1][i + 2] += dp[0][i];
            }
        }
    }
    return dp[0][kFibSize];
}

int main()
{
    ios_base::sync_with_stdio(false);

    fib.push_back(1);
    fib.push_back(2);
    for (int i = 2; i < kFibSize; ++i) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        long long n;
        cin >> n;
        cout << GetAnswer(n) << endl;
    }

    return 0;
}