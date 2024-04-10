#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMod = 998244353;

vector<int> Calc(vector<bool> obs, int dim) {
    int n = obs.size();
    vector<vector<int>> dp(n + 1, vector<int>(dim + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        if (i > 0 && obs[i] == false && obs[i - 1] == false) {
            for (int j = 0; j < dim; ++j) {
                dp[i + 1][j + 1] += dp[i - 1][j];
                if (dp[i + 1][j + 1] >= kMod)
                    dp[i + 1][j + 1] -= kMod;
            }
        }
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n; cin >> h >> w >> n;
    vector<bool> obsl(h, false), obsr(w, false);
    int tl = 0, tr = 0;

    for (int i = 0; i < n; ++i) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; 
        --r1; --c1; --r2; --c2;
        obsl[r1] = obsl[r2] = obsr[c1] = obsr[c2] = true;
    }
    
    for (auto x : obsl)
        if (x == false)
            tl += 1;
    for (auto x : obsr)
        if (x == false)
            tr += 1;

    int maxx = max(h, w);
    
    vector<vector<int>> bino(maxx + 1, vector<int>(maxx + 1, 0));
    for (int i = 0; i <= maxx; ++i) {
        bino[i][i] = bino[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            bino[i][j] = bino[i - 1][j] + bino[i - 1][j - 1];
            if (bino[i][j] >= kMod)
                bino[i][j] -= kMod;
        }
    }

    vector<int> fact(maxx + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= maxx; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % kMod;
    }
    
    int ans = 0;
    auto dpl = Calc(obsl, maxx), dpr = Calc(obsr, maxx);
    for (int l = 0; l <= maxx; ++l) {
        for (int r = 0; r <= maxx; ++r) {
            if (tl - 2 * l < r || tr - 2 * r < l) continue;
            int coef = 1LL * bino[tl - 2 * l][r] * bino[tr - 2 * r][l] % kMod;
            coef = 1LL * coef * dpl[l] % kMod;
            coef = 1LL * coef * dpr[r] % kMod;
            coef = 1LL * coef * fact[l] % kMod;
            coef = 1LL * coef * fact[r] % kMod;
            ans += coef;
            if (ans >= kMod) 
                ans -= kMod;
        }
    }
    cout << ans << endl;

    return 0;
}