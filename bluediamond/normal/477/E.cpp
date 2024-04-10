#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool home = 1;


const int N = (int) 4e5 + 7;
const int INF = (int) 1e9;

class minsegtree {
public:
  int n;
  vector<int> mn;

  void init(int nn) {
    n = nn;
    mn.resize(4 * (n + 7));

  }

  void upd(int v, int tl, int tr, int i, int val) {
    if (tr < i || i < tl) return;
    if (tl == tr) {
      mn[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, i, val);
    upd(2 * v + 1, tm + 1, tr, i, val);
    mn[v] = min(mn[2 * v], mn[2 * v + 1]);
  }

  int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return mn[v];
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
  }

  void upd(int i, int val) {
    upd(1, 0, n, i, val);
  }

  int get(int l, int r) {
    return get(1, 0, n, l, r);
  }


};


int n;
int a[2][N];
int type[N];
int r1[N];
int r2[N];
int c1[N];
int c2[N];
int sol[N];
int q;

int treemna[2][4 * N];

void buildmna(int tp, int v, int tl, int tr) {
  if (tl == tr) {
    treemna[tp][v] = a[tp][tl];
  } else {
    int tm = (tl + tr) / 2;
    buildmna(tp, 2 * v, tl, tm);
    buildmna(tp, 2 * v + 1, tm + 1, tr);
    treemna[tp][v] = min(treemna[tp][2 * v], treemna[tp][2 * v + 1]);
  }
}

int getmina(int tp, int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) return treemna[tp][v];
  int tm = (tl + tr) / 2;
  return min(getmina(tp, 2 * v, tl, tm, l, r), getmina(tp, 2 * v + 1, tm + 1, tr, l, r));
}

minsegtree t1;
minsegtree t2;

vector<int> lar1[2][N];
vector<int> lar2[2][N];

int bb[N];
int cc[N];

vector<int> stk;

