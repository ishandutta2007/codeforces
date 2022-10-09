#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  llong n; cin >> n;
  vector<llong> ans;
  for (llong i = 1; i <= 10 * 9; ++i) {
    llong t = n - i, s = 0;
    if (t <= 0) break;
    for (; t; t /= 10) s += t % 10;
    if (s == i) ans.push_back(n - i);
  }
  
  cout << len(ans) << '\n';
  sort(ans.begin(), ans.end());
  for (auto i: ans) cout << i << '\n';
  
  return 0;
}