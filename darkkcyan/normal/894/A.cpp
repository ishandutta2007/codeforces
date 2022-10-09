#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  string s;
  cin >> s;
  llong ans = 0;
  rep(i, len(s)) {
    if (s[i] != 'Q') continue;
    for (int f = i + 1; f < len(s); ++f) {
      if (s[f] != 'A') continue;
      for (int g = f + 1; g < len(s); ++g) ans += s[g] == 'Q';
    }
  }
  cout << ans;


  return 0;
}