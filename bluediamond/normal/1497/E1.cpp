#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 2e5 + 7;
const int K = 22;
const int L = (int) 1e7 + 7;
const int INF = (int) 1e9;
vector<int> primes;
int lp[L], f[L];
int n, k, a[N], t[L], dp[N][K];

void elon_musk() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = INF;
    }
  }
  vector<int> positions;
  positions.push_back(0);
  map<int, int> last;
  for (int i = 1; i <= n; i++) {
    if (last.count(a[i])) {
      positions.push_back(last[a[i]]);
      sort(positions.begin(), positions.end());
      reverse(positions.begin(), positions.end());
      while ((int) positions.size() > k + 1) {
        positions.pop_back();
      }
    }
    last[a[i]] = i;
    for (int p = (int) positions.size() - 1; p >= 0; p--) {
      int pay = (int) positions.size() - 1 - p;
      if (pay > k) {
        break;
      }
      for (int ant = 0; ant + pay <= k; ant++) {
        dp[i][ant + pay] = min(dp[i][ant + pay], dp[positions[p]][ant] + 1);
      }
    }
  }
 /** for (int i = 1; i <= n; i++) {
    int ant = 0;
    set<int> s;
    for (int j = i; j >= 1; j--) {
      s.insert(a[j]);
      int pay = i - j + 1 - (int) s.size();
      if (pay > k) {
        break;
      }
      for (int ant = 0; ant + pay <= k; ant++) {
        dp[i][ant + pay] = min(dp[i][ant + pay], dp[j - 1][ant] + 1);
      }
    }
  }**/
  if (!home) {
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      assert(dp[i - 1][j] <= dp[i][j]);
    }
  }
}

signed realMain() {
  for (int i = 2; i < L; i++) {
    if (!lp[i]) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i < L; j++) {
      lp[primes[j] * i] = primes[j];
    }
  }
  t[1] = 1;
  for (int i = 2; i < L; i++) {
    int val = t[i / lp[i]];
    if (val % lp[i] == 0) {
      t[i] = val / lp[i];
    } else {
      t[i] = val * lp[i];
    }
  }
  long long h = 0, p = 1;
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] = t[a[i]];
    }
    elon_musk();
    cout << dp[n][k] << "\n";
    h += dp[n][k] * p;
    p *= 33;
    h *= 666;
  }
  if (home) {
    cout << h << "\n";
    assert(h == 270672118251477210);
  }
}