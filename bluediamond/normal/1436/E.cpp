#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 777;
const int INF = (int) 1e9;
int n, a[N], t[4 * N];
vector<int> p[N];

void upd(int v, int tl, int tr, int l, int r, int x) {
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    t[v] = max(t[v], x);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, l, r, x);
  upd(2 * v + 1, tm + 1, tr, l, r, x);
}

int get(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) {
    return 0 ;
  }
  int sol = t[v];
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    sol = max(sol, get(2 * v, tl, tm, i));
    sol = max(sol, get(2 * v + 1, tm + 1, tr, i));
  }
  return sol;
}

void upd(int l, int r, int x) {
  if (l <= r) {
    upd(1, 1, n, l, r, x);
  }
}

int get(int i) {
  return get(1, 1, n, i);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int l = n + 7;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) upd(i, i, i);
  for (int x = 1; x <= l; x++) {
    bool found = 0;
    vector<int> lol;
    lol.push_back(0);
    lol.push_back(n + 1);
    for (auto &i : p[x]) lol.push_back(i);
    sort(lol.begin(), lol.end());
    for (int i = 0; i + 1 < (int) lol.size(); i++) {
      int l = lol[i] + 1;
      int r = lol[i + 1] - 1;
      if (l <= r && get(l) <= r) {
        found = 1;
        break;
      }
    }
    if (found == 0) {
      cout << x << "\n";
      return 0;
    }
    for (int i = 0; i + 1 < (int) p[x].size(); i++) {
      int l = p[x][i] + 1;
      int r = p[x][i + 1];
      upd(l, r, r);
    }
    if (p[x].empty()) {
      upd(1, n, INF);
    } else {
      upd(1, p[x][0], p[x][0]);
      upd(p[x].back() + 1, n, INF);
    }
  }
}