#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

bool home = 1;

int xp, yp;
int xv, yv;

void p() {
  cout << "Polycarp\n";
  exit(0);
}

void v() {
  cout << "Vasiliy\n";
  exit(0);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> xp >> yp >> xv >> yv;


  /**
  p(x, y) -> (x - 1, y) sau (x, y - 1)
  v(x, y) -> (x - 1, y) sau (x - 1, y - 1) sau (x, y - 1)
  **/


  int distp = xp + yp;
  int distv = max(xv, yv);

  if (distp <= distv) p();
  if (xp <= xv && yp <= yv) p();
  v();

  return 0;
}
/**

**/