#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int mod = 1000000007;

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

const int N = 1000007;
int pa[N];
int pb[N];

ll gcdex (ll a, ll b, ll & x, ll & y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  ll x1, y1;
  ll d = gcdex (b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

ll get_r(ll a, ll m) {
  ll x, y;
  ll g = gcdex (a, m, x, y);
  x = (x % m + m) % m;
  return x;
}


int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  ll n, m;
  ll k;
  cin >> n >> m >> k;

  vector<int> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  for (int i = 0; i < n; ++i) {
    pa[a[i]] = i+1;
  }

  for (int i = 0; i < m; ++i) {
    pb[b[i]] = i+1;
  }

  vector<pair<ll, ll> > eq_sol;
  ll G = __gcd(n, m);
  ll Z = get_r(m/G, n/G);
  mod = n/G;

  for (int i = 0; i < N; ++i) {
    if (!pa[i] || !pb[i]) continue;
    ll x = pa[i] - 1, y = pb[i] - 1;
    if (x%G != y%G) {
      eq_sol.pb(mp(-1, -1));
      continue;
    }

    ll ty = y;

    x /= G;
    y /= G;


    x = (((x - y) % mod) + mod) % mod;
    x = (x * Z) % mod;
    x *= m;
    x += ty+1;

    eq_sol.pb(mp(x, (ll) n * m / G));
    //cout << i << " " << x << " " << (ll) n * m / G << endl;

  }

  ll L = 0, R = 2e18;
  while (R-L>1) {
    ll M = (L+R)/2;
    ll dop = 0;
    int u = 0;
    for (int i = 0; i < N; ++i) {
      if (!pa[i] || !pb[i]) continue;
      if (eq_sol[u].x == -1) {
        u++;
        continue;
      }
      ll delta = (M - eq_sol[u].x + eq_sol[u].y) / eq_sol[u].y;
      dop += delta;
      u++;
    }
    if (M - dop >= k) R = M;
    else L = M;
  }
  cout << R;

}