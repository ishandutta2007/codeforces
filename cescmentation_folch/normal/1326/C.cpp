#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const ll mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi P(n);
  for (int i = 0; i < n; ++i) cin >> P[i];
  ll res1 = 0;
  vi S;
  for (int i = 0; i < n; ++i) {
    if (P[i] > n-k) {
      res1 += P[i];
      S.push_back(i);
    }
  }
  ll res2 = 1;
  for (int i = 1; i < (int)S.size(); ++i) {
    ll d = S[i] - S[i-1];
    ll v = d;
    v %= mod;
    res2 = (res2*v)%mod;
  }
  cout << res1 << ' ' << res2 << '\n';
}