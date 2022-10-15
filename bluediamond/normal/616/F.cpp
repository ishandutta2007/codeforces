#include <bits/stdc++.h>

using namespace std;

#define int long long

struct T {
  int id;
  int c1;
  int c2;
};

bool operator < (T a, T b) {
  if (a.c1 != b.c1) {
    return a.c1 < b.c1;
  } else {
    return a.c2 < b.c2;
  }
}


const int N = 700000 + 7 + 777;
int n;
int p[N];
int c[N];
int f[N];
int lcp[N];
int coef[N];
int s[N];

vector<T> so(vector<T> a) {
  int n = (int) a.size();
  vector<T> b(n);
  int mc = 0;
  for (auto &it : a) {
    mc = max(mc, it.c1);
    mc = max(mc, it.c2);
  }
  for (int i = 0; i <= mc; i++) {
    f[i] = 0;
  }
  for (auto &it : a) {
    f[it.c2]++;
  }
  for (int i = 1; i <= mc; i++) {
    f[i] += f[i - 1];
  }
  for (int i = 0; i < n; i++) {
    b[--f[a[i].c2]] = a[i];
  }
  for (int i = 0; i <= mc; i++) {
    f[i] = 0;
  }
  for (auto &it : b) {
    f[it.c1]++;
  }
  for (int i = 1; i <= mc; i++) {
    f[i] += f[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    a[--f[b[i].c1]] = b[i];
  }
  return a;
}

int init[N], kek[N], lo[N], hi[N], pre[N], l2[N], le[N];
string strs[N];


int t[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = lcp[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return (int) 1e9;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int get(int l, int r) {
  return get(1, 0, n, l, r);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int te = (int) 1e5 + 1;
  int cnt, sz = 0;
  cin >> cnt;
  for (int i = 1; i <= cnt; i++) {
    cin >> strs[i];
    lo[i] = sz;
    hi[i] = sz + (int) strs[i].size() - 1;
    for (int j = lo[i]; j <= hi[i]; j++) {
      l2[j] = hi[i] - j + 1;
    }
    for (auto &ch : strs[i]) {
      s[sz++] = ch + (int) 1e5 + 3;
    }
    s[sz++] = --te;
  }
  assert(sz < N);
  for (int i = 1; i <= cnt; i++) {
    cin >> init[i];
    for (int j = lo[i]; j <= hi[i]; j++) {
      kek[j] = init[i];
    }
  }
  n = sz;
  for (int i = 0; i < n; i++) {
    f[s[i]]++;
  }
  for (int x = 1; x < N; x++) {
    f[x] += f[x - 1];
  }
  for (int i = 0; i < n; i++) {
    p[--f[s[i]]] = i;
    c[i] = s[i];
  }
  for (int l = 1; l <= n; l *= 2) {
    vector<T> vec;
    for (int i = 0; i < n; i++) {
      vec.push_back({i, c[i], c[(i + l) % n]});
    }
    vec = so(vec);
    for (int i = 0; i < n; i++) {
      p[i] = vec[i].id;
    }
    c[vec[0].id] = 0;
    int cur = 0;
    for (int i = 1; i < n; i++) {
      if (vec[i - 1].c1 != vec[i].c1 || vec[i - 1].c2 != vec[i].c2) {
        cur++;
      }
      c[vec[i].id] = cur;
    }
  }
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int pi = c[i];
    int j = p[pi - 1];
    while (s[i + k] == s[j + k]) {
      k++;
    }
    lcp[pi] = k;
    k = max(0LL, k - 1);
  }
  for (int i = 0; i < n; i++) {
    le[i] = l2[p[i]];
    coef[i] = kek[p[i]];
    pre[i] = coef[i];
    if (i) {
      pre[i] += pre[i - 1];
    }
  }
  int sol = 0;
  for (int l = 1; l < n; l++) {
    if (le[l] > lcp[l] && le[l] > lcp[l + 1]) {
      sol = max(sol, le[l] * (pre[l] - pre[l - 1]));
    }
  }
  build(1, 0, n);
  vector<int> stk;
  for (int i = 2; i <= n; i++) {
    while (!stk.empty() && lcp[i] < lcp[stk.back()]) {
      stk.pop_back();
    }
    if (!stk.empty()) {
      int l = stk.back() + 1, r = i - 1;
      if (l > r) continue;
      bool ok = (2 <= l && l < n && l <= r && r < n);
      if (!ok) continue;
      int mn = get(l, r);
      if (mn > lcp[l - 1] && mn > lcp[r + 1]) {
        mn = min(mn, le[l - 1]);
        if (mn > lcp[l - 1] && mn > lcp[r + 1]) {
          sol = max(sol, mn * (pre[r] - pre[l - 2]));
        }
      }
    }
    stk.push_back(i);
  }
  stk.clear();

  for (int i = n; i >= 0; i--) {
    while (!stk.empty() && lcp[i] < lcp[stk.back()]) {
      stk.pop_back();
    }
    if (!stk.empty()) {
      int l = i + 1, r = stk.back() - 1;
      bool ok = (2 <= l && l < n && l <= r && r < n);
      if (!ok) continue;
      int mn = get(l, r);
      if (mn > lcp[l - 1] && mn > lcp[r + 1]) {
        mn = min(mn, le[l - 1]);
        if (mn > lcp[l - 1] && mn > lcp[r + 1]) {
          sol = max(sol, mn * (pre[r] - pre[l - 2]));
        }
      }
    }
    stk.push_back(i);
  }
  cout << sol << "\n";
}