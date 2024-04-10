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
signed realMain();

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
}

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

const int N = (int) 2e5 + 7;
int n, a[N], mx[N];
int len[N], cnt[N];
bool good[N];
vector<int> where[N];

void dfs(int a) {
  if (!good[a] || len[a]) {
    return;
  }
  dfs((a + 1) % n);
  len[a] = len[(a + 1) % n] + 1;
}

signed realMain() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    where[__gcd(i, n)].push_back(i);
  }
  ll ret = 0;
  for (int g = 1; g < n; g++) {
    if (n % g) {
      continue;
    }
    for (int i = 0; i < g; i++) {
      mx[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      mx[i % g] = max(mx[i % g], a[i]);
    }
    bool all = 1;
    for (int i = 0; i < n; i++) {
      good[i] = (a[i] == mx[i % g]);
      all &= good[i];
      len[i] = 0;
    }
    if (all) {
      ret += (ll) (int) where[g].size() * n;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      assert(cnt[i] == 0);
    }
    for (int i = 0; i < n; i++) {
      dfs(i);
      cnt[len[i]]++;
    }
    int y = 0;
    for (int i = 1; i <= n; i++) {
      while (cnt[i] > 0) {
        len[y++] = i;
        cnt[i]--;
      }
    }
    int piv = 0;
    for (auto &ln : where[g]) {
      while (piv < y && len[piv] < ln) {
        piv++;
      }
      if (piv >= y) {
        break;
      }
      ret += y - piv;
    }
  }
  cout << ret << "\n";
  return 0;
}