#include<bits/stdc++.h>
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong n, m, a, b; cin >> n >> m >> a >> b;
  llong u = n % m, v = m - u;
  cout << min(u * b, v * a) ;

  return 0;
}