#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

/**
 * Strategy:
 *  for points x1, x2, ... where xi < x(i+1)..
 *  we want the sum of following queries:
 *    - how many intervals start before x1 and end after
 *    - how many intervals start between xi and x(i+1), and end after x(i+1)
 *
 *  "how many intervals start between xi and x(i+1), and end after x(i+1)" ==
 *    - add how many intervals start before x(i+1) and end after
 *    - subtract how many intervals start before x(i) and end after x(i+1)
 *
 * code start 18:05
 */

const int SEG = 1;
const int QUERY = 2;

struct Query {
  int ind, dir, l, r, type;
  bool operator< (const Query& o) const {
    if (l == o.l) {
      return type < o.type;
    }
    return l < o.l;
  }
};

const int N = 300300;
int ans[N];

struct BIT {
  vector<ll> t;
  int n;
  BIT(int sz) {
    n = sz;
    t = vector<ll>(n);
  }
  void add(int x, ll v) {
    for (; x<n; x+=x&-x) {
      t[x] += v;
    }
  }
  // [l, r)
  void add(int l, int r, ll v) {
    add(l, v);
    add(r, -v);
  }
  ll query(int x) {
    ll ans = 0;
    for (; x; x-=x&-x) {
      ans += t[x];
    }
    return ans;
  }
};

int n, m;

BIT bit(1100000);
int p[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  vector<Query> queries;
  for (int i=1; i<=n; ++i) {
    Query q;
    cin >> q.l >> q.r;
    q.type = SEG;
    q.r ++;
    queries.push_back(q);
  }
  for (int i=1; i<=m; ++i) {
    int k;
    cin >> k;
    for (int j=1; j<=k; ++j) {
      cin >> p[j];
    }

    Query q;
    q.type = QUERY;
    q.ind = i;

    q.l = p[1];
    q.r = p[1];
    q.dir = 1;
    queries.push_back(q);

    for (int j=1; j<k; ++j) {
      q.l = p[j];
      q.r = p[j+1];
      q.dir = -1;
      queries.push_back(q);

      q.l = p[j+1];
      q.r = p[j+1];
      q.dir = 1;
      queries.push_back(q);
    }
  }

  sort(queries.begin(), queries.end());

  for (auto& q : queries) {
    if (q.type == SEG) {
      bit.add(q.l, q.r, 1);
    } else if (q.type == QUERY) {
      ll v = bit.query(q.r);
      ans[q.ind] += v*q.dir;
      if (q.ind == 1) {
        //cerr << "  Q " << q.l << " " << q.r << " " << q.dir << " :: " << v << endl;
      }
    }
  }

  for (int i=1; i<=m; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}