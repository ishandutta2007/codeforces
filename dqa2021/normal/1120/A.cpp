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

int m,k,n,s;
int a[500010];
int lim[500010];

int c[500010]; int E;
void ins(int x,int w){
	E-=c[x]<lim[x];
	c[x]+=w;
	E+=c[x]<lim[x];
}

void solve(){
	m=read(),k=read(),n=read(),s=read();
	int D=m-k*n;
	rep(i,1,m) a[i]=read();
	rep(i,1,s) lim[read()]++;
	rep(i,1,5e5) E+=lim[i]>0;
	int j=0;
	rep(i,1,m){
		if (i>1) ins(a[i-1],-1);
		while (j<m&&E) ins(a[++j],1);
		if (E) continue;
		if ((i-1)/k+(m-j)/k+1<n) continue;
		if (j-i+1-k<=D){
			vector<int> S;
//			printf("ok %d %d  %d\n",i,j,j-i+1-k);
			rep(t,i,j){
//				printf("test col %d: c %d lim %d\n",a[k],c[a[k]],lim[a[k]]);
//				printf("test k %d  %d %d\n",k,int(S.size())<j-i+1-k,c[a[k]]>lim[a[k]]);
//				printf("test )
				if (int(S.size())<j-i+1-k&&c[a[t]]>lim[a[t]]){
					--c[a[t]]; S.pb(t);
				}
			}
			printf("%d\n",int(S.size()));
			for (int x: S) printf("%d ",x);
			puts("");
			return;
		}
	}
	puts("-1");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}