
#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define xx first
#define yy second

string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}

bool ispalin(string s) {
  return s == rev(s);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int ans = 0;
  rep(i, len(s))
    for (int f = i; f < len(s); ++f) {
      if (!ispalin(s.substr(i, f - i + 1))) ans = max(ans, f - i + 1);
    }

  cout << ans;

  return 0;
}