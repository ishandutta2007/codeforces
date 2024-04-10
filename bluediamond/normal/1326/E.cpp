#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 7;
int n;
int a[N];
int p[N];
int b[N];
int t[4 * N];
int add[4 * N];

void push(int v, int tl, int tr) {
  if (add[v]) {
    t[v] += add[v];
    if (tl < tr) {
      add[2 * v] += add[v];
      add[2 * v + 1] += add[v];
    }
    add[v] = 0;
  }
}

void upd(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    add[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, l, r, x);
  upd(2 * v + 1, tm + 1, tr, l, r, x);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

void upd(int i, int x) {
  upd(1, 1, n, 1, i, x);
}

int get_max() {
  push(1, 1, n);
  return t[1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int sol = n;
  upd(p[n], +1);
  for (int i = 1; i <= n; i++) {
    while (get_max() <= 0) {
      sol--;
      upd(p[sol], +1);
    }
    upd(b[i], -1);
    cout << sol << " ";
  }
  cout << "\n";
}