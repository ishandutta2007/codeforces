#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2002*2002;
const ll MOD = 1e9+7;

ll tpow[N];
void setup() {
  tpow[0] = 1;
  for (int i=1; i<N; ++i) {
    tpow[i] = tpow[i-1]*2%MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int TT;
  cin >> TT;
  while (TT--) {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    string s;
    for (int i=0; i<n; ++i) {
      cin >> s;
      for (auto& x : s) {
        if (x == '#') {
          ++cnt;
        }
      }
    }
    ll ans = tpow[cnt]%MOD;
    if (n*m == cnt) {
      ans = (ans+MOD-1)%MOD;
    }
    cout << ans << "\n";
  }
  return 0;
}