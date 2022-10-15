#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, k;
int trans[N];
int a[N];
int b[N];
int lazy[4 * N];
int bg[N];
int sol[N];

void push(int v) {
  if (2 * v < 4 * N) {
    lazy[2 * v] = min(lazy[2 * v], lazy[v]);
    if (2 * v + 1 < 4 * N) {
      lazy[2 * v + 1] = min(lazy[2 * v + 1], lazy[v]);
    }
  }
}

void upd(int v, int tl, int tr, int l, int r, int x) {
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] = min(lazy[v], x);
  } else {
    int tm = (tl + tr) / 2;
    push(v);
    upd(2 * v, tl, tm, l, r, x);
    upd(2 * v + 1, tm + 1, tr, l, r, x);
  }
}

int get(int v, int tl, int tr, int p) {
  if (tr < p || p < tl) {
    return (int) 1e9;
  }
  if (tl == tr) {
    return lazy[v];
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    int a = get(2 * v, tl, tm, p);
    int b = get(2 * v + 1, tm + 1, tr, p);
    return min(a, b);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  for (int i = 0; i < 4 * N; i++) {
    lazy[i] = (int) 1e9;
  }

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    trans[a[i]] = i;
    upd(1, 1, n, i, i, i);
  }

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    b[i] = trans[x];
  }

  for (int i = 1; i < n; i++) {
    int x = b[i], y = b[i + 1];
    if (x > y) {
      upd(1, 1, n, y, x, y);
    }
  }

  for (int i = 1; i <= n; i++) {
    bg[i] = get(1, 1, n, i);
    if (bg[i] != i) {
      bg[i] = min(bg[i], bg[i - 1]);
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += (bg[i] != bg[i - 1]);
  }


  if (cnt < k) {
    cout << "NO\n";
    return 0;
  }

  int now = 0;

  for (int i = 1; i <= n; i++) {
    if (bg[i] < i) {
      sol[i] = sol[bg[i]];
    } else {
      sol[i] = min(now++, 25);
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << (char) (sol[trans[i]] + 'a');
  }
  cout << "\n";

  return 0;
}