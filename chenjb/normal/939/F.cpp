#include <bits/stdc++.h>

using namespace std;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool a) {
  return a ? "T" : "F";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;

#define mid ((l + r) >> 1)
#define lson (p << 1)
#define rson (p << 1 | 1)

const int N = 1e5 + 10, inf = 2e5 + 10, K = 110;

int n, k;
int l[K], r[K];

struct Seg {
  int tr[N * 2 * 4];
  void clear() {
    fill_n(tr, N * 2 * 4, inf);
  }

  void push_down(int p, int l, int r) {
    if (tr[p] != inf) {
      mini(tr[lson], tr[p]);
      mini(tr[rson], tr[p]);
      tr[p] = inf;
    }
  }

  void update(int p, int l, int r, int ll, int rr, int v) {
    debug(l, r, ll, rr);
    if (ll <= l && rr >= r) {
      mini(tr[p], v);
      return;
    }
    push_down(p, l, r);
    if (ll <= mid) update(lson, l, mid, ll, rr, v);
    if (rr >= mid + 1) update(rson, mid + 1, r, ll, rr, v);
  }

  int query(int p, int l, int r, int x) {
    debug(x);
    if (l == r) {
      return tr[p];
    }
    push_down(p, l, r);
    if (x <= mid) return query(lson, l, mid, x);
    return query(rson, mid + 1, r, x);
  }

} dp[2][2];

void chg(int &x) {
  if (x <= -n) x = -n;
  if (x >= n) x = n;
}

void run() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> l[i] >> r[i];
  }
  for (int i = 0; i < 2; ++i) dp[0][i].clear();
  
  dp[0][0].update(1, 0, 2 * n, n + 0, n + 0, 0);

  for (int i = 1; i <= k; ++i) {
    int d = l[i] - r[i - 1];
    for (int x = 0; x < 2; ++x) dp[i & 1][x].clear();
    for (int t = 0; t < 2; ++t) {
      for (int j = -n; j <= n; ++j) {
        int used = dp[(i - 1) & 1][t].query(1, 0, 2 * n, n + j);
        debug(used, i - 1, j);
        int od = j;
        int ll, rr;
        //0
        if (t == 0) od += d;
        else od -= d;
        if (t == 0) ll = od + (r[i] - l[i]);
        else ll = od - (r[i] - l[i]);
        chg(ll);
        dp[i & 1][t].update(1, 0, 2 * n, ll + n, ll + n, used);

        //1
        od = j;
        if (t == 0) od += d;
        else od -= d;
        ll = od - (r[i] - l[i]);
        chg(ll);
        rr = od + (r[i] - l[i]);
        chg(rr);
        dp[i & 1][!t].update(1, 0, 2 * n, ll + n, rr + n, used + 1);

        //2 ci
        od = j;
        if (t == 0) od += d;
        else od -= d;
        ll = od - (r[i] - l[i]);
        chg(ll);
        rr = od + (r[i] - l[i]);
        chg(rr);
        dp[i & 1][t].update(1, 0, 2 * n, ll + n, rr + n, used + 2);

      }
    }
  }

  int ans = inf;
  for (int t = 0; t < 2; ++t) {
    int nd;
    if (t == 0)
      nd = 0 - (2 * n - r[k]);
    else
      nd = 0 + (2 * n - r[k]);
    
    if (nd >= -n && nd <= n) {
      int x = dp[k & 1][t].query(1, 0, 2 * n, nd + n);
      mini(ans, x);
    }
  }
  if (ans == inf) {
    cout << "Hungry" << endl;
  } else {
    cout << "Full" << endl;
    cout << ans << endl;
  }

  //dp[k][0/1].query(n + 0)
}

int main() {
  run();
  return 0;
}