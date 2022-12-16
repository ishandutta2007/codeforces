#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;
const ll N = 200100;

ll modpow(ll b, ll p) {
  ll ans = 1;
  for (; p; p/=2, b=b*b%MOD) {
    if (p&1) {
      ans = ans*b%MOD;
    }
  }
  return ans;
}

ll fac[N], ifac[N];

void setup() {
  fac[0] = ifac[0] = 1;
  for (int i=1; i<N; ++i) {
    fac[i] = fac[i-1]*i%MOD;
  }
  ifac[N-1] = modpow(fac[N-1], MOD-2);
  //cerr << " IFAC " << N-1 << " : " << ifac[N-1] << endl;
  for (int i=N-2; i>0; --i) {
    ifac[i] = ifac[i+1]*(i+1)%MOD;
    if (i <10) {
      //cerr << " IFAC " << i << " :: "<< ifac[i] << " ,, fac[i]*ifac[i] = " << ifac[i]*fac[i]%MOD << endl;
    }
  }
}
ll choose(ll n, ll k) {
  assert(n >= k);
  assert(0 <= k);
  //cerr << " N" << n << " K" << k << " : " << fac[n] << " " << ifac[k] << " " << ifac[n-k] << endl;
  return (fac[n]*ifac[k]%MOD)*ifac[n-k]%MOD;
}

ll f, w, h;
ll den, num;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  cin >> f >> w >> h;
  if (w == 0) {
    cout << "1\n";
    return 0;
  }
  if (w <= h) {
    cout << "0\n";
    return 0;
  } 
  if (f == 0) {
    cout << "1\n";
    return 0;
  }

  for (int i=1; i<=w; ++i) {
    // i = # of wine stacks
    int wc = i;
    for (int j=-1; j<=1; ++j) {
      if (i+j == 0) continue;
      int fc = i+j;
      if (fc > f) {
        continue;
      }
      den += choose(w-1, wc-1)*choose(f-1, fc-1)*(j==0?2:1)%MOD;
      if (wc*(h+1) <= w) {
        num += choose(w-wc*h-1, wc-1)*choose(f-1, fc-1)*(j==0?2:1)%MOD;
      }
    }
  }
  cout << (num%MOD)*modpow(den%MOD, MOD-2)%MOD << "\n";
  return 0;
}