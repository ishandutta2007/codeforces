#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef ll llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vi V(n);
    for (auto& x : V) cin >> x;
    sort(V.rbegin(), V.rend());
    ll x, a;
    ll y , b;
    cin >> x >> a >> y >> b;
    if (x < y) {
      swap(x,y);
      swap(a,b);
    }
    ll z = x+y;
    ll c = a*b/gcd(a,b);

    ll k;
    cin >> k;

    int i1 = 0;
    int i2 = n+1;
    while (i1 + 1 < i2) {
      int i3 = (i1+i2)/2;
      int cn = i3/c;
      int an = i3/a - cn;
      int bn = i3/b - cn;
      ll rr = 0;
      for (int i = 0; i < cn; ++i) rr += z*V[i]/100ll;
      for (int i = cn; i < cn + an; ++i) rr += x*V[i]/100ll;
      for (int i = cn + an; i < cn + an + bn; ++i) rr += y*V[i]/100ll;
      if (rr >= k) i2 = i3;
      else i1 = i3;
    }

    if (i2 == n+1) cout << -1 << '\n';
    else cout << i2 << '\n';
  }

}