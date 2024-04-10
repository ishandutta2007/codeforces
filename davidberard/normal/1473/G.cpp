#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define sz(a) ((ll) a.size())
#define rep(i,a,b) for(int i=a; i<b; ++i)
using vi = vector<int>;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
const int LIM = 1000;
vl conv_small(const vl& a, const vl& b) {
  vl ans(sz(a)+sz(b)-1);
  for (int i=0; i<sz(a); ++i) {
    for (int j=0; j<sz(b); ++j) {
      ans[i+j] = (ans[i+j] + a[i]*b[j])%mod;
    }
  }
  return ans;
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
  if (a.size() < LIM) {
    return conv_small(b, a);
  }
  if (b.size() < LIM) {
    return conv_small(a, b);
  }
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

const int N = 200200;
ll fac[N], ifac[N];
void setup() {
  fac[0]  =ifac[0] = 1;
  for (int i=1; i<N; ++i) {
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = modpow(fac[i], mod-2);
  }
}
ll choose(int n, int k) {
  assert(0 <= k && k <= n);
  ll ans = (fac[n]*ifac[k]%mod)*ifac[n-k]%mod;
  return ans;
}

ll a[N], b[N], q[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int n;
  cin >> n;
  q[0] = 1;
  for (int i=1; i<=n; ++i) {
    cin >> a[i] >> b[i];
    q[i] = q[i-1] + a[i] - b[i];
  }
  vector<ll> cur = {1};
  vector<ll> chooses;
  for (int i=1; i<=n; ++i) {
    chooses.clear();
    int lb = max(0LL, b[i]-q[i-1]);
    int rb = min(a[i]+b[i], b[i]+q[i]);
    for (int j=lb; j<=rb; ++j) {
      chooses.push_back(choose(a[i]+b[i], j));
    }
    vector<ll> res = conv(cur, chooses);
    cur.resize(q[i]);
    for (int j=0; j<q[i]; ++j) {
      cur[j] = res[b[i]+j-lb];
    }
  }
  ll ans = 0;
  for (int i=0; i<q[n]; ++i) {
    ans += cur[i];
  }
  cout << ans%mod << "\n";
  return 0;
}