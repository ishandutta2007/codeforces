#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
//#define int ll
signed realMain();


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

const int N = (int) 1e7 + 7;
int n, lp[N], cnt, aib[N];
bool bad[N];
ll ret;

int get_phi(int i) {
  int ret = i;
  while (i > 1) {
    int d = lp[i];
    while (i % d == 0) {
      i /= d;
    }
    ret /= d;
    ret *= (d - 1);
  }
  return ret;
}

void add(int i) {
  while (i <= n) {
    aib[i]++;
    i += i & (-i);
  }
}

int pre(int i) {
  int ret = 0;
  while (i) {
    ret += aib[i];
    i -= i & (-i);
  }
  return ret;
}

signed realMain() {
  cin >> n;
  user.put(n);
  for (int i = 1; i <= n; i++) {
    lp[i] = user.lp[i];
    bad[i] = (i == 1 || (lp[i] == i && 2 * i > n));
  }
  add(1);
  for (int i = 2; i <= n; i++) {
    if (!bad[i]) {
      ret += get_phi(i) + 3 * ++cnt - i - 1 - pre(n / lp[i]);
    }
    add(lp[i]);
  }
  cout << ret << "\n";
  if (home && n == 999) {
    assert(ret == 679078);
  }
  return 0;
}