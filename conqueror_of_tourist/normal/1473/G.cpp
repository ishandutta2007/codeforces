#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;

const ll mod = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

typedef vector<ll> vl;
void ntt(vl& a, vl& rt, vl& rev, int n) {
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
				ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
				ai += (ai + z >= mod ? z - mod : z);
	}
}

vl conv(const vl& a, const vl& b) {
	if (a.empty() || b.empty())
		return {};
	int s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
	vl L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
	ll curL = mod / 2, inv = modpow(n, mod - 2);
	for (int k = 2; k < n; k *= 2) {
		ll z[] = {1, modpow(root, curL /= 2)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	ntt(L, rt, rev, n); ntt(R, rt, rev, n);
	rep(i,0,n) out[-i & (n-1)] = L[i] * R[i] % mod * inv % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}

int n;
int a,b;

ll power(ll x, unsigned int y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % mod; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % mod;  // Change x to x^2 
    } 
    return res; 
}

vl fact;
vl invfact;

ll comb(int a, int b){
    if ((b < 0) || b > a) return 0;
    ll denom = (invfact[b] * invfact[a-b]) % mod;
    return (fact[a] * denom) % mod;
}

int BIG = 200010;

int main() { FAST
    fact.pb(1);
    for(int i = 1; i <= BIG; i++){
        fact.pb((i * fact[i-1]) % mod);
    }
    invfact = vl(BIG + 1, 0);
    invfact[BIG] = modpow(fact[BIG], mod - 2);
    for (int i = BIG-1;i>=0;i--){
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    }

    cin >> n;
    vl curr;
    curr.pb(1);
    int sz = 1;
    for(int iasd = 0; iasd < n; iasd++){
        cin >> a >> b;
        int nsz = sz + a - b;
        
        vl mult;
        for(int i = b - sz + 1; i < a + sz; i++){
            mult.pb(comb(a+b,i));
        }
        
                
        
        vl newv = conv(curr, mult);
        
        vl cut = {newv.begin() + sz - 1, newv.end()};
        
        //for (ll v : cut) cout << v << " ";
        //cout << '\n';
        
        while (cut.size() > nsz) cut.pop_back();
        
        curr = cut;
        
        //for (ll v : curr) cout << v << " ";
        //cout << '\n';
        
        sz = nsz;
    }
    ll out = 0;
    for (ll v : curr) out += v;
    cout << (out % mod);
}