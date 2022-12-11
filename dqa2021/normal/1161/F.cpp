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
	x=flg?-x:x;
	assert(x!=-2);
//	return flg?-x:x;
	return x;
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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
#define F fflush(stdout)

int n,w[64][64];
int L[64],R[64];
vector<P> S[64];

void prepare(){
	rep(i,1,n){
		S[i].clear();
		L[i]=R[i]=0;
		rep(j,1,n) S[i].emplace_back(w[i][j],j);
		sort(all(S[i]),greater<P>());
	}
	static int stk[64],top;
	top=n; iota(stk+1,stk+n+1,1);
	while (top){
		const int u=stk[top--];
		assert(S[u].size());
		const int v=S[u].back().se; S[u].pop_back();
		if (!R[v]){
			L[u]=v,R[v]=u;
			continue;
		}
		if (w[R[v]][v]>w[u][v]) {++top; continue;}
		L[R[v]]=0,stk[++top]=R[v]; L[u]=v,R[v]=u;
	}
//	rep(i,1,n) debug("L %d = %d\n",i,L[i]);
//	rep(i,1,n) debug("R %d = %d\n",i,R[i]);
}

void print(int x,bool e){
	printf("%d\n",x+n*e); F;
}
void to_mat(int &x,bool &e){
	if (e) x=R[x],e=0;
	else x=L[x],e=1;
}

void solve(){
	n=read();
	rep(i,1,n) rep(j,1,n) w[i][j]=read();
	puts("B"); F;
	char s[2]; scanf("%s",s);
	if (s[0]=='D'){
		rep(i,1,n) rep(j,1,n) w[i][j]=n*n-w[i][j]+1;
	}
	bool e=0;
	int o=read();
	if (o>n){
		o-=n,e=1;
		rep(i,1,n) rep(j,i+1,n) swap(w[i][j],w[j][i]);
	}
	prepare();
	if (e){
		rep(i,1,n) swap(L[i],R[i]);
	}
	do{
		o=(o-1)%n+1;
		to_mat(o,e);
		print(o,e);
	}while (e^=1,~(o=read()));
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}