#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 14) + 7;
int n, m, t[2 * N], un, last[N];
bool rad[2 * N], val[N];

int ste;

int get(int a) {
  if (rad[a]) {
    return a;
  } else {
    return t[a] = get(t[a]);
  }
}

int root(int a) {
  ste = 0;
  return get(a);
}

void unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) return;
  un++;
  t[a] = b;
  rad[a] = 0;
}

int some[N], tr[2 * N];

void norm() {
  vector<int> ids;
  for (int i = 1; i <= m; i++) {
    some[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    if (val[i]) ids.push_back(i);
    else t[i] = 0;
    last[i] = val[i];
  }
  for (auto &i : ids) {
    t[i] = root(m + i);
  }
  for (auto &i : ids) {
    tr[t[i]] = 0;
  }
  int id = 0;
  for (int j = 1; j <= 2 * m; j++) {
    if (tr[j] == 0) {
      tr[j] = ++id;
    }
  }
  for (auto &i : ids) {
    t[i] = tr[t[i]];
  }
  for (auto &i : ids) {
    if (some[t[i]]) {
      t[i] = some[t[i]];
      rad[i] = 0;
    } else {
      rad[i] = 1;
      some[t[i]] = i;
    }
  }
  for (auto &i : ids) {
    tr[t[i]] = -1;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= 2 * m; i++) {
    tr[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    t[i] = i;
    rad[i] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int y = 0;
    for (auto &ch : s) {
      int num;
      if ('0' <= ch && ch <= '9') {
        num = ch - '0';
      } else {
        num = 10 + ch - 'A';
      }
      for (int bit = 3; bit >= 0; bit--) {
        val[++y] = !!(num & (1 << bit));
        cnt += val[y];
      }
    }
    for (int i = 1; i <= m; i++) {
      t[m + i] = m + i;
      rad[m + i] = 1;
    }
    for (int i = 1; i <= m; i++) {
      if (last[i] && val[i]) {
        unite(i, i + m);
      }
      if (i >= 2 && val[i - 1] && val[i]) {
        unite(i + m - 1, i + m);
      }
    }
    norm();
  }
  cout << cnt - un << "\n";
}