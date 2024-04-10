#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 1000;
int n, DP[mx];
ll a[mx], fact[mx], C[mx][mx], dp[mx][mx];
bool lst[mx];

ll binsearch(ll l, ll r, ll k) {
    if (l == r) return l;
    ll mid = (l + r) / 2;
    if (mid * mid < k) return binsearch(mid+1, r, k);
    else return binsearch(l, mid, k);
}

bool square(ll x) {
    ll k = binsearch(0, 2e9, x);
    if (k * k == x)
        return 1;
    else
        return 0;
}

vector<int> cmp;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        DP[i] = 1;
        lst[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (square(a[i] * a[j])) {
                lst[j] = 0;
                DP[i] = DP[j] + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (lst[i])
            cmp.push_back(DP[i]);
    }
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    ll mult = 1;
    int cn = cmp.size();
    for (int i = 0; i < cn; ++i) {
        mult = (mult * fact[cmp[i]]) % MOD;
    }
    for (int i = 0; i < mx; ++i) {
        for (int j = 0; j < mx; ++j) {
            dp[i][j] = 0;
            if (j > i) {
                C[i][j] = 0;
                continue;
            }
            if (j == 0)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }
    dp[0][cmp[0] - 1] = 1;
    int total = 0;
    for (int i = 0; i < cn - 1; ++i) {
        int size = cmp[i+1];
        total += cmp[i];
        for (int j = 0; j <= total - 1; ++j) {
            for (int s = 1; s <= min(size, total+1); ++s) {
                for (int d = 0; d <= min(j, s); ++d) {
                    int T = dp[i][j];
                    T = (T * C[j][d]) % MOD;
                    T = (T * C[total+1-j][s-d]) % MOD;
                    T = (T * C[size-1][s-1]) % MOD;
                    dp[i+1][j-d+size-s] = (dp[i+1][j-d+size-s] + T) % MOD;
                }
            }
        }
    }
    cout << (dp[cn-1][0] * mult) % MOD;
    return 0;
}