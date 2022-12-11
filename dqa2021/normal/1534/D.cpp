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
vector<int> S[2010];

vector<int> ask(int x){
	printf("? %d\n",x); fflush(stdout);
	vector<int> T={0};
	rep(i,1,n) T.pb(read());
	return T;
}

void solve(){
	n=read();
	S[1]=ask(1);
	static int tot[2];
	rep(i,1,n) ++tot[S[1][i]&1];
	int e=tot[0]<=tot[1]?0:1;
	rep(i,2,n) if (S[1][i]%2==e) S[i]=ask(i);
	puts("!");
	rep(i,1,n) if (S[1][i]%2==e){
		rep(j,1,n) if (S[i][j]==1) printf("%d %d\n",i,j);
	}
	fflush(stdout);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}