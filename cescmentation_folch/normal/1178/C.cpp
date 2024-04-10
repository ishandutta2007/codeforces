#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

ll mod = 998244353;

ll expo(ll e) {
  if (e == 0) return 1;
  ll k = expo(e/2);
  k = k*k%mod;
  if (e%2) return k*2ll%mod;
  return k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll h, w;
  cin >> h >> w;
  cout << expo(h+w) << endl;
}