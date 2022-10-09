#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
int cnt[5010];
string s;

int get(int l, int r) {
  r = min(r, len(s) - 1);
  l = max(l, 0);
  return r < 0 ? 0 : cnt[r] - (l ? cnt[l - 1] : 0);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s;
  rep(i, len(s)) {
    cnt[i] = (s[i] == 'a') + (i ? cnt[i - 1] : 0);
  }
  
  int ans = 0;
  rep(i, len(s)) for (int f = i - 1; f < len(s); ++f) {
    ans = max(ans, get(0, i - 1) + get(f + 1, len(s) - 1) + f - i + 1 - get(i, f));
  }
  cout << ans;
  
  return 0;
}