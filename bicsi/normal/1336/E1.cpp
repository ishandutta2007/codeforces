#include <bits/stdc++.h>

using namespace std;


int get(long long val) {
  return __builtin_popcountll(val);
}
  
const int kMod = 998244353;

void Mod(int& a) {
  while (a >= kMod) a -= kMod;
  while (a < 0) a += kMod;
}

int main() {
  int n, m; cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  vector<int> piv(m, -1);

  int ptr = 0;
  for (int bit = 0; bit < m && ptr < n; ++bit) {
    for (int i = ptr; i < n; ++i) {
      if (a[i] & (1LL << bit)) {
        swap(a[i], a[ptr]);
      }
    }
    if (a[ptr] & (1LL << bit)) {
      piv[bit] = ptr;
      for (int j = 0; j < n; ++j) {
        if (j == ptr) continue;
        if (a[j] & (1LL << bit)) {
          a[j] ^= a[ptr];
        }
      }
      ++ptr;
    }
  }
    
  int coef = 1;
  for (int i = ptr; i < n; ++i) {
    Mod(coef += coef);
  }

  // cerr << "COEF: " << coef << endl;

  vector<int> cnt(m + 1, 0);

  n = ptr;
  a.resize(n);
  /*
  for (int i = 0; i < n; ++i) {
    cerr << a[i] << " ";
  }
  cerr << endl;
  */
  if (n <= 20) {
    // cerr << "Brute" << endl;
    for (int msk = 0; msk < (1 << n); ++msk) {
      long long val = 0;
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i))
          val ^= a[i];
      }
      cnt[get(val)] += 1;
    }
  } else {
    // cerr << "DP" << endl;
    int idx = 0;
    vector<int> remap(m, -1);
    for (int i = 0; i < m; ++i) {
      if (piv[i] != -1) continue;
      remap[i] = idx++;
    }
    assert(idx <= 20);

    vector<vector<int>> dp(1 << idx, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
      int msk = 0;
      for (int j = 0; j < m; ++j) {
        if (remap[j] == -1) continue;
        if (a[i] & (1LL << j)) msk |= (1 << remap[j]);
      }
      
      for (int k = i; k >= 0; --k) {
        for (int j = 0; j < (1 << idx); ++j) {
          Mod(dp[j ^ msk][k + 1] += dp[j][k]);
        }
      } 
    }

    for (int i = 0; i <= n; ++i) {
      for (int msk = 0; msk < (1 << idx); ++msk) {
        Mod(cnt[get(msk) + i] += dp[msk][i]);
      }
    }
  }

  for (int i = 0; i <= m; ++i) {
    cout << (1LL * cnt[i] * coef) % kMod << " ";
  }
  cout << endl;
  
  return 0;
}