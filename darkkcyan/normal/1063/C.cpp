#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

int n;

bool ask(int x, int y) {
  --n;
  //clog << " n = " << n << endl;
  cout << x << ' ' << y << endl;
  string col; cin >> col;
  return tolower(col[0]) == 'w';   // just for safe, you know ;)
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  int curx = 0;
  bool lastc = ask(0, 0);
  bool c = lastc;
  while (n > 0) {
    curx += 2;
    c = ask(curx, 0);
    if (c != lastc) break;
  }

  if (n == 0) {
    cout << curx + (c == lastc ? 1 : -1) << ' ' << 0 << ' ' << curx + 1 << ' ' << 1 << endl;
    return 0;
  }

  int maxy = 1 << 29;

  ii firstPoint(curx - 1, 0);
  c = ask(curx - 1, maxy);

  bool lowc;
  if (c == lastc) {
    //curx = curx;
    lowc = !lastc;
  } else {
    curx = curx - 2;
    lowc = lastc;
  }

  lastc = c;

  int l = 0, r = maxy;
  while (n > 0) {
    int mid = l + (r - l) / 2;
    c = ask(curx, mid);
    if (c == lowc) l = mid;
    else r = mid;
  }

  cout << firstPoint.xx << ' ' << firstPoint.yy << ' ' << curx << ' ' << (l + (r - l) / 2) << endl;

  return 0;
}