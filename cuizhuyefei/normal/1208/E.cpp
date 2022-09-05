#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1520000,inf=0x3f3f3f3f;
int m,n,len,a[N];ll val[N];
namespace tree{
	int a[N<<2],n;
	inline void init(int m, int *c){
		for(n=1;n<=m+1;n<<=1);
		rep(i,0,n*2)a[i]=-inf;
		rep(i,1,m)a[n+i]=c[i];
		per(i,n-1,1)a[i]=max(a[i<<1],a[i<<1|1]);
	}
	inline int query(int l, int r){
		int res=-inf,u=n+l-1,v=n+r+1;
	//	assert(l<=r);
		while((u>>1)!=(v>>1)){
			if(!(u&1))umax(res,a[u+1]);
			if(v&1)umax(res,a[v-1]);
			u>>=1;v>>=1;
		}
		return res;
	}
}
inline void solve(int i){
	int res=tree::query(max(1,i+len-n),min(i,len));
	if(i+len<=n||i>len)umax(res,0);
	val[i]+=res;val[i+1]-=res;
}
int main() {
	read(m);read(n);
	while(m--){
		read(len);rep(i,1,len)read(a[i]);
		tree::init(len,a);
		if(len*2<n){
			rep(i,1,len)solve(i);rep(i,n-len+1,n)solve(i);
			int mx=0;rep(i,1,len)umax(mx,a[i]);
			val[len+1]+=mx;val[n-len+1]-=mx;
		}
		else{rep(i,1,n)solve(i);}
	}
	rep(i,1,n)val[i]+=val[i-1],printf("%lld ",val[i]);
	return 0;
}