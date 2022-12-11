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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
const int S=316,N=1e5;

int n,m;
int a[100010];
int dp[100010];
int p[100010];

struct B{
	int sum[S+10],tag;
	void settag(int w){
		tag+=w;
	}
	void settag(int l,int r,int w,int L,int R){
		int b=S+5; rep(i,l,r) p[i]+=w;
		rep(i,L,R) b=min(b,p[i]);
		tag+=b; rep(i,L,R) p[i]-=b;
		memset(sum,0,sizeof sum);
		rep(i,L,R) add(sum[p[i]],dp[i]);
		rep(i,1,S+5) add(sum[i],sum[i-1]);
	}
	void modify(int x){
//		iadd(sum[p[x]],dp[x]);
		add(sum[p[x]],dp[x]);
	}
	int query(int x){
		if (x-tag<0) return 0;
		x=min(x-tag,S+5);
		return sum[x];
	}
	int query(int x,int l,int r){
		int z=0;
		rep(i,l,r) if (p[i]+tag<=x)
			add(z,dp[i]);
		return z;
	}
}b[N/S+10];

int lst[100010],_lst[100010];

void settag(int x,int w){
	int X=(x-1)/S;
	b[X].settag(X*S+1,x,w,X*S+1,min(n+1,(X+1)*S));
	rep(i,0,X-1) b[i].settag(w);
}

int query(int x){
	int X=(x-1)/S;
	int z=b[X].query(m,X*S+1,x);
	rep(i,0,X-1) add(z,b[i].query(m));
	return z;
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) a[i]=read();
	dp[1]=1; b[0].modify(1);
	rep(i,1,n){
		int w=a[i];
		if (!lst[w]){
			settag(i,1);
		}
		else{
			if (!_lst[w]){
				settag(i,1);
				settag(lst[w],-2);
			}
			else{
				settag(i,1);
				settag(lst[w],-2);
				settag(_lst[w],1);
			}
		}
		_lst[w]=lst[w]; lst[w]=i;
		dp[i+1]=query(i);
		b[(i)/S].modify(i+1);
//		printf("dp %d = %d\n",i+1,dp[i+1]);
//		rep(j,1,i) printf("test p %d = %d + %d\n",j,b[(j-1)/S].tag,p[j]);
	}
	printf("%d\n",dp[n+1]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}