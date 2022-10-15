#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

const int N = (int)5e5 + 7;
const ll inf = (ll)1e18 + 7;
int n;
int q;
ll pref[4][N], ff[N], ss[N];

struct Segment {
  int l;
  int r;
  ll pay;
  ll dp;
};

bool operator < (Segment a, Segment b) {
  return a.r < b.r;
}


struct T1 {
  ll best = -inf;
  ll mx1 = -inf;
  ll mx2 = -inf;
  T1() {}
  T1(ll best, ll mx1, ll mx2) :best(best), mx1(mx1), mx2(mx2) {}
};

T1 operator + (T1 a, T1 b) {
  ll best = max(a.mx1 + b.mx2, max(a.best, b.best));
  ll mx1 = max(a.mx1, b.mx1);
  ll mx2 = max(a.mx2, b.mx2);
  return { best, mx1, mx2 };
}

T1 t1[4 * N];

void build1(int v, int tl, int tr) {
  if (tl == tr) {
    t1[v] = { ff[tl] + ss[tl],ff[tl],ss[tl] };
  }
  else {
    int tm = (tl + tr) / 2;
    build1(2 * v, tl, tm);
    build1(2 * v + 1, tm + 1, tr);
    t1[v] = t1[2 * v] + t1[2 * v + 1];
  }
}

T1 get1(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl)return T1();
  if (l <= tl && tr <= r) {
    return t1[v];
  }
  int tm = (tl + tr) / 2;
  return get1(2 * v, tl, tm, l, r) + get1(2 * v + 1, tm + 1, tr, l, r);
}

ll t2[4 * N];

void upd2(int v, int tl, int tr, int i, ll x) {
  if (tr < i || i < tl)return;
  if (tl == tr) {
    assert(tl == i);
    t2[v] = max(t2[v], x);
    return;
  }
  int tm = (tl + tr) / 2;
  upd2(2 * v, tl, tm, i, x);
  upd2(2 * v + 1, tm + 1, tr, i, x);
  t2[v] = max(t2[2 * v], t2[2 * v + 1]);
}

ll get2(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl)return -inf;
  if (l <= tl && tr <= r)return t2[v];
  int tm = (tl + tr) / 2;
  return max(get2(2 * v, tl, tm, l, r), get2(2 * v + 1, tm + 1, tr, l, r));
}

ll t3[4 * N];

void build3(int v, int tl, int tr) {
  if (tl == tr) {
    t3[v] = ff[tl];
  }
  else {
    int tm = (tl + tr) / 2;
    build3(2 * v, tl, tm);
    build3(2 * v + 1, tm + 1, tr);
    t3[v] = max(t3[2 * v], t3[2 * v + 1]);
  }
}

ll get3(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl)return -inf;
  if (l <= tl && tr <= r)return t3[v];
  int tm = (tl + tr) / 2;
  return max(get3(2 * v, tl, tm, l, r), get3(2 * v + 1, tm + 1, tr, l, r));
}



struct Node {
  ll mx_a = -inf;
  ll mx_b = -inf;
  ll mx = -inf;
  Node() {}
  Node(ll mx_a, ll mx_b, ll mx) :mx_a(mx_a), mx_b(mx_b), mx(mx) {}
};

Node operator + (Node a, Node b) {
  return { max(a.mx_a,b.mx_a),max(a.mx_b,b.mx_b),max(a.mx,b.mx) };
}

Node t[4 * N];
ll what[4 * N];

void push(int v, int tl, int tr) {
  if (what[v] != -inf) {
    t[v].mx_a = what[v];
    t[v].mx = what[v] + t[v].mx_b;
    if (tl < tr) {
      what[2 * v] = what[2 * v + 1] = what[v];
    }
    what[v] = -inf;
  }
}

void upd_a(int v, int tl, int tr, int l, int r, ll x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    what[v] = x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  upd_a(2 * v, tl, tm, l, r, x);
  upd_a(2 * v + 1, tm + 1, tr, l, r, x);
  t[v] = t[2 * v] + t[2 * v + 1];
}

void upd_b(int v, int tl, int tr, int i, ll x) {
  push(v, tl, tr);
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    assert(tl == i);
    t[v].mx_b = max(t[v].mx_b, x);
    t[v].mx = t[v].mx_b + t[v].mx_a;
    return;
  }
  int tm = (tl + tr) / 2;
  upd_b(2 * v, tl, tm, i, x);
  upd_b(2 * v + 1, tm + 1, tr, i, x);
  t[v] = t[2 * v] + t[2 * v + 1];
}

Node get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl)return Node();
  if (l <= tl && tr <= r)return t[v];
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  for (int i = 0; i < 4 * N; i++)what[i] = -inf;


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  for (int i = 0; i < 4 * N; i++)t2[i] = t3[i] = -inf;
  cin >> n >> q;

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> pref[i][j];
      pref[i][j] += pref[i][j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    ff[i] = (pref[1][i] - pref[2][i - 1]);
    ss[i] = (pref[3][n] - pref[3][i - 1]) + pref[2][i];
  }

  vector<Segment> segs(q);
  for (auto& seg : segs) {
    cin >> seg.l >> seg.r >> seg.pay;
    seg.dp = -inf;
  }
  sort(segs.begin(), segs.end());
  build1(1, 1, n);
  build3(1, 1, n);
  ll sol = -inf;

  int current = 0;
  vector<int> stk;

  for (int i = 0; i < q; i++) {
    /// directly
    int l = segs[i].l, r = segs[i].r;
    ll pay = segs[i].pay;
    sol = max(sol, get1(1, 1, n, l, r).best - pay);
    segs[i].dp = max(get2(1, 1, n, l - 1, r), get3(1, 1, n, l, r)) - pay;
    upd2(1, 1, n, r, segs[i].dp);

    while (current < r) {
      current++;
      while (!stk.empty() && ss[stk.back()] <= ss[current]) {
        stk.pop_back();
      }
      int from = (stk.empty()) ? 1 : (stk.back() + 1);
      upd_a(1, 1, n, from, n, ss[current]);
      stk.push_back(current);
    }

    sol = max(sol, get(1, 1, n, max(l - l + 1, l - 1), r).mx - pay);

    upd_b(1, 1, n, r, segs[i].dp);
  }
  cout << sol << "\n";
}