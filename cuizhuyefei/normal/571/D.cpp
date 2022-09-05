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
const int N = 566666;
int n,m;ll ans[N],v[N];Vi que[N];
char op[N];int A[N],B[N];
void modify(int p, int x){while(p<=n)v[p]+=x,p+=p&-p;}
ll qry(int p){ll r=0;while(p)r+=v[p],p-=p&-p;return r;}
struct zkw{
	int a[N<<2],m;
	inline void ini(int n){
		for(m=1;m<=n+1;m<<=1);
	}
	inline void modify(int l, int r, int x){
		l=m+l-1;r=m+r+1;
		while((l>>1)!=(r>>1)){
			if(!(l&1))umax(a[l+1],x);
			if(r&1)umax(a[r-1],x);
			l>>=1;r>>=1;
		}
	}
	inline int qry(int k){
		int res=0;for(int i=m+k;i;i>>=1)umax(res,a[i]);return res;
	}
}seg;
struct Tree{
	int fa[N],sz[N],dep[N],dl[N],dr[N],num,r[N];Vi e[N];
	void dfs(int u, int Fa, int Dep){
		fa[u]=Fa;dep[u]=Dep;dl[u]=++num;sz[u]=1;
		rep(i,0,SZ(e[u])-1)dfs(e[u][i],u,Dep+1),sz[u]+=sz[e[u][i]];
		dr[u]=num;
	}
	void ini(){
		rep(i,1,n)if(!fa[i])dfs(i,0,1);
	}
}a,b;
int Abs(int x){return x>0?x:-x;}
int sgn(int x){return x>0?1:-1;}
int main() {
	read(n);read(m);
	rep(i,1,m){
		char t[3];scanf("%s",t);
		op[i]=t[0];read(A[i]);
		if(op[i]=='U'||op[i]=='M'){
			read(B[i]);
			if(op[i]=='U')a.fa[B[i]]=A[i],a.e[A[i]].pb(B[i]);
			else b.fa[B[i]]=A[i],b.e[A[i]].pb(B[i]);
		}
	}
	a.ini();b.ini();seg.ini(b.num);
	rep(i,1,n)a.r[i]=a.dl[i],b.r[i]=b.dl[i];
	rep(i,1,m)
		if(op[i]=='Z')seg.modify(b.dl[A[i]],b.r[A[i]],i);
		else if(op[i]=='Q')que[i].pb(i),que[seg.qry(b.dl[A[i]])].pb(-i);
		else if(op[i]=='M')b.r[A[i]]=b.dr[B[i]];
	rep(i,1,m){
		if(op[i]=='A'){
		//	cerr<<i<<' '<<a.dl[A[i]]<<' '<<a.r[A[i]]<<endl;
			modify(a.dl[A[i]],a.r[A[i]]+1-a.dl[A[i]]),modify(a.r[A[i]]+1,-(a.r[A[i]]+1-a.dl[A[i]]));
		}
		else if(op[i]=='U')a.r[A[i]]=a.dr[B[i]];
		rep(j,0,SZ(que[i])-1)ans[Abs(que[i][j])]+=sgn(que[i][j])*qry(a.dl[A[Abs(que[i][j])]]);
	}
	rep(i,1,m)if(op[i]=='Q')printf("%lld\n",ans[i]);
	return 0;
}