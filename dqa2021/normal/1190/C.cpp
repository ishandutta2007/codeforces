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

int n,k;
char s[100010]; int w[100010];
int pre[100010][2],suf[100010][2],f[2],g[2];
int solve(){
	scanf("%d%d%s",&n,&k,s+1);
	rep(i,1,n) w[i]=s[i]-'0';
	rep(i,1,n){
		memcpy(pre[i],pre[i-1],8);
		pre[i][w[i]]=i;
	}
	suf[n+1][0]=suf[n+1][1]=n+1;
	per(i,1,n){
		memcpy(suf[i],suf[i+1],8);
		suf[i][w[i]]=i;
	}
	per(i,1,n) f[w[i]]=i;
	g[0]=g[1]=n+1;
	rep(i,1,n) g[w[i]]=i;
	bool h=0;
	rep(i,1,n-k+1){
		int l=i,r=i+k-1;
		int *p=pre[l-1],*q=suf[r+1];
		if (!p[0]&&q[0]==n+1) return 1;
		if (!p[1]&&q[1]==n+1) return 1;
		if ((!p[0]&&g[0]-q[0]+1<=k||q[0]==n+1&&p[0]-f[0]+1<=k)&&(!p[1]&&g[1]-q[1]+1<=k||q[1]==n+1&&p[1]-f[1]+1<=k));
		else h=1;
	}
	return h?0:-1;
}

int main()
{
	for (int T=1;T--;){
		int t=solve();
		if (t>0) puts("tokitsukaze");
		else if (t<0) puts("quailty");
		else puts("once again");
	}
	return 0;
}