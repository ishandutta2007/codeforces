#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int ctz(int x) {
  if (x == 0) {
    return 0;
  }
  return 32 - __builtin_clz(x);
}

const int N = 200200;
priority_queue<int, vector<int>, greater<int>> pq[31];
int n, q;
int a[N];

struct BIT {
  vector<ll> t;
  int n;
  BIT (int sz) {
    n = sz;
    t = vector<ll>(n);
  }
  void add(int x, ll v) {
    for (; x<n; x+=(x&-x)) {
      t[x] += v;
    }
  }
  ll query(int x) {
    ll ans = 0;
    for (; x; x-=(x&-x)) {
      ans += t[x];
    }
    return ans;
  }
};

BIT bit(1);

bool checkzero() {
  while (!pq[0].empty() && a[pq[0].top()] != 0) {
    pq[0].pop();
  }
  return (!pq[0].empty() && pq[0].top() == 1);
}

int check(int z) {
  int r[2] = {0, 0};
  while (!pq[z].empty() && !r[0]) {
    if (ctz(a[pq[z].top()]) != z) {
      pq[z].pop();
      continue;
    }

    r[0] = r[1];
    r[1] = pq[z].top();
    pq[z].pop();
  }
  int ans = 0;
  for (int i=0; i<2; ++i) {
    if (!r[i]) {
      continue;
    }
    int u = r[i];
    if (!ans && bit.query(u-1) == a[u]) {
      ans = u;
    }
    pq[z].push(u);
  }
  return ans;
}



int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  bit = BIT(n+10);
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    pq[ctz(a[i])].push(i);
    bit.add(i, a[i]);
  }
  while (q--) {
    int pi, xi;
    cin >> pi >> xi;
    bit.add(pi, xi-a[pi]);
    a[pi] = xi;
    pq[ctz(a[pi])].push(pi);
    int is_good = checkzero();
    for (int i=1; !is_good && i<31; ++i) {
      is_good = check(i);
    }
    cout << (is_good ? is_good : -1) << "\n";

  }
  return 0;
}