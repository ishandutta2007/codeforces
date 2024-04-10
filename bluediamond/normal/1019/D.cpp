#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 2000 + 7;
int n, pos[N];

struct pt {
  int x;
  int y;
};

ll f(pt a, pt b) {
  return (ll) (a.x - b.x) * (a.y + b.y);
}

ll f(pt a, pt b, pt c) {
  return f(a, b) + f(b, c) + f(c, a);
}

pt p[N];
int F, S;

ll f(int i, int j, int k) {
  return f(p[i], p[j], p[k]);
}

bool cmp(int i, int j) {
  return f(F, S, i) < f(F, S, j);
}

void print(int i, int j, int k) {
  cout << "Yes\n";
  cout << p[i].x << " " << p[i].y << "\n";
  cout << p[j].x << " " << p[j].y << "\n";
  cout << p[k].x << " " << p[k].y << "\n";
  exit(0);
}

void nope() {
  cout << "No\n";
  exit(0);
}

vector<int> ord;

void fnd(ll want) {
  int l = 0, r = (int) ord.size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (f(F, S, ord[m]) == want) print(F, S, ord[m]);
    if (f(F, S, ord[m]) < want) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
}

bool operator < (pt a, pt b) {
  return a.y < b.y;
}

struct seg {
  int i, j;
  ld ang;
};

bool operator < (seg a, seg b) {
  return a.ang < b.ang;
}

signed realMain() {
  ll want;
  cin >> n >> want;
  want *= 2;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  sort(p + 1, p + n + 1);
  vector<seg> prs;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ld ang = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
      prs.push_back({i, j, ang});
    }
  }
  sort(prs.begin(), prs.end());
  for (int k = 1; k <= n; k++) {
    ord.push_back(k);
    pos[k] = k - 1;
  }
  for (auto &it : prs) {
    int i = it.i, j = it.j;
    int posi = pos[i], posj = pos[j];
    swap(ord[posi], ord[posj]);
    swap(pos[i], pos[j]);
    F = i;
    S = j;
    /// binary search stuff
    fnd(want);
    fnd(-want);
  }
  nope();
  return 0;
}