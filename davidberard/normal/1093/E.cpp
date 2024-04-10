#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/**
 * 1093E - Intersection of Permutation
 * Idea:
 * 1. Convert the queries. Rename a_1 -> 1, a_2 -> 2, etc. in both a and b.
 *    Now a query (la, ra, lb, rb) is actually the query, 
 *        "In b[lb, rb], how many elemets have value in [la, ra]?"
 *    And swap(b[x], b[y]) is the same as before, just swap b[x], b[u].
 *
 * 2. Perform the queries: we can do this with a 2d segtree which stores:
 *    If b[i] = x, then st[i][x] = 1.
 *    Now queries (la, ra, lb, rb) are rectangle sums of st[lb..rb][la..ra].
 * Each query adds log^2 data.
 **/

struct Segtree {
  ordered_set<int> st;
  Segtree (int sz) {
  }
  void add(int i, int v) {
    if (v == 1) {
      st.insert(i);
    } else if (v == -1) {
      st.erase(i);
    }
  }
  int query(int l, int r) {
    --r;
    auto v = st.lower_bound(l);
    auto w = st.upper_bound(r);
    if (v == st.end()) {
      return 0;
    }
    if (w == st.begin()) {
      return 0;
    }
    return st.order_of_key(*prev(w))-st.order_of_key(*v) + 1;
  }
};

struct Segtree2D {
  vector<Segtree> t;
  int n, h;
  Segtree2D (int sz, int m) {
    t = vector<Segtree>(sz+1, m);
  }
  void add(int x, int mx, int v) {
    for (; x<t.size(); x+=x&-x) {
      t[x].add(mx, v);
    }
  }
  int query(int x, int lx, int rx) {
    int ans = 0;
    for (; x; x-=x&-x) {
      ans += t[x].query(lx, rx);
    }
    return ans;
  }
  int query(int l, int r, int lx, int rx) {
    int ans = query(r-1, lx, rx) - query(l-1, lx, rx);
    return ans;
  }
};

const int N = 200200;
int n, m;
int a[N], b[N], reva[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    reva[a[i]] = i;
  }
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
    b[i] = reva[b[i]];
  }
  Segtree2D st(n+1, n+1);
  for (int i=1; i<=n; ++i) {
    st.add(i, b[i], 1);
  }
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      cout << st.query(lb, rb+1, la, ra+1) << "\n";
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      st.add(x, b[x], -1);
      st.add(y, b[y], -1);
      swap(b[x], b[y]);
      st.add(x, b[x], 1);
      st.add(y, b[y], 1);
    }
  }
  return 0;
}