int babs(int it, int mn) {
  int sol = INF;
  int l = 0, r = (int) stk.size() - 1, last = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    int aft = stk[m];
    if (mn >= a[type[it]][aft]) {
      last = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  int kek1 = INF, kek2 = INF;
  if (0 <= last) {
    l = 0, r = last;
    int ultim = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      int aft = stk[m];
      if (c2[it] >= a[type[it]][aft]) {
        ultim = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (0 <= ultim) {
      sol = min(sol, t1.get(0, ultim) + c2[it]);
    }

    if (ultim + 1 <= last) {
      sol = min(sol, t2.get(ultim + 1, last) - c2[it]);
    }
  }

  return sol - r1[it] - r2[it];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[0][i];
    a[1][n + 1 - i] = a[0][i];
  }
  buildmna(0, 1, 1, n);
  buildmna(1, 1, 1, n);


  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
    if (r1[i] <= r2[i]) {
      type[i] = 0;
    } else {
      type[i] = 1;
      r1[i] = n + 1 - r1[i];
      r2[i] = n + 1 - r2[i];
    }
    lar1[type[i]][r1[i]].push_back(i);
    lar2[type[i]][r2[i]].push_back(i);
    sol[i] = INF;
  }
  for (int it = 1; it <= q; it++) {
    { /// normal + down
      sol[it] = min(sol[it], r2[it] - r1[it] + 1 + c2[it]);
    }
    { /// normal
      sol[it] = min(sol[it], r2[it] - r1[it] + abs(c2[it] - min(c1[it], getmina(type[it], 1, 1, n, r1[it], r2[it]))));
    }
  }
  for (int tp = 0; tp < 2; tp++) { /// normal + where up
    stk.clear();
    for (int i = 1; i <= n; i++){
      while (!stk.empty() && a[tp][i] <= a[tp][stk.back()]) {
        stk.pop_back();
      }
      stk.push_back(i);
      for (auto &it : lar2[tp][i]) {
        int mn = INF;
        int l = 0, r = (int) stk.size() - 1, pos = (int) stk.size();
        while (l <= r) {
          int m = (l + r) / 2;
          if (r1[it] <= stk[m]) {
            pos = m;
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
        if (pos < (int) stk.size()) {
          l = pos;
          r = (int) stk.size() - 1;
          int lo = l, hi = r, lar2st1 = l - 1;
          while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (c2[it] >= a[tp][stk[m]]) {
              lar2st1 = m;
              lo = m + 1;
            } else {
              hi = m - 1;
            }
          }
          if (l <= lar2st1 && lar2st1 <= r) mn = min(mn, abs(c2[it] - a[tp][stk[lar2st1]]));
          if (l <= lar2st1 + 1 && lar2st1 + 1 <= r) mn = min(mn, abs(c2[it] - a[tp][stk[lar2st1 + 1]]));
        }
        sol[it] = min(sol[it], r2[it] - r1[it] + mn + 1);
      }
    }
  }
  t1.init(n);
  t2.init(n);
  for (int tp = 0; tp < 2; tp++) { /// go back normal / up
    stk.clear();
    for (int i = 1; i <= n; i++) {
      for (auto &it : lar1[tp][i]) {
        int mn = min(getmina(tp, 1, 1, n, r1[it], r2[it]), c1[it]);
        int kek = INF;
        int l = 0, r = (int) stk.size() - 1, lastgood = -1;
        while (l <= r) {
          int m = (l + r) / 2;
          int bk = stk[m];
          if (mn >= a[type[it]][bk]) {
            lastgood = m;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        if (0 <= lastgood) {
          int lo = 0, hi = lastgood, lastsmall = -1;
          while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (c2[it] > a[type[it]][stk[mid]]) {
              lastsmall = mid;
              lo = mid + 1;
            } else {
              hi = mid - 1;
            }
          }

          if (0 <= lastsmall) {
            sol[it] = min(sol[it], t1.get(0, lastsmall) + c2[it] + r1[it] + r2[it]);
          }
          if (lastsmall + 1 <= lastgood) {
            sol[it] = min(sol[it], t2.get(lastsmall + 1, lastgood) - c2[it] + r1[it] + r2[it]);
          }
        }
        mn = getmina(tp, 1, 1, n, r1[it], r2[it]);
        l = 0, r = (int) stk.size() - 1, lastgood = -1;
        while (l <= r) {
          int m = (l + r) / 2;
          int bk = stk[m];
          if (mn >= a[type[it]][bk]) {
            lastgood = m;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }

        if (0 <= lastgood) {
          int lo = 0, hi = lastgood, lastsmall = -1;
          while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (c2[it] > a[type[it]][stk[mid]]) {
              lastsmall = mid;
              lo = mid + 1;
            } else {
              hi = mid - 1;
            }
          }
          if (0 <= lastsmall) {
            sol[it] = min(sol[it], t1.get(0, lastsmall) + c2[it] + r1[it] + r2[it] + 1);
          }
          if (lastsmall + 1 <= lastgood) {
            sol[it] = min(sol[it], t2.get(lastsmall + 1, lastgood) - c2[it] + r1[it] + r2[it] + 1);
          }
        }

      }
      while (!stk.empty() && a[tp][i] <= a[tp][stk.back()]) {
        stk.pop_back();
      }
      t1.upd((int) stk.size(), -a[tp][i] - 2 * i);
      t2.upd((int) stk.size(), a[tp][i] - 2 * i);
      stk.push_back(i);
    }
  }

 for (int tp = 0; tp < 2; tp++) { /// go after normal
    stk.clear();
    for (int i = n; i >= 1; i--) {
      for (auto &it : lar2[tp][i]) {
        bb[it] = INF;
        cc[it] = INF;

        int mn = min(c1[it], getmina(tp, 1, 1, n, r1[it], r2[it]));
        bb[it] = babs(it, mn);
        mn = a[type[it]][r2[it]];
        cc[it] = min(INF, babs(it, mn) + 1);
      }
      while (!stk.empty() && a[tp][i] <= a[tp][stk.back()]) {
        stk.pop_back();
      }
      t1.upd((int) stk.size(), -a[tp][i] + 2 * i);
      t2.upd((int) stk.size(), a[tp][i] + 2 * i);
      stk.push_back(i);
    }
  }
  /**

  XX
  XXXXX
  XX in stack
  XXXXX in stack
  XXXXXXXXX
  XXXXXXXX in stack
  XXXXXXXXXX in stack

  **/
  for (int it = 1; it <= q; it++) {
    { /// go after normal
      sol[it] = min(sol[it], bb[it]);
    }
    { /// go after + up
      sol[it] = min(sol[it], cc[it]);
    }
  }
  if (home) {
    cout << "no asserts failed!!\n";
   // return 0;
  }
  ll ha = 0;
  for (int i = 1; i <= n; i++) {
    ha = ha * 333333333 + sol[i];
  }
  if (home) {
    cout << ha << "\n";
    assert(ha == 5220200856869432519);
  }
  for (int i = 1; i <= q; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}