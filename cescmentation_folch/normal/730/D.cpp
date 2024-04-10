#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FOR(a, b, i) for (int i = a; i < b; ++i)

void mec() {
  cout << -1 << '\n';
  exit(0);
}

const ll N = 100000;
ll l[2*N + 10];
ll t[2*N + 10];
ll start[2*N + 10];
ll ans[N + 10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, r;
  cin >> n >> r;
//   vi l (n), t (n), start (n + 1, 0);
  FOR(0, n, i) cin >> l[i];
  FOR(0, n, i) cin >> t[i];
//   vi ans;
  ll saiz = 0;
  ll d = 0;
  FOR(0, n, i) {
    //cerr << i << ' ' << d << '\n';
    if (l[i] > t[i]) mec();
    else if (d > l[i]) {
      d -= l[i];
      start[i + 1] = start[i] + l[i];
    }
    else {
      l[i] -= d;
      t[i] -= d;
      if (t[i] >= 2 * l[i]) {
	start[i + 1] = start[i] + 2 * l[i] + d;
	d = 0;
      }
      else {
	ll m = t[i] - l[i];
	ll inc = (l[i] - m + r - 1) / r;
	saiz += inc;
	start[i + 1] = start[i] + d + m + l[i];
        if (saiz <= N){
	  for (ll j = inc; j > 0; --j) ans[saiz - j] = (start[i] + d + 2*m + (inc - j) * r);
        }
	d = inc * r + m - l[i];
      }
    }
  }
  cout << saiz << '\n';
  if (saiz <= N) {
    FOR(0, saiz, i) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
  }
}