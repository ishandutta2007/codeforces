#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 3e5 + 7;
int n, q, a[N], sol[N], tree[4 * N];
vector<int> p[N];

int pref(int x, int i) {
  int l = 0, r = (int) p[x].size() - 1, sol = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (p[x][m] <= i) {
      sol = m + 1;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return sol;
}

int cnt(int x, int l, int r) {
  if (p[x].empty()) return 0;
  return pref(x, r) - pref(x, l - 1);
}

vector<pair<int, int>> ask[N];



void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    if (cnt(tree[2 * v], tl, tr) > cnt(tree[2 * v + 1], tl, tr)) {
      tree[v] = tree[2 * v];
    } else {
      tree[v] = tree[2 * v + 1];
    }
  }
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    assert(0);
  }
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) {
    return get(2 * v, tl, tm, l, r);
  }
  if (tm + 1 <= l) {
    return get(2 * v + 1, tm + 1, tr, l, r);
  }
  int a = get(2 * v, tl, tm, l, r);
  int b = get(2 * v + 1, tm + 1, tr, l, r);
  if (cnt(a, l, r) > cnt(b, l, r)) {
    return a;
  } else {
    return b;
  }
}

vector<int> get(int a, int k) {
  if (a % k == 0) {
    vector<int> sol(k, a / k);
    return sol;
  } else {
    vector<int> sol(k, a / k);
    for (int j = 0; j < a % k; j++) {
      sol[j]++;
    }
    return sol;
  }
}

bool dumb(int a, int b, int k) {
  vector<int> ff = get(a, k);
  vector<int> ss = get(b, k);
  sort(ff.begin(), ff.end());
  sort(ss.begin(), ss.end());
  for (int i = 0; i < k; i++) {
    if (ff[i] > ss[i] + 1) {
      return 0;
    }
  }
  return 1;
}

int helped;

bool smart(int a, int b, int k) {
  int small_a = a / k, big_a = small_a + 1;
  int small_b = b / k, big_b = small_b + 1;

  int cnta = k - a % k, cntb = k - b % k;
  { /// is small a with small b?
    if (cnta && cntb) {
      if (small_a > small_b + 1) {
        return 0;
      }
    }
  }
  { /// is small a with big b
    if (cnta > cntb) {
      if (small_a > big_b + 1) {
        return 0;
      }
    }
  }
  { /// is big a with small b
    if (cntb > cnta) {
      if (big_a > small_b + 1) {
        return 0;
      }
    }
  }
  { /// is big a with big b
    if (cnta < k && cntb < k) {
      if (big_a > big_b + 1) {
        return 0;
      }
    }
  }

  return 1;

  helped++;
  return dumb(a, b, k);
}



void check(int l, int r) {
  map<int, int> f;
  int fm = 0, w = -1;
  for (int j = l; j <= r; j++) {
    f[a[j]]++;
    fm = max(fm, f[a[j]]);
    if (f[a[j]] == fm) {
      w = a[j];
    }
  }
  if (2 * f[w] > r - l + 1) {
    if (w != get(1, 1, n, l, r)) {
      cout << " : " << l << " " << r << "\n";
    }
    assert(w == get(1, 1, n, l, r));
  } else {

  }
}

signed realMain() {
/**
  int l = 50;
  for (int a = 1; a <= l; a++) {
    for (int b = 1; b <= l; b++) {
      for (int k = 1; k <= l; k++) {
        if (dumb(a, b, k) != smart(a, b, k)) {
          cout << a << " " << b << " " << k << "\n";
          cout << "good : " << dumb(a, b, k) << "\n";
          cout << "me   : " << smart(a, b, k) << "\n";
          return 0;
        }
        assert(dumb(a, b, k) == smart(a, b, k));
      }
    }
  }
  cout << l * l * l - helped << "\n";
  cout << helped << "\n";
  return 0;**/
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]].push_back(i);
  }
  build(1, 1, n);
/**
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      check(i, j);
    }
  }
  return 0;**/

  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    int x = get(1, 1, n, l, r), a = cnt(x, l, r), b = r - l + 1 - a, sol = -1;
    l = 1, r = n;
    while (l <= r) {
      int m = (l + r) / 2;
      if (smart(a, b, m)) {
        sol = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    assert(sol != -1);
    cout << sol << "\n";
  }
  return 0;
}