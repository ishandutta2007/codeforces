#include <bits/stdc++.h>

using namespace std;

struct T {
  int a, b, c;
};

bool operator < (T a, T b) {
  return a.c < b.c;
}

typedef long long ll;
const int N = 2500 + 7;
int n, a[N][N], t[N];
vector<int> rp[N];
vector<T> e;
bool ok = 1;

void done(bool ok) {
  cout << (ok ? "" : "NOT ") << "MAGIC\n";
  exit(0);
}

int r(int i) {
  if (t[i] == i) return i;
  return t[i] = r(t[i]);
}

bool u(int i, int j) {
  if (i == j) return 0;
  t[i] = j;
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
    t[i] = i;
    rp[i] = {i};
  }
  for (int i = 1; i <= n; i++) {
    ok &= (a[i][i] == 0);
    for (int j = i; j <= n; j++) {
      ok &= (a[i][j] == a[j][i]);
      e.push_back({i, j, a[i][j]});
    }
    if (!ok) {
      done(0);
    }
  }
  sort(e.begin(), e.end());
  for (auto &it : e) {
    it.a = r(it.a), it.b = r(it.b);
    if (u(it.a, it.b)) {
      for (auto &x : rp[it.a]) for (auto &y : rp[it.b]) {
        if (a[x][y] != it.c) {
          done(0);
        }
      }
      for (auto &x : rp[it.a]) rp[it.b].push_back(x);
      rp[it.a].clear();
    }
  }
  done(1);

  return 0;
}