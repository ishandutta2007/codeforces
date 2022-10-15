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

class linearSieve { /// linear Sieve
public:
  vector<int> primes;
  vector<int> lp;
  void put(int Limit) {
    primes.clear();
    lp.clear();
    lp.resize(Limit + 1, 0);
    for (int i = 2; i <= Limit; i++) {
      if (!lp[i]) {
        lp[i] = i;
        primes.push_back(i);
      }
      for (int j = 0; j < (int) primes.size() && primes[j] * i <= Limit && primes[j] <= lp[i]; j++) {
        lp[primes[j] * i] = primes[j];
      }
    }
  }
} user;

const int N = (int) 1e5 + 7;
const int K = 20;
int n, lg[N], q, tab[K][N], a[N], pos[N];
vector<int> posi[N];

int get(int l, int r) {
  int k = lg[r - l + 1];

}

void place(int i, int x) {
  while (x > 1) {
    int p = user.lp[x];
    while (x % p == 0) x /= p;
    posi[p].push_back(i);
  }
}

signed realMain() {
  for (int i = 2; i < N; i++) lg[i] = 1 + lg[i / 2];
  user.put(N);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[i] = n;
    place(i, a[i]);
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j + 1 < (int) posi[i].size(); j++) {
      pos[posi[i][j]] = min(pos[posi[i][j]], posi[i][j + 1] - 1);
    }
  }
  for (int i = n - 1; i >= 1; i--) pos[i] = min(pos[i], pos[i + 1]);
  for (int i = 1; i <= n; i++) {
    tab[0][i] = pos[i] + 1;
  }
  for (int k = 1; (1 << k) <= n; k++) {
    for (int i = 1; i <= n; i++) {
      if (tab[k - 1][i]) {
        tab[k][i] = tab[k - 1][tab[k - 1][i]];
      }
    }
  }
  while (q--) {
    int l, r, sol = 0;
    cin >> l >> r;
    for (int k = K - 1; k >= 0; k--) {
      if (tab[k][l] && tab[k][l] <= r) {
        sol += (1 << k);
        l = tab[k][l];
      }
    }
    cout << sol + 1 << "\n";
  }
  return 0;
}