#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T {
  int x;
  int y;
};

bool operator < (T a, T b) {
  return a.x < b.x;
}

const int INF = (int) 1e9;
const int N = (int) 1e6 + 7;
int n;
T a[N];
int x;
int pt;
int premny[N];
int sufmxy[N];
int sufdifmax[N];
int predifmax[N];


int get(int y) {
  T it = {x, y};
  int sol = 0;
  while (pt + 1 <= n && a[pt + 1].x <= x) {
    pt++;
  }
  sol = max(sol, x - a[1].x);
  sol = max(sol, a[n].x - x);

  sol = max(sol, y - premny[pt]);
  sol = max(sol, sufmxy[pt + 1] - y);
  sol = max(sol, x - y + predifmax[pt]);
  sol = max(sol, y - x + sufdifmax[pt + 1]);
  return sol;
}

void grow() {
  x++;
}

int l;
int r;
int sol = INF;
int cb, cn;

void kol(int x, int y) {
  if (y < 0) {
    return;
  }
  int val = get(y);
  if (val <= sol) {
    sol = val;
    cb = x;
    cn = y;
  }
}

void upd() {
  grow();
  while (get(l + 1) < get(l)) {
    l++;
  }
  if (r < l) {
    r = l;
  }
  while (get(r + 1) == get(r)) {
    r++;
  }
  for (int d = -4; d <= +4; d++) {
    kol(x, l + d);
    kol(x, r + d);
  }
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (auto &ch : s) {
      if (ch == 'B') {
        a[i].x++;
      } else {
        a[i].y++;
      }
    }
  }
  sort(a + 1, a + n + 1);
  premny[0] = +INF;
  for (int i = 1; i <= n; i++) {
    premny[i] = min(premny[i - 1], a[i].y);
  }
  sufmxy[n + 1] = -INF;
  for (int i = n; i >= 1; i--) {
    sufmxy[i] = max(sufmxy[i + 1], a[i].y);
  }
  predifmax[0] = -INF;
  for (int i = 1; i <= n; i++) {
    predifmax[i] = max(predifmax[i - 1], a[i].y - a[i].x);
  }
  sufdifmax[n + 1] = -INF;
  for (int i = n; i >= 1; i--) {
    sufdifmax[i] = max(sufdifmax[i + 1], a[i].x - a[i].y);
  }
  int mn = (int) 1e9, l, r;
  for (int i = 0; i < N; i++) {
    int x = get(i);
    if (x < mn) {
      mn = x;
      l = i;
    }
    if (x == mn) {
      r = i;
    }
  }
  for (int d = -4; d <= +4; d++) {
    kol(0, l + d);
    kol(0, r + d);
  }
  for (int i = 1; i < N; i++) {
    upd();
  }
  cout << sol << "\n";
  for (int i = 1; i <= cb; i++) {
    cout << "B";
  }
  for (int i = 1; i <= cn; i++) {
    cout << "N";
  }
  cout << "\n";
  return 0;
}