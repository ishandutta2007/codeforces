#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;
#define ll long long
#define travel(i,x) for(int i=h[x];i;i=pre[i])

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig = false, c = read(); !isdigit(c); c = read()) {
		if (c == '-') iosig = true;
		if (c == -1) return;
	}
	for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
	if (iosig) x = -x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x == 0) print('0');
	else {
		if (x < 0) print('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

int n, m;
vector<int> a, c;
namespace Poly{
	const int P = 998244353;

	vector<int> Inv;
	vector<int> ans;// for Evaluate()
	vector<vector<int>> p;// for Evaluate() & Interpolate()

	// x^y
	inline int Pow(ll x, int y=P-2){
		int ans=1;
		for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
		return ans;
	}
	inline void Inv_Init(int x){
		x=max(x, 2);
		if(!Inv.size()) Inv.resize(2), Inv[1]=1;
		for(int i=Inv.size(); i<x; ++i) Inv.push_back((ll)(P-P/i)*Inv[P%i]%P);
	}
	inline int Ge(int x){ int n=1; while(n<=x) n<<=1; return n;}
	inline int Mod(int x){ return x<P?x:x-P;}
	// ...
	inline void NTT(vector<int> &f, int g, int n){
		f.resize(n);
		for(int i=0, j=0; i<n; ++i){
			if(i>j) swap(f[i], f[j]);
			for(int k=n>>1; (j^=k)<k; k>>=1);
		}
		vector<int> w(n>>1);
		for(int i=1; i<n; i<<=1){
			for(int j=w[0]=1, w0=(g==1?Pow(3, (P-1)/i/2):Pow(Pow(3, (P-1)/i/2))); j<i; ++j) w[j]=(ll)w[j-1]*w0%P;
			for(int j=0; j<n; j+=i<<1){
				for(int k=j; k<j+i; ++k){
					int t=(ll)f[k+i]*w[k-j]%P;
					f[k+i]=Mod(f[k]-t+P);
					f[k]=Mod(f[k]+t);
				}
			}
		}
		if(g==-1) for(int i=0, I=Pow(n); i<n; ++i) f[i]=(ll)f[i]*I%P;
	}
	// f+g
	inline vector<int> Add(const vector<int> &f, const vector<int> &g){
		vector<int> ans=f;
		for(unsigned i=0; i<f.size(); ++i) (ans[i]+=g[i])%=P;
		return ans;
	}
	// f*g
	inline vector<int> Mul(const vector<int> &f, const vector<int> &g){
		vector<int> F=f, G=g;
		int p=Ge(f.size()+g.size()-2);
		NTT(F, 1, p), NTT(G, 1, p);
		for(int i=0; i<p; ++i) F[i]=(ll)F[i]*G[i]%P;
		NTT(F, -1, p);
		return F.resize(f.size()+g.size()-1), F;
	}
	// 1/f
	inline vector<int> PolyInv(const vector<int> &f, int n=-1){
		if(n==-1) n=f.size();
		vector<int> ans;
		if(n==1) return ans.push_back(Pow(f[0])), ans;
		ans=PolyInv(f, (n+1)/2);
		vector<int> tmp(&f[0], &f[0]+n);
		int p=Ge(n*2-2);
		NTT(tmp, 1, p), NTT(ans, 1, p);
		for(int i=0; i<p; ++i) ans[i]=(2-(ll)ans[i]*tmp[i]%P+P)*ans[i]%P;
		NTT(ans, -1, p);
		return ans.resize(n), ans;
	}
	//a=d*b+r
	inline void PolyDiv(const vector<int> &a, const vector<int> &b, vector<int> &d, vector<int> &r){
		if(b.size()>a.size()) return r=a, d.clear();

		vector<int> A=a, B=b, iB;
		int n=a.size(), m=b.size();
		reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
		B.resize(n-m+1), iB=PolyInv(B, n-m+1);
		d=Mul(A, iB);
		d.resize(n-m+1), reverse(d.begin(), d.end());

		r=Mul(b, d);
		for(int i=0; i<m-1; ++i) r[i]=(P+a[i]-r[i])%P;
		r.resize(m-1);
	}
	// a'
	inline vector<int> Derivative(const vector<int> &a){
		vector<int> ans;
		ans.resize(a.size()-1);
		for(unsigned i=1; i<a.size(); ++i) ans[i-1]=(ll)a[i]*i%P;
		return ans;
	}
	// \int
	inline vector<int> Integral(const vector<int> &a){
		vector<int> ans;
		ans.resize(a.size()+1), Inv_Init(a.size()+1);
		for(unsigned i=0; i<a.size(); ++i) ans[i+1]=(ll)a[i]*Inv[i+1]%P;
		return ans;
	}
	void Evaluate_Interpolate_Init(int l, int r, int t, const vector<int> &a){
		if(l==r) return p[t].clear(), p[t].push_back(P-a[l]), p[t].push_back(1);
		int mid=(l+r)/2, k=t<<1;
		Evaluate_Interpolate_Init(l, mid, k, a), Evaluate_Interpolate_Init(mid+1, r, k|1, a);
		p[t]=Mul(p[k], p[k|1]);
	}
	inline void Evaluate(int l, int r, int t, const vector<int> &f, const vector<int> &a){
		if(r-l+1<=512){
			for(int i=l; i<=r; ++i){
				int x=0, j=f.size(), a1=a[i], a2=(ll)a[i]*a[i]%P, a3=(ll)a[i]*a2%P, a4=(ll)a[i]*a3%P, a5=(ll)a[i]*a4%P, a6=(ll)a[i]*a5%P, a7=(ll)a[i]*a6%P, a8=(ll)a[i]*a7%P;
				while(j>=8)
				x=((ll)x*a8+(ll)f[j-1]*a7+(ll)f[j-2]*a6+(ll)f[j-3]*a5+(ll)f[j-4]*a4+(ll)f[j-5]*a3+(ll)f[j-6]*a2+(ll)f[j-7]*a1+f[j-8])%P, j-=8;
				while(j--) x=((ll)x*a[i]+f[j])%P;
				ans.push_back(x);
			}
			return;
		}
		vector<int> tmp;
		PolyDiv(f, p[t], tmp, tmp);
		Evaluate(l, (l+r)/2, t<<1, tmp, a), Evaluate((l+r)/2+1, r, t<<1|1, tmp, a);
	}
	// f(a_i)
	inline vector<int> Evaluate(const vector<int> &f, const vector<int> &a){
		p.resize(a.size()<<2), Evaluate_Interpolate_Init(0, a.size()-1, 1, a);
		ans.clear(), Evaluate(0, a.size()-1, 1, f, a);
		return ans;
	}
	vector<int> Interpolate(int l, int r, int t, const vector<int> &x, const vector<int> &f){
		if(l==r){
			vector<int> ans;
			return ans.push_back(f[l]), ans;
		}
		int mid=(l+r)/2, k=t<<1;
		auto tmp=Add(Mul(Interpolate(l, mid, k, x, f), p[k|1]), Mul(Interpolate(mid+1, r, k|1, x, f), p[k]));
		return tmp;
	}
	// (x_i,y_i)
	inline vector<int> Interpolate(const vector<int> &x, const vector<int> &y){
		int n=x.size();
		p.resize(n<<2), Evaluate_Interpolate_Init(0, n-1, 1, x);
		vector<int> f=Derivative(p[1]);
		f=Evaluate(f, x);
		for(int i=0; i<n; ++i) f[i]=(ll)y[i]*Pow(f[i])%P;
		return Interpolate(0, n-1, 1, x, f);
	}
	// ln f
	inline vector<int> PolyLn(const vector<int> &f){
		vector<int> ans=Mul(Derivative(f), PolyInv(f));
		ans.resize(f.size()-1);
		return Integral(ans);
	}
	// e^f
	inline vector<int> PolyExp(const vector<int> &f, int n=-1){
		if(n==-1) n=f.size();
		vector<int> ans, tmp;
		if(n==1) return ans.push_back(1), ans;
		ans=PolyExp(f, (n+1)/2), ans.resize(n), tmp=PolyLn(ans);
		for(int &i:tmp) i=P-i;
		++tmp[0];
		ans=Mul(ans, Add(tmp, f));
		return ans.resize(n), ans;
	}
	// sqrt f
	inline vector<int> PolySqrt(const vector<int> &f, int n=-1){
		if(n==-1) n=f.size();
		vector<int> ans, tmp(&f[0], &f[0]+n);
		if(n==1) return ans.push_back(1), ans;// !
		ans=PolySqrt(f, (n+1)/2), ans.resize(n);
		ans=Add(ans, Mul(tmp, PolyInv(ans)));
		for(int &i:ans) i=(i&1?(i+P)/2:i/2);
		return ans;
	}
}

int main() {
	read(n), read(m), c.resize(m+1);
	for(int i=1; i<=n; ++i){
		static int x;
		read(x);
		if(x<=m) c[x]=-4;
	}
	c[0]=1;
	a=Poly::PolySqrt(c);
	++a[0];
	a=Poly::PolyInv(a);
	for(int i=1; i<=m; ++i) print(a[i]*2%Poly::P), print('\n');
	return flush(), 0;
}