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

int n; char s[150010];
int dp[150010][25];
int pre[150010][25];

int getid(char x){
	if (x=='t') return 0;
	if (x=='w') return 1;
	if (x=='o') return 2;
	if (x=='n') return 3;
	if (x=='e') return 4;
	return 5;
}

void chk(int *F,int *pre,int x,const int *G,int y,int w){
	if (F[x]>G[y]+w) F[x]=G[y]+w,pre[x]=y;
}

//int getnext(int S,int c){
//	if (c==2) S|=1;
//	if (S&1&&c==3) S|=2;
//	if (c==0) S|=4;
//	if (S&4&&c==1) S|=8;
//	return S;
//}

void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	rep(i,0,n) rep(j,0,24) dp[i][j]=1e9;
	dp[0][24]=0;
	rep(i,1,n){
		const auto G=dp[i-1];
		auto F=dp[i]; int c=getid(s[i]);
		rep(u,0,4) rep(v,0,4){
			if (G[u*5+v]==1e9) continue;
			if (!(c!=5&&c!=3&&u+1==v&&v+1==c)) chk(F,pre[i],v*5+min(c,4),G,u*5+v,0);
			chk(F,pre[i],u*5+v,G,u*5+v,1);
		}
	}
	int p=0;
	rep(j,0,24) if (dp[n][j]<dp[n][p]) p=j;
	printf("%d\n",dp[n][p]);
	vector<int> S;
	per(i,1,n){
		int q=pre[i][p];
		if (dp[i-1][q]+1==dp[i][p]) S.pb(i);
		p=q;
	}
	reverse(all(S));
	for (int x: S) printf("%d ",x);
	puts("");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}