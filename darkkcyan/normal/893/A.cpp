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
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int t = 3;
  rep(i, n) {
    int u; cin >> u;
    if (u == t) {
      cout << "NO";
      return 0;
    }
    t = 6 - t - u;
  }
  cout << "YES";

  return 0;
}