#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 7;
int n, a[N], tmin[4 * N];
bool has[N], pre[N], ok[N];

void build(int v, int tl, int tr) {
  if (tl == tr) tmin[v] = a[tl];
  else {int tm = (tl + tr) / 2; build(2 * v, tl, tm); build(2 * v + 1, tm + 1, tr); tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);}
}

int mn(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return N;
  if (l <= tl && tr <= r) return tmin[v];
  int tm = (tl + tr) / 2; return min(mn(2 * v, tl, tm, l, r), mn(2 * v + 1, tm + 1, tr, l, r));
}

void build() {
  build(1, 1, n);
}

int mn(int l, int r) {
  return mn(1, 1, n, l, r);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) has[i] = pre[i] = 0;
    for (int i = 1; i <= n; i++) {cin >> a[i]; has[a[i]] = 1;}
    pre[0] = 1;
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] & has[i];
    build();
    ok[1] = pre[n];
    ok[n] = has[1];
    int l = 1, r = n, len = 0;
    for (int it = 1; it < n; it++) {
      if (a[l] == it && mn(l + 1, r) == it + 1) {
        len++;
        l++;
        continue;
      }
      if (a[r] == it && mn(l, r - 1) == it + 1) {
        len++;
        r--;
        continue;
      }
      len += (mn(l, r) == it);
      break;
    }
    for (int i = 2; i < n; i++) {
      int x = n - i + 1;
      ok[i] = (x <= len);
    }
    string print;
    for (int i = 1; i <= n; i++) if (ok[i]) print += '1'; else print += '0';
    cout << print << "\n";
  }
}