#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 200200;
const ll MOD = 998244353;

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
  for (int i=N-2; i>=1; --i) {
    ifac[i] = ifac[i+1]*(i+1)%MOD;
  }
}

ll choose(int n, int k) {
  return fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += 'x';
    char last = 'x';
    int cnt = 0;
    int zero = 0, opair = 0;
    for (auto& c : s) {
      if (c != last) {
        if (last == '0') {
          zero += cnt;
        } else if (last == '1') {
          opair += cnt/2;
        }
        cnt = 0;
        last = c;
      }
      cnt++;
    }
    cout << choose(opair+zero, zero) << "\n";

  }
  return 0;
}