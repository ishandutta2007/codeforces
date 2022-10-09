#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int n, k;
int cnt[1 << 5];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep(i, n) {
    int u = 0;
    rep(f, k) {
      int t; cin >> t;
      u = u << 1 | t;
    }
    cnt[u] ++;
  }
  
  #define YES return cout << "YES", 0
  if (cnt[0]) YES;
  
  rep(i, (1 << k)) {
    rep(f, (1 << k)) {
      if (cnt[i] and cnt[f] and (i & f) == 0) YES;
    }
  }
  
  cout << "NO";
  
  return 0;
}