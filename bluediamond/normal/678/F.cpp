#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
const ll INF = (ll) 2e18;
int q;
int type[N], first[N], second[N];

struct T {
  bool nothing;
  ll a;
  ll b;
  ll eval(ll x) {
    if (nothing) {
      return -INF;
    }
    return a * x + b;
  }
};

T t[4 * N];
int n;
int when[N];
vector<pair<int, T>> ret;
vector<vector<pair<int, T>>> memo;

void add(int v, int tl, int tr, T it) {
  ret.push_back({v, t[v]});
  if (t[v].nothing) {
    t[v] = it;
    return;
  }
  if (tl == tr && it.eval(when[tl]) > t[v].eval(when[tl])) {
    t[v] = it;
    return;
  }
  if (it.eval(when[tl]) > t[v].eval(when[tl]) && it.eval(when[tr]) > t[v].eval(when[tr])) {
    t[v] = it;
    return;
  }
  if (it.eval(when[tl]) < t[v].eval(when[tl]) && it.eval(when[tr]) < t[v].eval(when[tr])) {
    return;
  }
  if (tl == tr) {
    return;
  }
  int tm = (tl + tr) / 2;
  if (it.eval(when[tl]) >= t[v].eval(when[tl])) {
      swap(it, t[v]);
  }
  if (it.eval(when[tm]) < t[v].eval(when[tm])) {
    add(2 * v + 1, tm + 1, tr, it);
  } else {
    add(2 * v, tl, tm, t[v]);
    t[v] = it;
  }
}

ll query(int v, int tl, int tr, int x) {
  ll sol = t[v].eval(x);
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    if (x <= when[tm]) {
      sol = max(sol, query(2 * v, tl, tm, x));
    } else {
      sol = max(sol, query(2 * v + 1, tm + 1, tr, x));
    }
  }
  return sol;
}

ll query(int x) {
  return query(1, 1, n, x);
}

void add(ll a, ll b) {
  ret.clear();
  add(1, 1, n, {0, a, b});
  memo.push_back(ret);
}

void rev() {
  ret = memo.back();
  memo.pop_back();
  for (auto &it : ret) {
    t[it.first] = it.second;
  }
}

bool fin[N];
vector<pair<ll, ll>> de[4 * N];
ll solution[N];

void baga(int v, int tl, int tr, int l, int r, ll a, ll b) {
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    de[v].push_back({a, b});
    return;
  }
  int tm = (tl + tr) / 2;
  baga(2 * v, tl, tm, l, r, a, b);
  baga(2 * v + 1, tm + 1, tr, l, r, a, b);
}

vector<pair<int, int>> acum;

void dfs(int v, int tl, int tr) {
  for (auto &it : de[v]) {
    add(it.first, it.second);
    acum.push_back({it.first, it.second});
  }
  if (tl == tr) {
    if (type[tl] == 3) {
      solution[tl] = query(first[tl]);
    }
  } else {
    int tm = (tl + tr) / 2;
    dfs(2 * v, tl, tm);
    dfs(2 * v + 1, tm + 1, tr);
  }
  for (auto &it : de[v]) {
    rev();
    acum.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 4 * N; i++) {
    t[i].nothing = 1;
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> type[i] >> first[i];
    if (type[i] == 1) {
      cin >> second[i];
    }
  }
  for (int i = 1; i <= q; i++) {
    if (type[i] == 3) {
      when[++n] = first[i];
    }
  }
  sort(when + 1, when + n + 1);
  for (int i = 1; i <= q; i++) {
    if (type[i] == 2) {
      int j = first[i];
      fin[j] = 1;
      baga(1, 1, q, j, i, first[j], second[j]);
    }
  }
  for (int i = 1; i <= q; i++) {
    if (type[i] == 1 && fin[i] == 0) {
      baga(1, 1, q, i, q, first[i], second[i]);
    }
  }
  dfs(1, 1, q);
  for (int i = 1; i <= q; i++) {
    if (type[i] == 3) {
      if (solution[i] == -INF) {
        cout << "EMPTY SET\n";
      } else {
        cout << solution[i] << "\n";
      }
    }
  }
}