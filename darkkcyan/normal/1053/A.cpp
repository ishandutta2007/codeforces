#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

llong n, m, k;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  if ((n * m * 2) % k) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int _ = 2; _--; swap(n, m)) {
    llong u = n * 2;
    llong v = m;
    llong tk = k;
    llong g = __gcd(u, tk);
    u /= g;
    tk /= g;
    g = __gcd(v, tk);
    v /= g;
    tk /= g;
    clog << u << ' ' << v << ' ' << tk << endl;
    if (tk > 1) continue;
    if (u > n) continue;
    if (_ == 0) swap(u, v);
    cout << "0 0\n" << "0 " << v << "\n" << u << " 0";
    break;
  }

  return 0;
}