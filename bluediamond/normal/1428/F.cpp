#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 5e5 + 7;
int n;
int a[N];
string s;
ll sol;

int cur1[N];
int mx1[N];
int suf[N];
bool grow[N];

int cur2[N];
int mx2[N];
int pre[N];

struct T {
  int tree[N];
  ll ss[N];
  ll tot;
  T() {
    tot = 0;
    for (int i = 0; i < N; i++) {
      tree[i] = 0;
      ss[i] = 0;
    }
  }

  void add(int i) {
    int val = i;
    tot += val;
    i++;
    while (i <= n + 2) {
      tree[i]++;
      ss[i] += val;
      i += i & (-i);
    }
  }

  void del(int i) {
    int val = i;
    tot -= val;
    i++;
    while (i <= n + 2) {
      tree[i]--;
      ss[i] -= val;
      i += i & (-i);
    }
  }

  int cnt(int i) {
    i++;
    int sol = 0;
    while (i) {
      sol += tree[i];
      i -= i & (-i);
    }
    return sol;
  }

  ll sum(int i) {
    i++;
    ll sol = 0;
    while (i) {
      sol += ss[i];
      i -= i & (-i);
    }
    return sol;
  }

};

T t1;
T t2;

void solve(int l, int r) {
  if (l == r) {
    sol += a[l];
    return;
  }
  int m = (l + r) / 2;
  solve(l, m);
  solve(m + 1, r);
  int cur = 0, mx = 0, bg = 0, zero = 0;
  for (int i = m; i >= l; i--) {
    if (a[i]) {
      cur++;
    } else {
      cur = 0;
      zero = 1;
    }
    bg += (zero == 0);
    grow[i] = (zero == 0);
    mx = max(mx, cur);
    cur1[i] = cur;
    mx1[i] = mx;
    suf[i] = bg;
  }
  cur = mx = bg = zero = 0;
  for (int i = m + 1; i <= r; i++) {
    if (a[i]) {
      cur++;
    } else {
      cur = 0;
      zero = 1;
    }
    bg += (zero == 0);
    mx = max(mx, cur);
    cur2[i] = cur;
    mx2[i] = mx;
    pre[i] = bg;
  }
  vector<pair<int, int>> lol;
  for (int j = m + 1; j <= r; j++) {
    lol.push_back({mx2[j] - pre[j], j});
    t1.add(mx2[j]);
  }
  sort(lol.rbegin(), lol.rend());
  int lol2 = 0;
  for (int i = m; i >= l; i--) {
    while (!lol.empty() && suf[i] >= lol.back().first) {
      int j = lol.back().second;
      lol2++;
      t1.del(mx2[j]);
      t2.add(pre[j]);
      lol.pop_back();
    }
    sol += (ll) suf[i] * lol2;
    sol += t2.tot;
    if (mx1[i] - suf[i] - 1 >= 0) {
      sol += (ll) (mx1[i] - suf[i]) * t2.cnt(mx1[i] - suf[i] - 1);
      sol -= t2.sum(mx1[i] - suf[i] - 1);
    }
    sol += (ll) mx1[i] * t1.cnt(mx1[i] - 1);
    sol -= t1.sum(mx1[i] - 1);
    sol += t1.tot;
  }
  for (auto &it : lol) {
    int j = it.second;
    t1.del(mx2[j]);
    t2.add(pre[j]);
  }
  for (int j = m + 1; j <= r; j++) {
    t2.del(pre[j]);
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - '0';
  }
  solve(1, n);
  cout << sol << "\n";
}