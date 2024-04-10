#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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

const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n;
vector<int> e[310];

int f[310][310],g[310][310],S;
int s[310];

inline void merge(int *f,int *g,int *s,int *t,int &n,int m){
	static int a[310],b[310];
	rep(i,0,n+m) a[i]=b[i]=0;
	rep(i,0,n) rep(j,0,m){
		add(a[min(i,j+1)],1LL*f[i]*s[j]%mod);
		add(i+j+1<=S?a[i]:b[j+1],1LL*f[i]*t[j]%mod);
		add(i+j+1<=S?a[j+1]:b[i],1LL*g[i]*s[j]%mod);
		add(b[max(i,j+1)],1LL*g[i]*t[j]%mod);
	}
	n+=m;
	rep(i,0,n) f[i]=a[i],g[i]=b[i];
}

void dfs(int x,int fa){
	s[x]=1;
	f[x][0]=1,f[x][1]=0;
	g[x][0]=1,g[x][1]=0;
	for (int y: e[x]) if (y^fa){
		dfs(y,x);
		merge(f[x],g[x],f[y],g[y],s[x],s[y]);
	}
}

int work(int x){
	S=x;
	dfs(1,0);
	int z=0;
	rep(i,0,S) add(z,f[1][i]);
//	printf("work %d = %d\n",x,z);
//	z=1LL*z*qpow(2,mod-1-n)%mod;
	return z;
}

void solve(){
	n=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	int ans=1LL*n*qpow(2,n)%mod;
	rep(i,1,n) iadd(ans,work(i));
//	add(ans,n>>1);
	iadd(ans,1);
	ans=1LL*ans*qpow(2,mod-1-n)%mod;
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}