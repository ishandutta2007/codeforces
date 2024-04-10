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
  llong a, b; cin >> a >> b;
  llong lcm = a / __gcd(a, b) * b;
  llong u = lcm / a, v = lcm / b;
  if (a > b) ++u; else ++v;
  if (u < v) cout << "Masha";
  else if (u > v) cout << "Dasha";
  else cout << "Equal";
  
  return 0;
}