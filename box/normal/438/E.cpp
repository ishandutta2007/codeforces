// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 998244353;

namespace poly {
	const int MOD = 998244353;
	const int IMAG = 86583718;
	const int NTTG = 3;
	
	int rev[262160];
	int minv[262160];
	int w[20][2][262160];
	
	int qpow(int b, int e) {
		int re=1;
		while(e){
			if(e&1)re=1ll*re*b%MOD;
			b=1ll*b*b%MOD;e>>=1;
		}
		return re;
	}
	
	void constructrev(int n) {
		for(int i=1, j=0; i < n; i++) {
			int bit=n>>1;
			for(;j&bit;bit>>=1)j^=bit;
			j^=bit; rev[i] = j;
		}
	}

	void constructroot(int n) {
		minv[1] = 1;
		iter(i, 2, n+1)
			minv[i]=1ll*(MOD-MOD/i)*minv[MOD%i]%MOD;
		for(int l=1; (1<<l)<=n; l++)
			rep(inv, 2) {
				int re = inv?qpow(minv[NTTG],(MOD-1)>>l):qpow(NTTG,(MOD-1)>>l);
				w[l][inv][0] = 1;
				rep1(i,(1<<(l-1))-1) w[l][inv][i] = 1ll*w[l][inv][i-1]*re%MOD;
			}
	}
	
	void ntt(int *v, int n, bool inv) {
		rep(i, n) if(i < rev[i]) swap(v[i], v[rev[i]]);
		for(int l=1;(1<<l)<=n;l++)
			for(int i=0;i<n;i+=(1<<l)) {
				int p=i+(1<<(l-1));
				iter(j, i, p) {
					int a=v[j],b=1ll*v[j+(1<<(l-1))]*w[l][inv][j-i]%MOD;
					v[j]=(a+b>=MOD?a+b-MOD:a+b);
					v[j+(1<<(l-1))]=(a<b?a+MOD-b:a-b);
				}
			}
		if(inv) rep(i, n) v[i] = 1ll*v[i]*minv[n]%MOD;
	}
	
	void mult(int *a, int as, int *b, int bs, int *o, bool construct, bool clean = 0, int th = 100000000) {
		int n = as+bs-1;
		while(n - (n & (-n))) n += (n & (-n));
		if(construct) constructroot(n);
		constructrev(n);
		ntt(a, n, 0); ntt(b, n, 0);
		rep(i, n) o[i] = 1ll*a[i]*b[i]%MOD;
		ntt(o, n, 1);
		iter(i, th, n) o[i] = 0;
		if(clean) rep(i, n) a[i] = b[i] = 0;
	}

	void cfn(int* a, int as, int *o) {
		static int tmp[262160];
		if(as == 1) { tmp[0] = a[0]; o[0] = qpow(a[0], MOD - 2); return; }
		cfn(a, (as+1)/2, o); int le = 0;
		while((1 << le) < (as << 1)) le++;
		constructrev(1 << le);
		rep(i, as) tmp[i] = a[i];
		iter(i, as, 1<<le) tmp[i] = o[i] = 0;
		ntt(tmp, 1<<le, 0); ntt(o, 1<<le, 0);
		rep(i, 1<<le) o[i] = 1ll * (MOD + (2 - 1ll * tmp[i] * o[i]) % MOD) * o[i] % MOD;
		ntt(o, 1<<le, 1);
		iter(i, as, 1<<le) o[i] = 0;
	}

	void deriv(int *a, int as, int *o) { rep1(i, as-1) { o[i-1] = 1ll * i * a[i] % MOD; } o[as-1] = 0; }
	void integ(int *a, int as, int *o) { for(int i=as-2; i>=0; i--) { o[i+1] = 1ll * minv[i+1] * a[i] % MOD; } o[0] = 0; }

	void ln(int *a, int as, int *o) {
		static int iv[262160]; 
		cfn(a, as, iv); 
		deriv(a, as, a);
		mult(iv, as, a, as, o, 0, 1, as);
		integ(o, as, o);
	}
	
	void exp(int *a, int as, int *o) {
		static int tmp[262160], tmp2[262160], tmp3[262160];
		if(as == 1) { o[0] = 1; return; }
		exp(a, (as+1)/2, o);
		rep(i, as) tmp[i] = o[i], tmp3[i] = 0; 
		ln(tmp, as, tmp3);
		rep(i, as) tmp3[i] = (MOD + a[i] - tmp3[i] + (i == 0)) % MOD, tmp2[i] = o[i];
		mult(tmp2, as, tmp3, as, o, 0, 1);
	}
	
	void sqrt(int *a, int as, int *o) {
		static int tmp[262160];
		ln(a, as, tmp);
		rep(i, as) tmp[i] = 1ll * minv[2] * tmp[i] % MOD;
		exp(tmp, as, o);
		iter(i, as, 2*as) o[i] = 0;
	}

	void init(int n) { constructroot(n); }
}

int p[262160];
int fourp[262160];
int oneminusfourp[262160];
int twotimessquarerootofoneminusfourp[262160];
int fourpminustwotimessquarerootofoneminusfourpminustwo[262160];
int inverseoffourpminustwotimessquarerootofoneminusfourpminustwo[262160];
int result[262160];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    oneminusfourp[0] = 1;
    rep(i, n) {
        int k; cin >> k;
        p[k]++;
        fourp[k] += 4;
        oneminusfourp[k] = (oneminusfourp[k] + MOD - 4) % MOD;
    }
    m++;
    int k = 1; while(k < (m << 1)) k <<= 1;
    poly::init(k);
    poly::sqrt(oneminusfourp, m, twotimessquarerootofoneminusfourp);
    rep(i, m) twotimessquarerootofoneminusfourp[i] = twotimessquarerootofoneminusfourp[i]*2%MOD;
    rep(i, m) fourpminustwotimessquarerootofoneminusfourpminustwo[i] = (fourp[i] + MOD - twotimessquarerootofoneminusfourp[i]) % MOD;
    fourpminustwotimessquarerootofoneminusfourpminustwo[0] = (MOD + fourpminustwotimessquarerootofoneminusfourpminustwo[0] - 2) % MOD;
    poly::cfn(fourpminustwotimessquarerootofoneminusfourpminustwo, m, inverseoffourpminustwotimessquarerootofoneminusfourpminustwo);
    poly::mult(fourp, m, inverseoffourpminustwotimessquarerootofoneminusfourpminustwo, m, result, 0);
    rep1(i, m-1) cout << (MOD - result[i]) % MOD << endl;
}