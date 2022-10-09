#include<bits/stdc++.h>
using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )

int n, k;

bool ok(int dia) {
  int h = dia / 2;
  llong s = dia - 1;
  s += (llong)(k - 2) * (h - 1);
  return s >= n - k;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  int l = 2, r = n - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) r = mid;
    else l = mid + 1;
  }

  cout << l << '\n';
  
  rep1(i, l - 2) {
    cout << i << ' ' << i + 1 << '\n';
  }

  int root = l / 2;
  int leaf = n - k + 1;
  int nxt = l;
  cout << leaf++ << ' ' << 1 << '\n';
  cout << leaf++ << ' ' << l - 1 << '\n';

  rep(_, k - 2) {
    int last = root;
    rep(_, l / 2 - 1) {
      if (nxt > n - k) break;
      cout << last;
      last = nxt;
      cout << ' ' << nxt ++ << '\n';
    }
    cout << last << ' ' << leaf++ << '\n';
  }

  return 0;
}