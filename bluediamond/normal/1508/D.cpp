#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 2000 + 7;
int val[N];

struct pt {
  int x, y, ind;
};

bool operator < (pt a, pt b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

int f(pt a, pt b) {
  return (a.x - b.x) * (a.y + b.y);
}

int f(pt a, pt b, pt c) {
  return f(a, b) + f(b, c) + f(c, a);
}

int n;
pt p[N];

bool cmp(pt a, pt b) {
  return f(p[1], a, b) > 0;
}

int tstamp, last[N];

bool same_cycle(int a, int b) {
  assert(a != b);
  tstamp++;
  while (last[a] != tstamp) {
    last[a] = tstamp;
    a = val[a];
    if (a == b) return 1;
  }
  return 0;
}

vector<pair<int, int>> lines;

void swp(int i, int j) {
  lines.push_back({i, j});
  swap(val[i], val[j]);
}

int sz;

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    val[i] = a;
    if (a != i) {
      p[++sz] = {x, y, i};
    }
  }
  if (sz == 0) {
    cout << "0\n";
    return 0;
  }
  n = sz;
  for (int i = 2; i <= n; i++) {
    if (p[i] < p[1]) {
      swap(p[i], p[1]);
    }
  }
  sort(p + 2, p + n + 1, cmp);
  for (int i = 3; i <= n; i++) {
    if (!same_cycle(p[i - 1].ind, p[i].ind)) {
      swp(p[i - 1].ind, p[i].ind);
    }
  }
  while (val[p[1].ind] != p[1].ind) {
    swp(p[1].ind, val[p[1].ind]);
  }
  cout << (int) lines.size() << "\n";
  for (auto &i : lines) {
    cout << i.first << " " << i.second << "\n";
  }
  return 0;
}