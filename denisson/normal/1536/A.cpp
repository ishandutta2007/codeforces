#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    set<ll> a;
    for (int i = 0; i < n; ++i) { int x; cin >> x; a.insert(x); }

    int mi = *a.begin();
    int ma = *prev(a.end());

    if (mi < 0) {
      cout << "NO\n";
      continue;
    }

    ll g = ma;

    for (ll x : a) for (ll y : a) if (x != y) g = __gcd(g, abs(x - y));

    for (int x = g; x <= ma; x += g) {
      a.insert(x);
      if (a.size() > 300) break;
    }

    if (a.size() > 300) cout << "NO\n";
    else {
      cout << "YES\n" << a.size() << "\n";;
      for (ll x : a) cout << x << ' ';
      cout << "\n";
    }

  }


}