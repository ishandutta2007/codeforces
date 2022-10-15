#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
signed realMain();


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

const int M = 1000012361;

struct node {
  int mx;
  int cnt;
};

node operator + (node a, node b) {
  int mx = max(a.mx, b.mx);
  int cnt = a.cnt * (mx == a.mx) + b.cnt * (mx == b.mx);
  cnt %= M;
  return {mx, cnt};
}

const int N = 400000 + 7;
int n, q, a[N], b[N];
node t[4 * N];

void add(int v, int tl, int tr, int i, node val) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    t[v] = t[v] + val;
  } else {
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, i, val);
    add(2 * v + 1, tm + 1, tr, i, val);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

void upd(int i, node val) {
  add(1, 1, n, i, val);
}

node get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return {0, 0};
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

node get(int l, int r) {
  return get(1, 1, n, l, r);
}

void clr(int v, int tl, int tr) {
  t[v] = {0, 0};
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    clr(2 * v, tl, tm);
    clr(2 * v + 1, tm + 1, tr);
  }
}

void clr() {
  clr(1, 1, n);
}

int pre[N], cpre[N];
int suf[N], csuf[N];
int ret[N], first[N], second[N];

struct Question {
  int ind;
  int i;
  int x;
};

bool operator < (Question a, Question b) {
  return a.x < b.x;
}

int aib[N];

void clraib() {
  for (int i = 1; i <= n; i++) aib[i] = 0;
}

void updaib(int i, int x) {
  while (i <= n) {
    aib[i] = max(aib[i], x);
    i += i & (-i);
  }
}

int getaib(int i) {
  int ret = 0;
  while (i) {
    ret = max(ret, aib[i]);
    i -= i & (-i);
  }
  return ret;
}

signed realMain() {
  map<int, int> no;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    no[a[i]] = 0;
  }
  int ind = 0;
  for (auto &it : no) {
    it.second = ++ind;
  }
  for (int i = 1; i <= n; i++) {
    b[i] = no[a[i]];
  }
  clr();
  for (int i = 1; i <= n; i++) {
    node it = get(1, b[i] - 1);
    if (it.mx == 0) {
      it.cnt++;
    }
    it.mx++;
    pre[i] = it.mx;
    cpre[i] = it.cnt;
    upd(b[i], it);
  }
  int best, total;
  {
    auto it = get(1, n);
    best = it.mx;
    total = it.cnt;
  }
  clr();
  for (int i = n; i >= 1; i--) {
    node it = get(b[i] + 1, n);
    if (it.mx == 0) {
      it.cnt++;
    }
    it.mx++;
    suf[i] = it.mx;
    csuf[i] = it.cnt;
    upd(b[i], it);
  }
  clr();
  vector<Question> v;
  for (int it = 1; it <= q; it++) {
    int i, x;
    cin >> i >> x;
    ret[it] = best;
    if (pre[i] + suf[i] - 1 == best && (ll) cpre[i] * csuf[i] % M == total) {
      ret[it] = best - 1;
    }
    /// acum tot ce trece prin el :)
    v.push_back({it, i, x});
  }
  vector<pair<int, int>> elements;
  for (int i = 1; i <= n; i++) {
    elements.push_back({a[i], i});
  }
  sort(elements.begin(), elements.end());
  sort(v.begin(), v.end());
  clraib();
  int p = 0;
  for (auto &it : v) {
    while (p < (int) elements.size() && elements[p].first < it.x) {
      updaib(elements[p].second, pre[elements[p].second]);
      p++;
    }
    first[it.ind] = getaib(it.i - 1);
  }
  reverse(elements.begin(), elements.end());
  reverse(v.begin(), v.end());
  clraib();
  p = 0;
  for (auto &it : v) {
    while (p < (int) elements.size() && elements[p].first > it.x) {
      updaib(n + 1 - elements[p].second, suf[elements[p].second]);
      p++;
    }
    second[it.ind] = getaib(n - it.i);
  }
  for (int i = 1; i <= q; i++) {
    cout << max(first[i] + second[i] + 1, ret[i]) << "\n";
  }
  return 0;
}