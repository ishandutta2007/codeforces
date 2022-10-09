#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n, m;
llong a[maxn], b[maxn];

bool ok(llong t) {
  int p = 0;
  rep(i, n) {
    int op = p;
    while (p < m and b[p] - b[op] + min(abs(a[i] - b[p]), abs(a[i] - b[op])) <= t) ++p;
  }
  return p == m;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  llong l = 0, r = 3e10;
  while (l < r) {
    llong mid = l + (r - l) / 2;
    if (ok(mid)) r = mid;
    else l = mid + 1;
  }
  cout << l;
  
  return 0;
}