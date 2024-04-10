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
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,k,m;
int a[32];
bitset<2048> dp[1<<16];

vector<int> S[2048]; int q;

void solve(){
	n=read(),k=read();
	const int lim=(1<<n)-1;
	rep(i,1,n) a[i]=read(),m+=a[i];
	dp[0].set(0);
	//rep(i,1,n) dp[1<<i-1].set(a[i]);
	rep(msk,0,lim){
		auto &C=dp[msk];
		per(i,1,m) if (i%k==0&&C[i]) C.set(i/k);
		rep(i,1,n) if (msk>>i-1&1^1) dp[msk|1<<i-1]|=C<<a[i];
	}
	if (!dp[lim][1]) return puts("NO"),void();
	puts("YES");
	int msk=lim,w=1;
	while (msk){
		if (w*k<=m&&dp[msk][w*k]) w*=k,++q;
		else{
			rep(i,1,n) if (w>=a[i]&&msk>>i-1&1&&dp[msk^(1<<i-1)][w-a[i]])
				S[q].pb(a[i]),msk^=1<<i-1,w-=a[i];
		}
	}
	rep(_,1,n-1){
		int mx=-1;
		per(i,0,q) if (S[i].size()) {mx=i; break;}
		assert(~mx&&S[mx].size()>1);
		int u=S[mx].back(); S[mx].pop_back();
		int v=S[mx].back(); S[mx].pop_back();
		printf("%d %d\n",u,v);
		u+=v; while (u%k==0) u/=k,--mx;
		S[mx].pb(u);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}