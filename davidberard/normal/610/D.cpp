#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

// start: 18:22

struct Node {
  int l, r;
  int lv, rv;
  int val;
};

struct Segtree {
  Node d[101000*64];
  int zz = 1;
  int n, h;
  Segtree() {
    //memset(d, 0, sizeof d);
    d[1] = {0, 0, -(1<<30), (1<<30), 0};
  }
  int query(int l, int r, int x) {
    if (!x) return 0;
    if (d[x].rv <= l || r <= d[x].lv) return 0;
    //cerr << " L R " << l << " " << r << " Q " << x << "  : " << d[x].val << endl;
    if (l <= d[x].lv && d[x].rv <= r) {
      return d[x].val;
    }
    return query(l, r, d[x].l)+query(l, r, d[x].r);
  }
  int query(int l, int r) {
    return query(l, r, 1);
  }
  void add(int p, int v, int x) {
    assert(x);
    if (d[x].rv <= p || p < d[x].lv) return;
    if (!d[x].l && (ll) d[x].rv-d[x].lv > 1) {
      d[x].l = ++zz;
      d[x].r = ++zz;
      d[d[x].l].lv = d[x].lv;
      d[d[x].l].rv = d[d[x].r].lv = (d[x].lv+d[x].rv)/2;
      d[d[x].r].rv = d[x].rv;
    }
    d[x].val += v;
    ////cerr << "  : " << x << " += " << v << " , " << d[x].rv-d[x].lv << endl;
    if ((ll) d[x].rv-d[x].lv > 1) {
      ////cerr << " PROP " << endl;
      add(p, v, d[x].l);
      add(p, v, d[x].r);
    }
  }
  void add(int p, int v) {
    add(p, v, 1);
  }
};

const int VERTICAL   = 1;
const int HORIZONTAL = 2;

struct Query {
  int type, y, x1, x2, dir;
  bool operator < (const Query& o) const {
    if (y == o.y) {
      return type < o.type;
    }
    return y < o.y;
  }
};

Segtree st;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  ll total = 0;
  vector<Query> queries;
  map<int, vector<pii>> vmap, hmap;

  for (int i=1; i<=n; ++i) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int x1 = min(xa, xb);
    int x2 = max(xa, xb);
    int y1 = min(ya, yb);
    int y2 = max(ya, yb);

    if (x1 == x2) {
      // VERTICAL;
      vmap[x1].emplace_back(y1, y2+1);
    } else if (y1 == y2) {
      hmap[y1].emplace_back(x1, x2+1);
    }
  }
  
  vector<pii> u;
  for (auto& pp : vmap) {
    auto& v = pp.second;
    sort(v.begin(), v.end());
    u.clear();
    for (auto& x : v) {
      if (!u.empty() && u.back().second >= x.first) {
        u.back().second = max(u.back().second, x.second);
      } else {
        u.push_back(x);
      }
    }
    for (auto& x : u) {
      //cerr << " : " << x.first << " " << x.second << " at x=" << pp.first << endl;
      total += x.second-x.first;
      Query q;
      q.type = VERTICAL;
      q.x1 = pp.first;

      q.y = x.first;
      q.dir = 1;
      queries.push_back(q);

      q.y = x.second;
      q.dir = -1;
      queries.push_back(q);

    }
  }

  for (auto& pp : hmap) {
    auto& v = pp.second;
    sort(v.begin(), v.end());
    u.clear();
    for (auto& x : v) {
      if (!u.empty() && u.back().second >= x.first) {
        u.back().second = max(u.back().second, x.second);
      } else {
        u.push_back(x);
      }
    }
    for (auto& x : u) {
      //cerr << " : " << x.first << " " << x.second << " at y=" << pp.first << endl;
      total += (ll) x.second-x.first;
      Query q;
      q.type = HORIZONTAL;
      q.y = pp.first;
      q.x1 = x.first;
      q.x2 = x.second;
      queries.push_back(q);
    }
  }

  //cerr << "  BASIS " << total << endl;

  sort(queries.begin(), queries.end());

  for (auto& q : queries) {
    if (q.type == HORIZONTAL) {
      total -= st.query(q.x1, q.x2);
      //cerr << " H: " << q.x1 << " " << q.x2 << " -> " << st.query(q.x1, q.x2) << endl;
    } else if (q.type == VERTICAL) {
      st.add(q.x1, q.dir);
      //cerr << " V: " << q.x1 << " + " << q.dir << endl;
    }
  }

  cout << total << "\n";

  return 0;
}