#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,p[250010],g[250010];

int find(int *a,int A,int *b,int B){
	int mxr=b[B];
	int l=1,r=A+1;
	while (l<r){
		int mid=(l+r)>>1;
		if (a[mid]<mxr) r=mid;
		else l=mid+1;
	}
	return l>A?-1:a[l];
}
void solve(){
	n=read();
	rep(i,1,n) p[i]=read();
	if (n==1) return puts("0"),void();
	static int a[250010],b[250010]; int A=0,B=0;
	a[A]=b[B]=n+1; a[++A]=b[++B]=n;
	per(i,1,n-1){
		while (A&&p[i]<p[a[A]]) --A;
		while (B&&p[i]>p[b[B]]) --B;
		int w=max(find(a,A,b,B),find(b,B,a,A));
		g[i]=w;
		a[++A]=i,b[++B]=i;
	}
	//rep(i,1,n-1) printf("g %d = %d\n",i,g[i]);
	int z=0;
	for (int t=1;t^n;t=g[t],++z);
	printf("%d\n",z);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}