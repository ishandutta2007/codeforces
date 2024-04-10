#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
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
const int N = 100005, P = 998244353;
int n, k, num, p, down[N], up[N], h[N], fa[N], siz[N], fac[N], ifac[N], A[1<<17], B[1<<17], e[N<<1], pre[N<<1];
pair<int,int> S[N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void init(int u){
	siz[u]=1;
	travel(i, u) if(e[i]!=fa[u]) fa[e[i]]=u, init(e[i]), siz[u]+=siz[e[i]];
}
int dfs(int u, int s=0){
	int now=0, ass=(ll)((s+=up[u])%=P)*down[u]%P;
	travel(i, u) if(e[i]!=fa[u]) ass=(ass+dfs(e[i], s)+(ll)now*down[e[i]])%P, now=(now+down[e[i]])%P;
	down[u]=(down[u]+now)%P;
	return ass;
}
inline int Pow(ll x, int y=P-2){
	ll ass=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ass=ass*x%P;
	return ass;
}
inline void NTT(int *f, int g){
	for(int i=0, j=0; i<p; ++i){
		if(i>j) swap(f[i], f[j]);
		for(int k=p>>1; (j^=k)<k; k>>=1);
	}
	for(int i=1; i<p; i<<=1){
		int w0=(g==1?Pow(3, (P-1)/i>>1):Pow(Pow(3, (P-1)/i>>1)));
		for(int j=0; j<p; j+=i<<1){
			int w=1;
			for(int k=j; k<j+i; ++k){
				int t=(ll)w*f[k+i]%P;
				f[k+i]=(f[k]-t+P)%P;
				f[k]=(f[k]+t)%P;
				w=(ll)w*w0%P;
			}
		}
	}
	if(g==-1){
		ll I=Pow(p);
		for(int i=0; i<p; ++i) f[i]=f[i]*I%P;
	}
}
vector<int> mul(int l, int r){
	if(r-l<2){
		vector<int> f;
		f.push_back(1);
		if(l<r) f.push_back(S[l].first);
		return f;
	}
	vector<int> a=mul(l, l+r>>1), b=mul(l+r>>1, r);
	for(p=1; p<=r-l; p<<=1);
	for(int i=0; i<p; ++i) A[i]=(i<a.size()?a[i]:0), B[i]=(i<b.size()?b[i]:0);
	NTT(A, 1), NTT(B, 1);
	for(int i=0; i<p; ++i) A[i]=(ll)A[i]*B[i]%P;
	NTT(A, -1);
	vector<int> f;
	f.resize(r-l+1);
	rep(i, 0, r-l) f[i]=A[i];
	return f;
}
int main() {
	read(n), read(k);
	if(k==1) return printf("%lld", (ll)n*(n-1)/2%P), 0;
	rep(i, 2, n){
		static int x, y;
		read(x), read(y);
		add(x, y), add(y, x);
	}
	init(1);
	fac[0]=1;
	rep(i, 1, k) fac[i]=(ll)fac[i-1]*i%P;
	ifac[k]=Pow(fac[k]);
	for(int i=k; i; --i) ifac[i-1]=(ll)ifac[i]*i%P;
	rep(i, 1, n){
		int cnt=0;
		travel(j, i) S[cnt++]=make_pair(e[j]==fa[i]?n-siz[i]:siz[e[j]], e[j]);
		sort(S, S+cnt);
		vector<int> f=mul(0, cnt);
		// for(int i:f) printf("%d ", i); puts("");
		for(int l=0, r=0; l<cnt; l=r){
			int I=Pow(S[l].first), ass=0;
			for(int j=f.size(); j--;) A[j]=f[j];
			for(int j=f.size(); --j;){
				int tmp=(ll)A[j]*I%P;
				A[j-1]=(A[j-1]-tmp+P)%P;
				if(j-1<=k) ass=(ass+(ll)ifac[k-j+1]*tmp)%P;
			}
			ass=(ll)ass*fac[k]%P;
			// printf(">>>%d %d\n", i, ass);
			while(r<cnt && S[r].first==S[l].first) (S[r].second==fa[i]?down[i]:up[S[r].second])=ass, ++r;
		}
	}
	// rep(i, 1, n) printf("%d ", down[i]); puts("");
	return printf("%d", dfs(1)), 0;
}