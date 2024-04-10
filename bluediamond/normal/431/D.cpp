#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll comb[100][100];

int get(ll x) {
  if (x == 0) {
    return 0;
  } else {
    return x % 2 + get(x / 2);
  }
}

ll brute(ll num, int k) {
  ll sol = 0;
  for (ll x = 1; x <= num; x++) {
    sol += (get(x) == k);
  }
  return sol;
}

ll cnt(ll num, int k) { /// how many numbers have k bits in 1...num
  if (num == 0 || k == 0) {
    return 0;
  }
  vector<int> b;
  while (num) {
    b.push_back(num % 2);
    num /= 2;
  }
  reverse(b.begin(), b.end());
  int l = (int) b.size();
  ll sol = 0;
  for (int pre = 0; pre <= l; pre++) {
    if (pre > 0) {
      k -= b[pre - 1];
    }
    if (k < 0) {
      break;
    }
    if (pre == l) {
      sol += (k == 0);
      continue;
    }
    if (b[pre] == 0) {
      continue;
    }
    int rem = l - pre - 1;
    sol += comb[rem][k];
  }
  return sol;
}

ll f(ll x, ll k) {
  return cnt(2 * x, k) - cnt(x, k);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 100; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    }
  }
  ll w, l = 1, r = (ll) 1e18;
  int k;
  cin >> w >> k;
  while (l <= r) {
    ll m = (l + r) / 2;
    ll val = f(m, k);
    if (val == w) {
      cout << m << "\n";
      return 0;
    }
    if (val > w) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
}