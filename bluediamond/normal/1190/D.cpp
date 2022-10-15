#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  int x;
  int y;
};

bool operator < (T a, T b) {
  if (a.y == b.y) {
    return a.x < b.x;
  }
  return a.y > b.y;
}

const int N = (int) 2e5 + 7;
int n;
bool u[N];
int t[N];
T a[N];

void activate(int x) {
  if (u[x] == 0) {
    u[x] = 1;
    for (int i = x; i <= n; i += i & (-i)) {
      t[i]++;
    }
  }
}

int prefix(int p) {
  int sol = 0;
  for (int i = p; i >= 1; i -= i & (-i)) {
    sol += t[i];
  }
  return sol;
}

int get(int l, int r) {
  if (l > r) {
    return 0;
  }
  return prefix(r) - prefix(l - 1);
}

ll gauss(ll x) {
  return x * (x + 1) / 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  map<int, int> t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    t[a[i].x] = 0;
  }
  int cur = 0;
  for (auto &it : t) {
    it.second = ++cur;
  }
  for (int i = 1; i <= n; i++) {
    a[i].x = t[a[i].x];
  }
  sort(a + 1, a + n + 1);
  ll sol = 0;
  int l = 1;
  while (l <= n) {
    int r = l;
    while (r + 1 <= n && a[l].y == a[r + 1].y) {
      r++;
    }
    ll now = -gauss(get(1, a[l].x - 1));
    now -= gauss(get(a[r].x + 1, n));
    for (int j = l; j < r; j++) {
      now -= gauss(get(a[j].x + 1, a[j + 1].x - 1));
    }
    for (int j = l; j <= r; j++) {
      activate(a[j].x);
    }
    now += gauss(get(1, n));
    sol += now;
    l = r + 1;
  }
  cout << sol << "\n";
}