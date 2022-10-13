#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;

struct ModInt {
  long long n;
  
  ModInt(long long n = 0) : n(n % kMod) {}
  ModInt operator+(const ModInt& oth) { return n + oth.n; }
  ModInt operator-(const ModInt& oth) { return n - oth.n; }
  ModInt operator*(const ModInt& oth) { return n * oth.n; }
  long long get() { 
//      return n;
      return n < 0 ? n + kMod : n; 
  }
};

ModInt lgpow(ModInt b, int e) {
  ModInt r;
  for (r = 1; e; e /= 2, b = b * b)
    if (e % 2) r = r * b;
  return r;
}
ModInt inv(ModInt x) { 
    //return 1.0 / x.get();
    return lgpow(x, kMod - 2); 
}

ModInt operator/(ModInt a, ModInt b) { return a * inv(b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, a, b; ModInt pa, pb;
    cin >> k >> a >> b;
    
    pa = ModInt(a) / ModInt(a + b);
    pb = ModInt(b) / ModInt(a + b);
    
    vector<vector<ModInt>> dp(k + 1, vector<ModInt>(k + 1));
    dp[1][0] = 1;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            // pick a
            dp[i + 1][j] = dp[i + 1][j] + pa * (dp[i][j]);
            // pick b
            if (i + j < k)
                dp[i][j + i] = dp[i][j + i] + pb * (dp[i][j]);
        }
    }

    ModInt ans = k;
    ModInt magic = pa;
    magic = magic / (ModInt(1) - pa);
    

    for (int have = 0; have < k; ++have) {
        for (int as = 1; as <= k; ++as) {
            if (as < k) {
                int of = as + have - k;
                if (of < 0) continue;
                ans = ans + pb * of * dp[as][have];
            } else {
                ans = ans + dp[as][have] * (magic + have);
            }
        }
    }

    cout << ans.get() << endl;

    return 0;
}