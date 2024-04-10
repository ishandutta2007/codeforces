#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
ll inv[N];

struct T {
  pair<int, ll> t[N];
  T() {
    for (int i = 0; i < N; i++) {
      t[i].first = 0;
      t[i].second = 0;
    }
  }
  void add(int i, ll x) {
    while (i < N) {
      t[i].first++;
      t[i].second += x;
      i += i & (-i);
    }
  }
  void del(int i, ll x) {
    while (i < N) {
      t[i].first--;
      t[i].second -= x;
      i += i & (-i);
    }
  }
  int cnt(int i) {
    int sol = 0;
    while (i) {
      sol += t[i].first;
      i -= i & (-i);
    }
    return sol;
  }
  ll sum(int i) {
    ll sol = 0;
    while (i) {
      sol += t[i].second;
      i -= i & (-i);
    }
    return sol;
  }
  int cnt(int l, int r) {
    return cnt(r) - cnt(l - 1);
  }
  ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
  ll big(int x) {
    if (x <= 0) {
      return 0;
    }
    if (x > cnt(1, N - 1)) {
      cout << "error at big\n";
      exit(0);
    }
    int l = 1, r = N - 1, first;
    while (l <= r) {
      int m = (l + r) / 2;
      if (x > cnt(m, N - 1)) {
        first = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    int rem = x - cnt(first, N - 1);
    return (ll) inv[first - 1] * rem + sum(first, N - 1);
  }
};

T all;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ops(n);
  map<int, int> tr;
  for (int i = 0; i < n; i++) {
    cin >> ops[i].first >> ops[i].second;
    tr[abs(ops[i].second)] = 0;
  }
  int cur = 0;
  for (auto &it : tr) {
    it.second = ++cur;
    inv[cur] = it.first;
  }
  ll tot = 0;
  int cn = 0, cs = 0;
  multiset<ll> sp, no;
  for (auto &it : ops) {
    int type = it.first, x = it.second;
    tot += x;
    if (x > 0) {
      all.add(tr[x], x);
    } else {
      all.del(tr[-x], -x);
    }
    if (type == 0) { /// normal
      if (x > 0) {
        cn++;
        no.insert(x);
      } else {
        cn--;
        no.erase(no.find(-x));
      }
    } else { /// special
      if (x > 0) {
        cs++;
        sp.insert(x);
      } else {
        cs--;
        sp.erase(sp.find(-x));
      }
    }
    if ((int) no.size() != cn || (int) sp.size() != cs) {
      cout << "error sz\n";
      exit(0);
    }
    ll e = 0;
    if (cs) {
      if (cn == 0) {
        e = all.big(cs - 1);
      } else {
        /// if all mx norm <= mn spec
        auto mx = no.end();
        mx--;
        auto mn = sp.begin();
        if (*mx <= *mn) {
          e = *mx + all.big(cs - 1);
        } else {
          e = all.big(cs);
        }
      }
    }
    cout << tot + e << "\n";
  }
  return 0;
}
/**

**/