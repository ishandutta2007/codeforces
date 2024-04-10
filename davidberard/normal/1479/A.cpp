#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

map<int, int> mp;
int n;

int query(int x) {
  if (mp.count(x)) {
    return mp[x];
  }
  cout << "? " << x << endl;
  int y;
  cin >> y;
  return mp[x] = y;
}

bool is_locmin(int x) {
  int a = query(x-1);
  int b = query(x);
  int c = query(x+1);
  return b < a && b < c;
}

bool point_down(int x, int y) {
  if (x == y) return false;
  //cerr << " :: " << query(x) << "-> " << query(x+1) << " ; " << query(y-1) << " <- " << query(y) << endl;
  return (query(x) > query(x+1) && query(y-1) < query(y));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  mp[0] = mp[n+1] = 1e9;
  int lo = 1, hi = n;
  if (is_locmin(lo)) {
    cout << "! " << lo << endl;
    return 0;
  }
  if (is_locmin(hi)) {
    cout << "! " << hi << endl;
    return 0;
  }
  while (lo<hi) {
    int mid = (lo+hi)/2;
    if (is_locmin(mid)) {
      cout << "! " << mid << endl;
      return 0;
    }
    if (point_down(lo, mid)) {
      hi = mid;
    } else if (point_down(mid, hi)) {
      lo = mid;
    } else {
      assert(false);
    }
  }
  assert(false);
  return 0;
}