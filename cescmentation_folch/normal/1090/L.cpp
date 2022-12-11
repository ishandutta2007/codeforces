#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll t, n, a, b, k;
  cin >> t >> n >> a >> b >> k;
  ll l = 0;
  ll r = t+1;
  while (l + 1 < r) {
    ll c = (l+r)/2;
    ll val = min(a,c)*((n+1)/2) + min(b,c)*(n/2);
    if (val >= c*k) l = c;
    else r = c;
  }
  cout << l << endl;
}