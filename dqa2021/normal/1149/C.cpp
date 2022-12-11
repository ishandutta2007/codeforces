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
const int INF=1e8;

int n; char s[200010]; int q;

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct C{
	int w,s;
	int la,ra;
	int lb,rb;
	int lc,rc;
}c[1<<19];

C operator+(const C &x,const C &y){
	C z;
	z.w=max(max(x.w,y.w),max(x.ra+y.lb+x.s,x.rb+y.la-x.s));
	z.s=x.s+y.s;
	z.la=max(x.la,max(y.la-x.s,x.lc+x.s+y.lb));
	z.ra=max(y.ra-x.s,max(x.ra,y.rc-2*x.s+x.rb));
	z.lb=max(x.lb,x.s+y.lb);
	z.rb=max(y.rb+x.s,x.rb);
	z.lc=max(x.lc,y.lc-2*x.s);
	z.rc=max(y.rc-2*x.s,x.rc);
	return z;
}

void build(int x,int l,int r){
	if (l==r){
		if (s[l]=='('){
			c[x]=(C){0,1,-1,-1,1,1,-2,-2};
		}
		else{
			c[x]=(C){0,-1,-INF,-INF,-INF,-INF,2,2};
		}
		//printf("  c %d  %d %d: %d %d  %d %d  %d %d  %d %d\n",x,l,r,c[x].w,c[x].s,c[x].la,c[x].ra,c[x].lb,c[x].rb,c[x].lc,c[x].rc);
		return;
	}
	build(ls,l,mid); build(rs,mid+1,r);
	c[x]=c[ls]+c[rs];
	//printf("  c %d  %d %d: %d %d  %d %d  %d %d  %d %d\n",x,l,r,c[x].w,c[x].s,c[x].la,c[x].ra,c[x].lb,c[x].rb,c[x].lc,c[x].rc);
}

void modify(int x,int l,int r,int p){
	if (l==r){
		if (s[l]=='('){
			c[x]=(C){0,1,-1,-1,1,1,-2,-2};
		}
		else{
			c[x]=(C){0,-1,-INF,-INF,-INF,-INF,2,2};
		}
		return;
	}
	if (p<=mid) modify(ls,l,mid,p);
	else modify(rs,mid+1,r,p);
	c[x]=c[ls]+c[rs];
}

void solve(){
	n=read(),q=read(); scanf("%s",s+2); s[1]='(',s[n<<1]=')';
	build(1,1,n<<1);
	//printf("test %s",s+1);
	printf("%d\n",c[1].w);
	while (q--){
		int x=read()+1,y=read()+1;
		
		//printf("test %s",s+1);
		
		swap(s[x],s[y]);
		modify(1,1,n<<1,x);
		modify(1,1,n<<1,y);
		printf("%d\n",c[1].w);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}