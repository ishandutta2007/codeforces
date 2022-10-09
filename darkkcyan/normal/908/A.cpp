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
  string s; cin >> s;
  int ans = 0;
  for (auto i: s) {
    if (isdigit(i)) ans += (i - '0') % 2;
    else ans += string("aeiou").find(i) != string::npos;
  }
  cout << ans;
  
  return 0;
}