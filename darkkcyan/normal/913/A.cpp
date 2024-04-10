
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n;)
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define ii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong n, m;
  cin >> n >> m;
  llong p = 1;
  while (n-- and p <= m) {
    p *= 2;
  }
  cout << m % p;

  return 0;
}