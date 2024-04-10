#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

void print(vector<int> v) {
  cout << (int) v.size() << "\n";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
  return;
}

vector<int> get(int n) {
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (__gcd(i, n) == 1) {
      v.push_back(i);
    }
  }
  sort(v.begin(), v.end());
  int prod = 1, idx = 0, last = -1;
  for (auto &x : v) {
    idx++;
    prod = prod * x % n;
    if (prod == 1) {
      last = idx;
    }
  }
  assert(last != -1);
  v.resize(last);
  return v;
}

int dumb(int n) {
  int best = 0;
  for (int m = 0; m < (1 << n); m++) {
    int prod = 1, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (m & (1 << i)) {
        cnt++;
        prod = prod * i % n;
      }
    }
    if (prod == 1) {
      best = max(best, cnt);
    }
  }
  return best;
}

signed realMain() {
  int n;
  cin >> n;
  print(get(n));
  return 0;
  for (int n = 2; n <= 20; n++) {
    cout << get(n).size() << " " << dumb(n) << "\n";
  }
  return 0;
}