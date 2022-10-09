#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<llong> a(1);
  rep(i, n) {
    int u; cin >> u;
    a.push_back(a.back() + u);
  }

  rep1(i, n) {
    if (a[i] >= (a.back() + 1) / 2) {
      cout << i;
      break;
    }
  }


  return 0;
}