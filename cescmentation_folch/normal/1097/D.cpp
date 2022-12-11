#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;

ll mod = 1e9 + 7;

ll ex(ll x, ll e) {
  if (e == 0) return 1;
  ll k = ex((x*x)%mod, e/2);
  if (e%2) return (k*x)%mod;
  return k;
}

ll inv(ll x) {
  return ex(x, mod - 2);
}

const int M = 10010;
const int S = 70;

ll D[M][S];

ll calc(ll x,int s, int k) {
  D[0][0] = 1;
  for (int i = 1; i <= s; ++i) D[0][i] = (x*D[0][i-1])%mod; 
  for (int j = 1; j <= k; ++j) {
    ll sum = 0;
    for (int i = 0; i <= s; ++i) {
      sum = (sum + D[j-1][i])%mod;
      D[j][i] = (sum*inv(i+1))%mod;
    }
  }
  return D[k][s];
}

int main() {
  ll n;
  int k;
  cin >> n >> k;
  ll res = 1;
  for (ll i = 2; i*i <= n; ++i) {
    if (n%i == 0) {
      int cont = 0;
      while (n%i == 0) {
        ++cont;
        n /= i;
      }
      res = (res*calc(i, cont, k))%mod;
    }
  }
  if (n > 1) res = (res*calc(n,1,k))%mod;
  cout << res << '\n';
}