#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll

using namespace std;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<(int)(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<endl;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

const int N=300010;
int n,k,cnt[N],b[5],fac[N],inf[N];
vi pol[N];
vi res[5];

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

void ntt(vi& a, vi& rt, vi& rev, int n) {
	for (int i=0;i<n;++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) for (int j=0;j<k;++j) {
				int z = rt[j + k] * 1ll * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
				ai += (ai + z >= mod ? z - mod : z);
	}
}

vi conv(const vi& a, const vi& b) {
	if (a.empty() || b.empty())
		return {};
	int s = a.size()+b.size()-1, B = 32 - __builtin_clz(s), n = 1 << B;
	if (min(a.size(),b.size())<=8)
	{
		vl ans(s);
		for (int i=0;i<a.size();++i) for (int j=0;j<b.size();++j) ans[i+j]+=a[i]*1ll*b[j];
		vi u;
		for (auto a: ans) u.pb(a%MOD);
		return u;
	}
	vi L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);
	for (int i=0;i<n;++i) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
	int curL = mod / 2, inv = pot(n, mod - 2);
	for (int k = 2; k < n; k *= 2) {
		int z[] = {1, pot(root, curL /= 2)};
		for (int i=k;i<2*k;++i) rt[i] = rt[i / 2] * 1ll * z[i & 1] % mod;
	}
	ntt(L, rt, rev, n); ntt(R, rt, rev, n);
	for (int i=0;i<n;++i) out[-i & (n-1)] = L[i] * 1ll * R[i] % mod * inv % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}

typedef complex<double> C;
typedef vector<double> vd;
#define sz(a) (int)(a).size()
#define rep(i,a,b) for (int i=(a);i<(b);++i)
const long double pi=asinl(1)*2;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, pi / k); // M_PI, lower-case L
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

const int M=998244353;

vi convMod(const vi &a, const vi &b) {
	if (a.empty() || b.empty()) return {};
	vi res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i,0,n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i,0,sz(res)) {
		ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
		ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}

int ch(int a,int b)
{
	if (b>a) return 0;
	return mult(fac[a],mult(inf[b],inf[a-b]));
}

vi ge(int l,int r)
{
	int cnt1=0,cnt2=0;
	for (int i=l;i<r;++i)
	{
		if (cnt[i]==1) ++cnt1;
		if (cnt[i]>=2) ++cnt2;
	}
	cnt2*=2;
	vi a,b;
	for (int i=0;i<=cnt1;++i) a.pb(mult(pot(2,i),ch(cnt1,i)));
	for (int i=0;i<=cnt2;++i) b.pb(ch(cnt2,i));
	//cout<<cnt1<<' '<<cnt2<<en;
	//prVec(a);
	//prVec(b);
	return convMod(a,b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	M998();
	cin>>n>>k;
	fac[0]=1;
	for (int i=1;i<N;++i) fac[i]=mult(fac[i-1],i);
	inf[N-1]=divide(1,fac[N-1]);
	for (int i=N-2;i>=0;--i) inf[i]=mult(inf[i+1],i+1);
	for (int i=0;i<n;++i)
	{
		int a;
		cin>>a;
		++cnt[a];
	}
	for (int i=0;i<N;++i)
	{
		if (cnt[i]>=2) pol[i]={1,2,1};
		else if (cnt[i]==1) pol[i]={1,2};
		else pol[i]={1};
	}
	for (int i=0;i<k;++i)
	{
		cin>>b[i];
		res[i]=ge(0,b[i]);
		//prVec(res[i]);
	}
	int q;
	cin>>q;
	while (q--)
	{
		int a;
		cin>>a;
		a/=2;
		--a;
		int r=0;
		for (int i=0;i<k;++i) if (a>=b[i] && a-b[i]<res[i].size()) r=add(r,res[i][a-b[i]]);
		cout<<r<<en;
	}
}