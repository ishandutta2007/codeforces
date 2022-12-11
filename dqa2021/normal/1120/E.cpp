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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
const int B=5002,C=1e4;

int a;
bool vis[1010][10010];
P pre[1010][10010];
int tr[1010][10010];
P que[10000010]; int hd,tl;

void ins(int x,int y,int X,int Y,int o){
	y+=B; if (y<0||y>C) return;
	if (vis[x][y]) return;
	vis[x][y]=1; pre[x][y]={X,Y};
	tr[x][y]=o;
	que[++tl]={x,y};
}

void report(int x,int y){
	vector<int> S;
	while (~x){
//		printf("test %d %d\n",x,y);
		y+=B;
		int X,Y; tie(X,Y)=pre[x][y];
		S.pb(tr[x][y]);
		x=X,y=Y;
	}
	reverse(all(S));
	while (S.back()==0) S.pop_back();
	reverse(all(S));
	for (int x: S) printf("%d",x);
	puts("");
}

void solve(){
	a=read();
	rep(i,1,9) ins(a*i/10,i-a*i%10*a,-1,-1,i);
	while (hd<tl){
		int x,y; tie(x,y)=que[++hd]; y-=B;
//		printf("test %d %d\n",x,y);
		if (!x&&!y) report(x,y),exit(0);
		rep(e,0,9){
			ins((x+a*e)/10,y+e-(x+a*e)%10*a,x,y,e);
		}
	}
	puts("-1");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}