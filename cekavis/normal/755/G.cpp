#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int OUT_LEN = 1000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 1<<15, M = N<<1, P = 998244353;
int n, k, w[M], inv[M];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
inline void DFT(vector<int> &f, int n){
	static unsigned ll F[M];
	for(int i=0, j=0; i<n; ++i){
		F[i]=f[j];
		for(int k=n>>1; (j^=k)<k; k>>=1);
	}
	for(int i=1; i<n; i<<=1) for(int j=0; j<n; j+=i<<1){
		int *W=w+i;
		unsigned ll *F0=F+j, *F1=F+j+i;
		for(int k=j; k<j+i; ++k, ++W, ++F0, ++F1){
			int t=*F1**W%P;
			*F1=*F0+P-t, *F0+=t;
		}
	}
	for(int i=0; i<n; ++i) f[i]=F[i]%P;
}
inline void IDFT(vector<int> &f, int n){
	reverse(f.begin()+1, f.end()), DFT(f, n);
	for(int i=0, I=Pow(n); i<n; ++i) f[i]=(ll)f[i]*I%P;
}
inline int Calc(int x){ int ans=1; while(ans<=x) ans<<=1; return ans;}
inline vector<int> operator *(const vector<int> &x, const vector<int> &y){
	if(!x.size() || !y.size()) return {0};
	if((unsigned ll)x.size()*y.size()<=1<<8){
		vector<int> ans(x.size()+y.size()-1);
		for(unsigned i=0; i<x.size(); ++i) for(unsigned j=0; j<y.size(); ++j)
			ans[i+j]=(ans[i+j]+(ll)x[i]*y[j])%P;
		return ans;
	}
	vector<int> a=x, b=y;
	int n=Calc(x.size()+y.size()-2);
	a.resize(n), b.resize(n), DFT(a, n), DFT(b, n);
	for(int i=0; i<n; ++i) a[i]=(ll)a[i]*b[i]%P;
	IDFT(a, n);
	return a.resize(min((int)x.size()+(int)y.size()-1, k+1)), a;
}
inline void operator *=(vector<int> &x, const vector<int> &y){ x=x*y;}
inline vector<int> operator +(const vector<int> &x, const vector<int> &y){
	vector<int> ans=x;
	if(y.size()>x.size()) ans.resize(y.size());
	for(unsigned i=0; i<y.size(); ++i) (ans[i]+=y[i])%=P;
	return ans;
}
inline void operator +=(vector<int> &x, const vector<int> &y){ x=x+y;}
inline vector<int> operator -(const vector<int> &x, const vector<int> &y){
	vector<int> ans=x;
	if(y.size()>x.size()) ans.resize(y.size());
	for(unsigned i=0; i<y.size(); ++i) (ans[i]+=P-y[i])%=P;
	return ans;
}
inline vector<int> PolyDiv2(const vector<int> &x){
	vector<int> ans(x.size());
	for(unsigned i=0; i<x.size(); ++i) ans[i]=(x[i]&1?x[i]+P:x[i])>>1;
	return ans;
}
inline vector<int> Ext(const vector<int> &a, int n){
	if(n<=(int)a.size()) return vector<int>(a.begin(), a.begin()+n);
	vector<int> ans=a;
	return ans.resize(n), ans;
}
vector<int> PolyInv(const vector<int> &a, int n=-1){
	if(n==-1) n=a.size();
	if(n==1) return {Pow(a[0])};
	vector<int> ans=PolyInv(a, (n+1)/2), tmp=Ext(a, n);
	int m=Calc(n*2-1);
	ans.resize(m), tmp.resize(m), DFT(ans, m), DFT(tmp, m);
	for(int i=0; i<m; ++i) ans[i]=(2+(ll)(P-tmp[i])*ans[i])%P*ans[i]%P;
	IDFT(ans, m);
	return ans.resize(n), ans;
}
vector<int> PolySqrt(const vector<int> &a, int n=-1){
	if(n==-1) n=a.size();
	if(n==1) return {1};
	vector<int> ans=PolySqrt(a, (n+1)/2);
	return PolyDiv2(Ext(ans+Ext(a, n)*PolyInv(Ext(ans, n)), n));
}
inline vector<int> D(const vector<int> &a){
	vector<int> ans(a.size()-1);
	for(unsigned i=1; i<a.size(); ++i) ans[i-1]=(ll)a[i]*i%P;
	return ans;
}
inline vector<int> Int(const vector<int> &a){
	vector<int> ans(a.size()+1);
	for(unsigned i=0; i<a.size(); ++i) ans[i+1]=(ll)a[i]*inv[i+1]%P;
	return ans;
}
inline vector<int> PolyLn(const vector<int> &a){
	return Int(Ext(D(a)*PolyInv(a), a.size()-1));
}
vector<int> PolyExp(const vector<int> &a, int n=-1){
	if(n==-1) n=a.size();
	if(n==1) return {1};
	vector<int> ans=PolyExp(a, (n+1)/2);
	return Ext(ans*(Ext(a, n)-PolyLn(Ext(ans, n))+vector<int>{1}), n);
}
int main() {
	for(int i=1; i<M; i<<=1){
		w[i]=1, w[i+1]=Pow(3, (P-1)/i/2);
		for(int j=2; j<i; ++j) w[i+j]=(ll)w[i+j-1]*w[i+1]%P;
	}
	inv[1]=1;
	for(int i=2; i<M; ++i) inv[i]=(ll)(P-P/i)*inv[P%i]%P;
	scanf("%d%d", &n, &k);
	vector<int> s={1, 6, 1}, c;
	s.resize(k+1), s=PolySqrt(s);
	c=PolyLn(PolyDiv2(vector<int>{1, 1}+s));
	for(int &i:c) i=(ll)i*(n+1)%P;
	c=PolyExp(c)*PolyInv(s);
	for(int i=1; i<=k; ++i) (i>n?print('0'):print(c[i])), print(' ');
	return flush(), 0;
}