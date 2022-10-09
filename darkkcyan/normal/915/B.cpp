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
  int n, p, l, r;
  cin >> n >> p >> l >> r;
  if (l == 1 and r == n)
    cout << 0;
  else if (l == 1) cout << 1 + abs(r - p);
  else if (r == n) cout << 1 + abs(p - l);
  else cout << 2 + min(abs(r - p), abs(p - l)) + (r - l);

  return 0;
}