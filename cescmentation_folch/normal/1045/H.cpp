#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const ll mod = 1e9+7;

vi F;

ll expo(ll x, ll e) {
  if (e == 0) return 1;
  ll k = expo(x*x%mod, e/2);
  if (e%2) return k*x%mod;
  return k;
}

ll inv(ll x) {
  return expo(x, mod-2);
}

ll ncr(ll n, ll k) {
  if (k > n or n < 0 or k < 0) return 0;
  return F[n]*inv(F[k]*F[n-k]%mod)%mod;
}


ll resl(string& A, int n, int C00, int C01, int C10, int C11) {
  ll res = 0;
  int C[2][2];
  C[0][0] = C00;
  C[1][0] = C10;
  C[0][1] = C01;
  C[1][1] = C11;
  for (int i = 1; i < n; ++i) {
    int ant = A[i-1] - '0';
    int act = A[i] - '0';
    if (act and C[ant][0]) {
      --C[ant][0];
      if (C[0][0] == n-i-1) {
        res = (res+1)%mod;
      }
      else if (C[0][1] and (C[0][1] == C[1][0] + 1 or C[0][1] == C[1][0])) {
        int tt = 0;
        if (C[0][1] == C[1][0]+1) tt = 1;
        ll val = ncr(C[0][0] + C[1][0], C[0][1]-tt)*ncr(C[1][1] + C[0][1] -1, C[0][1] - 1)%mod;
        res = (res+val)%mod;
      }
      ++C[ant][0];
    }
    if (!C[ant][act]) return res;
    --C[ant][act];
  }
  return (res+1)%mod;
}

ll res2l(string& A, int n, int C00, int C01, int C10, int C11) {
  int C[2][2];
  C[0][0] = C00;
  C[1][0] = C10;
  C[0][1] = C01;
  C[1][1] = C11;
  for (int i = 1; i < n; ++i) {
    int ant = A[i-1] - '0';
    int act = A[i] - '0';
    if (!C[ant][act]) return 0;
    --C[ant][act];
  }
  return 1;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string A, B;
  cin >> A >> B;
  int C00, C01, C10, C11;
  cin >> C00 >> C01 >> C10 >> C11;
  int n = C00 + C01 + C10 + C11 + 1;
  if (A.size() > n or B.size() < n) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (A.size() < n) {
    A = "1" + string(n-1, '0');
  }
  if (B.size() > n) {
    B = string(n, '1');
  }
  F = vi(n+1);
  F[0] = 1;
  for (ll i = 1; i <= n; ++i) F[i] = F[i-1]*i%mod;
  ll res = resl(B,n, C00, C01, C10, C11) - resl(A,n, C00, C01, C10, C11) + res2l(A,n, C00, C01, C10, C11) + mod; 
  cout << res%mod << endl;
}