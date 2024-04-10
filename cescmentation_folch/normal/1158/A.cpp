#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll ma = 0;
  ll ma2 = 0;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    res += x*m;
    if (x >= ma) {
      ma2 = ma;
      ma = x;
    } else if (x > ma2) {
      ma2 = x;
    }
  }
  ll mi = 1e9;
  for (int i = 0; i < m; ++i) {
    ll x;
    cin >> x;
    res += x - ma;
    if (x < mi) mi = x;
  }
  if (mi > ma) res += ma - ma2;
  if (mi < ma) cout << -1 << endl;
  else cout << res << endl;
}