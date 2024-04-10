/**
https://codeforces.com/problemset/problem/494/D
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int add(int a, int b, int c) {
  return add(a, add(b, c));
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int mul(int a, int b, int c) {
  return mul(a, mul(b, c));
}

int sqr(int a) {
  return mul(a, a);
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N = (int) 1e5 + 7;
int n;
int par[N];
int init_dists[N];
int len_par[N];
int low[N];
int high[N];
int ord[N];
int tt;
vector<pair<int, int>> gi[N];
vector<int> g[N];

void build(int a, int p = -1) {
  ord[++tt] = a;
  low[a] = tt;
  vector<int> kids;
  for (auto &it : gi[a]) {
    int b = it.first;
    if (b == p) {
      continue;
    }
    par[b] = a;
    len_par[b] = it.second;
    init_dists[b] = add(len_par[b], init_dists[a]);
    build(b, a);
    kids.push_back(b);
  }
  g[a] = kids;
  high[a] = tt;
}

vector<pair<int, int>> questions[N];
int solution[N];

struct T {
  int sum;
  int sum2;
};

T operator + (T a, T b) {
  return {add(a.sum, b.sum), add(a.sum2, b.sum2)};
}

T t[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    addup(t[v].sum2, mul(sqr(lazy[v]), tr - tl + 1));
    addup(t[v].sum2, mul(2, lazy[v], t[v].sum));
    addup(t[v].sum, mul(lazy[v], tr - tl + 1));
    /**
    a^2 + b^2 + c^2
    (a+x)^2+(b+x)^2+(c+x)^2=a^2+b^2+c^2+x^2*3+2*x*(a+b+c)
    **/

    if (tl < tr) {
      addup(lazy[2 * v], lazy[v]);
      addup(lazy[2 * v + 1], lazy[v]);
    }

    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    addup(lazy[v], x);
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  t[v] = t[2 * v] + t[2 * v + 1];
}

T get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return {0, 0};
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

void add_op(int l, int r, int x) {
  add(1, 1, n, l, r, x);
}

int get_op(int l, int r) {
  return get(1, 1, n, l, r).sum2;
}

void solve(int a) {
  for (auto &qu : questions[a]) {
    int b = qu.first, index = qu.second;
    solution[index] = 0;
    addup(solution[index], -get_op(1, n));
    addup(solution[index], mul(2, get_op(low[b], high[b])));
  }

  for (auto &b : g[a]) {
    add_op(1, n, len_par[b]);
    add_op(low[b], high[b], -mul(2, len_par[b]));
    solve(b);
    add_op(1, n, -len_par[b]);
    add_op(low[b], high[b], mul(2, len_par[b]));
  }
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    gi[a].push_back({b, c});
    gi[b].push_back({a, c});
  }
  int q;
  cin >> q;
  for (int iq = 1; iq <= q; iq++) {
    int a, b;
    cin >> a >> b;
    questions[a].push_back({b, iq});
    solution[iq] = -1;
  }
  build(1);
  for (int i = 1; i <= n; i++) {
    add_op(i, i, init_dists[ord[i]]);
  }
  solve(1);
  for (int iq = 1; iq <= q; iq++) {
    cout << solution[iq] << "\n";
  }
  return 0;
}