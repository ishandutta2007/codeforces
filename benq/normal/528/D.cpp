#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

const ll mod = (119 << 23) + 1, root = 3; // = 998244353

typedef vector<ll> vl;

ll modpow(ll b, ll p) { // mod is prime
    ll ans = 1;
    while (p) {
        if (p&1) ans = ans*b % mod;
        p >>= 1;
        b = b*b % mod;
    }
    return ans;
}

void ntt(ll* x, ll* temp, ll* roots, int N, int skip) {
	if (N == 1) return;
	int n2 = N/2;
	ntt(x     , temp, roots, n2, skip*2);
	ntt(x+skip, temp, roots, n2, skip*2);
    F0R(i,N) temp[i] = x[i*skip];
    F0R(i,n2) {
		ll s = temp[2*i], t = temp[2*i+1] * roots[skip*i];
		x[skip*i] = (s + t) % mod; x[skip*(i+n2)] = (s - t) % mod;
	}
}

void ntt(vl& x, bool inv = false) {
	ll e = modpow(root, (mod-1) / int(x.size()));
	if (inv) e = modpow(e, mod-2);
	vl roots(x.size(), 1), temp = roots;
	FOR(i,1,x.size()) roots[i] = roots[i-1] * e % mod;
	ntt(&x[0], &temp[0], &roots[0], x.size(), 1);
}

vl operator+(const vl& a, const vl& b) {
    vl c = a; 
    F0R(i,b.size()) c[i] += b[i];
    return c;
}

vl conv(vl a, vl b) {
	int s = int(a.size()) + int(b.size()) - 1; if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
	if (s <= 200) { // (factor 10 optimization for |a|,|b| = 10)
		vl c(s);
		F0R(i,a.size()) F0R(j,b.size())
			c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
		return c;
	}
	a.resize(n); ntt(a);
	b.resize(n); ntt(b);
	vl c(n); ll d = modpow(n, mod-2);
	F0R(i,n) c[i] = a[i] * b[i] % mod * d % mod;
	ntt(c, true); c.resize(s); 
	F0R(i,s) c[i] = (c[i]%mod+mod)%mod;
	return c;
}

int s[200000], t[200000], co[4], S, T, K;
map<char,int> m;
vl v[4], V[4];

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	m['A'] = 0, m['C'] = 1, m['G'] = 2, m['T'] = 3;
	cin >> S >> T >> K;
	F0R(i,4) v[i].resize(S), V[i].resize(T);
	F0R(i,S) {
	    char c; cin >> c;
	    s[i] = m[c];
	}
	F0R(i,T) {
	    char c; cin >> c;
	    t[i] = m[c]; V[t[i]][T-1-i] = 1;
	}
}

int main() {
	init();
	int l = 0, r = -1;
	F0R(i,S) {
	    while (l < i-K) co[s[l++]] --;
	    while (r < min(i+K,S-1)) co[s[++r]] ++;
	    F0R(j,4) if (co[j]) v[j][i] = 1;
	}
	vl v0 = conv(v[0],V[0]);
	vl v1 = conv(v[1],V[1]);
	vl v2 = conv(v[2],V[2]);
	vl v3 = conv(v[3],V[3]);
	vl su = v0+v1+v2+v3;
	
	int ans = 0;
	F0R(i,S-T+1) if (su[T-1+i] == T) {
	    ans++;
	    //cout << i << "\n";
	}
	cout << ans;
}

// read!
// ll vs. int!