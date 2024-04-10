#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define sz(v) ((int)v.size())

string s, t;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  cin >> s >> t;
  assert(sz(s) <= sz(t));
  int ans = 1e9, st = 0;
  rep(i, m - n + 1) {
    int x = 0;
    rep(f, n) x += s[f] != t[f + i];
    if (ans > x) {
      ans = x;
      st = i;
    }
  }
  cout << ans << '\n';
  rep(f, n)
    if (s[f] != t[st + f]) cout << f + 1 << ' ';
  return 0;
}