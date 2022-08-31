// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/NTT.h
// thanks ksun48

#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const ll mod = (119 << 23) + 1, root = 3; 

typedef vector<ll> vl;

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
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
	ll e = modpow(root, (mod-1) / x.size());
	if (inv) e = modpow(e, mod-2);
	vl roots(x.size(), 1), temp = roots;
	FOR(i,1,x.size()) roots[i] = roots[i-1] * e % mod;
	ntt(&x[0], &temp[0], &roots[0], x.size(), 1);
}

vl conv(vl a, vl b) {
	int s = a.size()+b.size()-1; if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
	
	a.resize(n); ntt(a);
	b.resize(n); ntt(b);
	
	vl c(n); ll d = modpow(n, mod-2);
	F0R(i,n) c[i] = a[i] * b[i] % mod * d % mod;
	ntt(c, true); c.resize(s); return c;
}

vector<ll> v1, v2, v3;
string str;
int n, ok[550000], bad[550000];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	F0R(t,T) {
		v1.clear(); v2.clear(); v3.clear();
		cin >> n >> str;
		FOR(i,1,n+1) ok[i] = 1, bad[i] = 1;
		
		F0R(i,n) v1.pb(str[i] == 'V');
		F0R(i,n) v2.pb(str[n-1-i] == 'K');
		
		v3 = conv(v1,v2);
		F0R(i,v3.size()) {
			v3[i] %= mod;
			if(v3[i] == 0) continue;
			bad[abs(i-(n-1))] = 0;
		}
		
		FOR(i,1,n+1) 
			for(int j = i; j <= n; j += i)
				ok[i] &= bad[j];
				
		vi ans;
		FOR(i,1,n+1) if (ok[i]) ans.pb(i);
		cout << ans.size() << "\n";
		for (int a: ans) cout << a << " ";
		cout << "\n";
	}
}