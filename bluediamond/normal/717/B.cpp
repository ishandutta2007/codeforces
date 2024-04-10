#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

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

map<int, int> cnt;
int n, c0, c1, zuc;

signed realMain() {
  cin >> n >> c0 >> c1;
  zuc = 1;
  cnt[0]++;
  while (zuc < n) {
    auto it = cnt.begin();
    int kolrabi = min(it->second, n - zuc);
    zuc += kolrabi;
    cnt[it->first + c0] += kolrabi;
    cnt[it->first + c1] += kolrabi;
    it->second -= kolrabi;
    if (!it->second) {
      cnt.erase(it);
    }
  }
  int zuk = 0;
  for (auto &it : cnt) {
    int taki = min(it.second, n);
    n -= taki;
    zuk += taki * it.first;
  }
  cout << zuk << "\n";

  return 0;
}