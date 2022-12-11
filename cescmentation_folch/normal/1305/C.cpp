#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 << '\n';
    return 0;
  }
  vi V(n);
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
  }
  ll res = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      res = res*abs(V[i] - V[j])%m;
    }
  }
  cout << res << '\n';
}