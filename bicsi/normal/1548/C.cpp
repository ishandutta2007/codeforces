#include <bits/stdc++.h>

using namespace std;

const vector<int> P = {1, 3, 3, 1};

const int MOD = 1e9 + 7; 
struct ModInt {
  int x;
  ModInt(int x = 0) : x(x + (x < 0) * MOD - (x >= MOD) * MOD){}
  ModInt operator+(ModInt o) { return x + o.x; }
  ModInt operator-(ModInt o) { return x - o.x; }
  ModInt operator*(ModInt o) { return 1LL * x * o.x % MOD; }
  ModInt operator/(ModInt b) { return *this * b.inv(); }
  ModInt inv() { return pow(MOD - 2); }
  ModInt pow(long long e) {
    if (!e) return 1;
    ModInt r = pow(e / 2); r = r * r;
    return e % 2 ? *this * r : r;
  }
  bool operator==(ModInt o) { return x == o.x; }
  int get() { return x; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  const int sz = 3 * n + 8;
  
  vector<ModInt> fact(sz, 1), ifact(fact);
  for (int i = 1; i < sz; ++i)
    fact[i] = fact[i - 1] * i;
  ifact.back() = fact.back().inv();
  for (int i = sz - 1; i >= 1; --i) {
    assert(ifact[i] * fact[i] == 1);
    ifact[i - 1] = ifact[i] * i;
  }

  auto choose = [&](int n, int k) {
    if (k < 0 || k > n) return ModInt(0);
    return fact[n] * ifact[k] * ifact[n - k];
  };
  
  vector<ModInt> P(sz);
  for (int i = 1; i < sz; ++i) {
    P[i - 1] = choose(3 * n + 3, i);
  }

  vector<ModInt> Q = {3, 3, 1};

  vector<ModInt> R;
  for (int i = sz - 1; i >= 3; --i) {
    ModInt coef = P[i];
    R.push_back(coef);
    for (int j = 0; j < 3; ++j) {
      P[i - j] = P[i - j] - *(Q.rbegin() + j) * coef;
    }
  }
  reverse(R.begin(), R.end());

  int q; cin >> q;
  while (q--) {
    int x; cin >> x;
    cout << R[x - 1].get() << '\n';
  }

  return 0;
}