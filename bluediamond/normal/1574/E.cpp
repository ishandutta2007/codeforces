#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = (int) 1e6 + 7;
int n, m, k, bad[2], la[2];
set<pair<int, int>> forced;
map<pair<int, int>, int> val;
int errors[2];
int fr[2][N][2], kek[2];

void upd(int type, int pos, int value, int tg) {
  errors[type] -= (fr[type][pos][0] > 0 && fr[type][pos][1] > 0);
  kek[type] += (fr[type][pos][0] > 0 || fr[type][pos][1] > 0);
  fr[type][pos][value] += tg;
  errors[type] += (fr[type][pos][0] > 0 && fr[type][pos][1] > 0);
  kek[type] -= (fr[type][pos][0] > 0 || fr[type][pos][1] > 0);
}

void del(int x, int y) {
  if (forced.count({x, y})) {
    forced.erase({x, y});
    bad[0] -= (x + y + val[{x, y}]) % 2;
    bad[1] -= (x + y + 1 + val[{x, y}]) % 2;

    upd(0, y, (x % 2) ^ val[{x, y}], -1);
    upd(1, x, (y % 2) ^ val[{x, y}], -1);
  }
}

void ins(int x, int y) {
  forced.insert({x, y});
  bad[0] += (x + y + val[{x, y}]) % 2;
  bad[1] += (x + y + 1 + val[{x, y}]) % 2;

  upd(0, y, (x % 2) ^ val[{x, y}], +1);
  upd(1, x, (y % 2) ^ val[{x, y}], +1);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> m >> k;
  kek[0] = m;
  kek[1] = n;

  while (k--) {
    int x, y, tp;
    cin >> x >> y >> tp;
    if (tp == -1) {
      del(x, y);
    } else {
      del(x, y);
      val[{x, y}] = tp;
      ins(x, y);
    }
    int scad = (bad[0] == 0) + (bad[1] == 0), sol = 0;
    for (int i = 0; i < 2; i++) {
      if (!errors[i]) {
        sol = add(sol, pw(2, kek[i]));
      }
    }
    cout << add(sol, -scad) << "\n";
  }


  return 0;
}