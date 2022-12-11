#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
int fac[64],ifac[64];
void init(int x){
	fac[0]=1; rep(i,1,x) fac[i]=1LL*fac[i-1]*i%mod;
	ifac[x]=qpow(fac[x],mod-2); per(i,1,x) ifac[i-1]=1LL*ifac[i]*i%mod;
}


int n; const int m=60;
bool exst[64],vis[64];

void dfs(int x,vector<int> &S){
	vis[x]=1; S.pb(x);
	for (int i=x+x;i<=m;i+=x)
		if (exst[i]&&!vis[i]) dfs(i,S);
	rep(i,1,x-1) if (exst[i]&&x%i==0&&!vis[i]) dfs(i,S);
}


int work(const vector<int> &S){
	//if (S.size()==1) return 1;
	static int id[64]; int q=0;
	static int msk[64];
	static int fwt[1<<15];
	memset(id,-1,sizeof id);
	for (int x: S){
		bool g=0;
		for (int y: S)
			if (y<x&&x%y==0){g=1; break;}
		if (!g) id[x]=q++;
	}
	assert(q<=15);
	const int lim=(1<<q)-1;
	--q;
	rep(i,0,lim) fwt[i]=0;
	for (int x: S) if (!~id[x]){
		for (int y: S) if (x%y==0&&~id[y]) msk[x]|=1<<id[y];
		++fwt[msk[x]];
	}
	rep(j,0,q) rep(i,0,lim) if (i>>j&1) fwt[i]+=fwt[i^(1<<j)];
	static int dp[64][1<<15];
	rep(i,0,n) memset(dp[i],0,lim+1<<2);
	for (int x: S) if (!~id[x]) dp[1][msk[x]]++;
	rep(T,1,lim) rep(t,1,n) if (dp[t][T]){
		const int &V=dp[t][T];
		//printf("dp %d %d = %d\n",t,T,dp[t][T]);
		if (fwt[T]-t>0) add(dp[t+1][T],1LL*V*(fwt[T]-t)%mod);
		for (int x: S) if (!~id[x]&&(msk[x]|T)!=T&&(msk[x]&T)) add(dp[t+1][msk[x]|T],V);
	}
	//int z=ifac[S.size()-q-1];
	int mx=S.size()-q-2;
	int z=1LL*dp[mx+1][lim]*ifac[mx]%mod;
	//printf("solve:"); for (int x: S) printf(" %d",x);
	//printf("\n  mx %d dp %d\n",mx,dp[mx+1][lim]);
	return z;
}

void solve(){
	n=read(); init(m+2);
	rep(i,1,n) exst[read()]=1;
	int z=n,ans=1;
	rep(i,1,m) if (exst[i]&&!vis[i]){
		vector<int> S;
		dfs(i,S); sort(all(S));
		if (S.size()==1) continue;
		z--; ans=1LL*ans*work(S)%mod;
	}
	rep(i,1,m) if (exst[i]){
		bool g=1;
		rep(j,1,i-1) if (exst[j]&&i%j==0){g=0; break;}
		z-=g;
	}
	ans=1LL*ans*fac[z]%mod;
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}