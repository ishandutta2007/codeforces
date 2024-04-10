#include <bits/stdc++.h>


using namespace std;

const int N = (int) 2e5 + 7;
int height, n, a[N], q, t[4 * N];


void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return -1;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> height >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  cin >> q;
  for (int iq = 1; iq <= q; iq++) {
    int h1, i1, h2, i2, k;
    cin >> h1 >> i1 >> h2 >> i2 >> k;
    if (i1 > i2) {
      swap(h1, h2);
      swap(i1, i2);
    }
    if ((h2 - h1) % k != 0 || abs(i2 - i1) % k != 0) {
      cout << "NO\n";
      continue;
    }
    int mx = h1;
    mx += (height - mx) / k * k;
    cout << ((get(1, 1, n, i1, i2) < mx) ? ("YES") : ("NO")) << "\n";
  }


  return 0;
}