#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll a[200005],b[200005],t[200005];
typedef complex<double> base;
void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(int i=0; i<n/2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	/* In NTT, let prr = primitive root. Then,
	int ang = ipow(prr, (MOD - 1) / n);
	if(inv) ang = ipow(ang, MOD - 2);
	for(int i=0; i<n/2; i++){
		roots[i] = (i ? (1ll * roots[i-1] * ang % MOD) : 1);
	}
	XOR Convolution : set roots[*] = 1.
	OR Convolution : set roots[*] = 1, and do following:
    if (!inv) {
        a[j + k] = u + v;
        a[j + k + i/2] = u;
    } else {
        a[j + k] = v;
        a[j + k + i/2] = u - v;
    }
	*/
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n; // skip for OR convolution.
}
 
vector<ll> multiply(vector<ll> &v, vector<ll> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}
vector<ll> multiply(vector<ll> &v, vector<ll> &w, ll MOD){
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	vector<base> v1(n), v2(n), r1(n), r2(n);
	for(int i=0; i<v.size(); i++){
		v1[i] = base(v[i] >> 15, v[i] & 32767);
	}
	for(int i=0; i<w.size(); i++){
		v2[i] = base(w[i] >> 15, w[i] & 32767);
	}
	fft(v1, 0);
	fft(v2, 0);
	for(int i=0; i<n; i++){
		int j = (i ? (n - i) : i);
		base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
		base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
		base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
		base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
		r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
		r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
	}
	fft(r1, 1);
	fft(r2, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++){
		ll av = (ll)round(r1[i].real());
		ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
		ll cv = (ll)round(r2[i].imag());
		av %= MOD, bv %= MOD, cv %= MOD;
		ret[i] = (av << 30) + (bv << 15) + cv;
		ret[i] %= MOD;
		ret[i] += MOD;
		ret[i] %= MOD;
	}
	return ret;
}
Vll go(int S,int E){
	if(S==E){
		Vll res={1};
		res.pb(b[S]);
		return res;
	}
	Vll L=go(S,S+E>>1), R=go((S+E>>1)+1,E);
	return multiply(L,R,MOD);
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)scanf("%lld",a+i);
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int o,q,x,y,z;
		scanf("%d%d%d%d",&o,&q,&x,&y);
		if(o==1){
			fup(i,1,n,1)t[i]=a[i];
			t[x]=y;
		}else{
			scanf("%d",&z);
			fup(i,1,n,1)t[i]=a[i];
			fup(i,x,y,1)t[i]+=z;
		}
		fup(i,1,n,1){
			b[i]=(q-t[i])%MOD;
			if(b[i]<0)b[i]+=MOD;
		}
		Vll v=go(1,n);
		printf("%lld\n",v[k]);
	}
}