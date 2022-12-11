#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, a, m, d;
  cin >> n >> m >> a >> d;
  ll c = 0;
  vector<ll> V(m + 1);
  for (int i = 0; i < m; ++i) cin >> V[i];
  V[m] = max(V[m - 1],a*n);

  ll kp = d/a;
  ++kp;
  ll res = 0;
  for (int i = 0; i <= m; ++i) {
    if (V[i] <= c) continue;
    ll tta = (c + a)/a;
    if (tta > n) {
      ++res;
      c = V[i] + d;
      continue;
    }
    ll ppa = (V[i])/a;
    ppa = min(ppa, n);
    
    if (tta > ppa) {
      ++res;
      c = V[i] + d;
      continue;
    }
    ll tet =(ppa - tta)/kp; 
    res += tet;
    ll eps = a*(tta + tet*kp);
    if (V[i] > eps + d) {
      ++res;
      c = V[i] + d;
    }
    else {
      c = eps + d;
    }
    ++res;
  }
  cout << res << endl;
}