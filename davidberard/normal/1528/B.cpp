#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1001000;
const ll MOD = 998244353;
int dc[N];
ll f[N];

void setup() {
  for (int i=1; i<N; ++i) {
    for (int j=i; j<N; j+=i) {
      ++dc[j];
    }
  }
  f[1] = 1;
  ll sm = 1;
  for (int i=2; i<N; ++i) {
    f[i] = (sm + dc[i])%MOD;
    sm = (sm+f[i])%MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int n;
  cin >> n;
  cout << f[n] << "\n";
  return 0;
}