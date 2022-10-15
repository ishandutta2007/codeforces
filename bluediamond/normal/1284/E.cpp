#include <bits/stdc++.h>

using namespace std;

#define int long long

int c3(int n) {
  return n * (n - 1) * (n - 2) / (1 * 2 * 3);
}

struct point {
  int x, y;
};

int f(point a, point b) {
  return (a.x - b.x) * (a.y + b.y);
}

int f(point a, point b, point c) {
  return f(a, b) + f(b, c) + f(c, a);
}

const int N = 2500 + 7;
int n;
point p[N];

int f(int i, int j) {
  return f(p[i], p[j]);
}

int f(int i, int j, int k) {
  return f(p[i], p[j], p[k]);
}

int sup;

int cadran(point a) {
  if (a.y >= 0) {
    if (a.x >= 0)
      return 1;
    else
      return 2;
  } else {
    if (a.x >= 0)
      return 4;
    else
      return 3;
  }
}

bool cmp(int i, int j) {
  point a = p[i], b = p[j];
  a.x -= p[sup].x;
  a.y -= p[sup].y;
  b.x -= p[sup].x;
  b.y -= p[sup].y;
  if (cadran(a) != cadran(b))
    return cadran(a) < cadran(b);
  return f(point{0, 0}, a, b) > 0;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen ("input", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  int t = 0;
  int c = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / (1 * 2 * 3 * 4 * 5);
  p[n + 1].x = (int) 2e9;
  p[n + 1].y = (int) 2e9 + 1;
  for (int i = 1; i <= n; i++) {
    vector<int> ord;
    sup = i;
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        ord.push_back(j);
      }
    }
    sort(ord.begin(), ord.end(), cmp);
    for (int it = 0; it < n - 1; it++) {
      int j = ord[it];
      if (j < i) continue;
      int cnt = 0;
      int pos = it % (n - 1);
      int l = 0, r = n - 2;
      while(l < r)
      {
          int mid = ((l + r + 1) >> 1);
          if(f(i, j, ord[(pos + mid) % (n - 1)]) >= 0)
            l = mid;
          else
            r = mid - 1;
      }
      cnt = l;
      t += c3(cnt);
      t += c3(n - 2 - cnt);
    }
  }
  cout << 5 * c - t << "\n";
}