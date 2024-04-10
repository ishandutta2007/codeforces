#include<bits/stdc++.h>
#define pb push_back
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

int n;
int a[100010],b[100010];

vector<int> S;

void work(int x,int w){
	assert(x<n);
	if (w==1){
		if (a[x+1]==9) work(x+1,-1);
		++a[x],++a[x+1];
		S.pb(x);
	}
	else{
		if (a[x+1]==0) work(x+1,1);
		--a[x],--a[x+1];
		S.pb(-x);
	}
}

void solve(){
	n=read();
	static char str[100010];
	scanf("%s",str+1);
	rep(i,1,n) a[n-i+1]=str[i]-'0';
	scanf("%s",str+1);
	rep(i,1,n) b[n-i+1]=str[i]-'0';
	int t=b[1]-a[1]; ll s=abs(t);
	rep(i,2,n){
		t=b[i]-a[i]-t;
		s+=abs(t);
	}
	if (t) return puts("-1"),void();
	printf("%lld\n",s);
	int p=1;
	while (S.size()<int(1e5)){
		while (p<=n&&a[p]==b[p]) p++;
		if (p>n) break;
		int t=b[p]-a[p]<0?-1:1;
		work(p,t); //assert(a[n]);
	}
//	assert(S.size()==s);
	if (S.size()>1e5) S.resize(1e5);
	for (int x: S) printf("%d %d\n",n-abs(x),x<0?-1:1);
	
//	rep(i,1,n) printf("%d: a %d b %d\n",i,a[i],b[i]);
//	t=b[1]-a[1]; s-=abs(t);
//	rep(i,2,n){
//		t=b[i]-a[i]-t;
//		s-=abs(t);
//	}
//	if (s-S.size()) assert(0);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}