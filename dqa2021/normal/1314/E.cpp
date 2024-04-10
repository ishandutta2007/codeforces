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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,k;
int ans;

int c[128],top;

bool trans(int *d,int &m,bool g){
	int z=0;
	rep(i,1,m) z+=d[i];
	if (z>n) return 0;
	if (!g) return 1;
	static int e[1<<11],q,b; q=0,b=0;
	per(i,1,m){
		++b;
		while (d[i]--) e[++q]=b;
	}
	m=q;
	rep(i,1,q) d[i]=e[i];
	return 1;
}

bool check(){
	//return 1;
	//int z=0; rep(i,1,top) z+=c[i];
	//if (z^64) return 0;
	//static int cnt=0; ++cnt;
	//if (cnt%1000000==0,1) printf("check %d\n",cnt);
	
	/*int z=0;
	per(i,1,top){
		z+=c[i]*(top-i+1);
		if (z>n) return 0;
	}*/
	static int d[1<<11],m; m=top;
	rep(i,1,top) d[i]=c[top-i+1];
	rep(_,1,k){
		if (!trans(d,m,_<k)) return 0;
	}
	return 1;
}

void dfs(int x,int S){
	if (!x||S==64) return;
	//if (!x||S==64) return ans+=check(),void();
	//if (S+x>64) return;
	int T=S,cnt=0;
	dfs(x-1,S);
	while (T+x<=64&&top<n){
		++cnt; T+=x;
		c[++top]=x;
		if (!check()) break;
		else ++ans;
		dfs(x-1,T);
	}
	top-=cnt;
}

void solve(){
	n=read(),k=read();
	if (k==1){
		static int dp[1<<11];
		dp[0]=1;
		rep(i,1,n) rep(j,0,n-i) add(dp[i+j],dp[j]);
		int z=0;
		rep(i,1,n) add(z,dp[i]);
		printf("%d\n",z);
		return;
	}
	if (k==2){
		static int dp[1<<11][1<<11];
		dp[0][0]=1;
		per(t,1,n){
			rep(j,0,n)
				rep(i,0,j/t){
					if (i==n||j+(i+1)*t>n) break;
					add(dp[i+1][j+(i+1)*t],dp[i][j]);
				}
		}
		int z=0;
		rep(i,1,n) rep(j,1,n) add(z,dp[i][j]);
		printf("%d\n",z);
		return;
	}
	dfs(64,0);
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}