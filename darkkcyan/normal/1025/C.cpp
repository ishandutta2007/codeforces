#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

string s;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s;
  int ans = 0;
  s += s;
  int l = 0, r = 0;
  for (r = 1; r < len(s); ++r) { 
    if (s[r] == s[r - 1]) {
      ans = max(ans, r - l);
      l = r;
    }
  }
  ans = max(ans, r - l);
  ans = min(ans, len(s) / 2);
  cout << ans;
  
  
  return 0;
}