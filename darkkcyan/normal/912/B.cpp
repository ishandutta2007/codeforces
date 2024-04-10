#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define ii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong k, n; cin >> n >> k;
  if (k == 1) cout << n;
  else {
    int mb = 0;
    for (llong i = n; i > 1; i >>=1, ++mb);
    
    cout << ((1ULL << mb) ^ ((1ULL << mb) - 1));
  }

  return 0;
}