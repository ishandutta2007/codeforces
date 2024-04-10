#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
int n;
int l[N];
int r[N];
int tl[N];
int tr[N];

void add(int i, int x, int t[]) {
  while (i < N)  {
    t[i] += x;
    i += i & (-i);
  }
}

int query(int i, int t[]) {
  int sol = 0;
  while (i) {
    sol += t[i];
    i -= i & (-i);
  }
  return sol;
}

int query(int l, int r, int t[]) {
  return query(r, t) - query(l - 1, t);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
      m[l[i]] = 0;
      m[r[i]] = 0;
    }
    int c = 0;
    for (auto &it : m) it.second = ++c;
    for (int i = 1; i <= n; i++) {
      l[i] = m[l[i]];
      r[i] = m[r[i]];
    }
    for (int i = 1; i <= c; i++) tl[i] = tr[i] = 0;
    int no = (int) 1e9;
    for (int i = 1; i <= n; i++) {
      add(r[i], 1, tr);
      add(l[i], 1, tl);
    }
    for (int i = 1; i <= n; i++) {
      int cur = query(1, l[i] - 1, tr) + query(r[i] + 1, c, tl);
      no = min(no, cur);
    }
    cout << no << "\n";
  }

}