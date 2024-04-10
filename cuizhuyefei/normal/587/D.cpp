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
struct Pii{
	int fi,se,th,fo;
	Pii(int a=0,int b=0,int c=0,int d=0){fi=a;se=b;th=c;fo=d;}
};
bool cmp(Pii x, Pii y){return x.se<y.se;}
const int N = 302000;
int n,m,A[N],B[N],C[N],D[N];vector<Pii>e[N];Vi ans;
int head[N],to[N*8],nxt[N*8],edgenum;
//inline int inv(int a) {return (a&1)?a+1:a-1;}
inline void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int dfn[N],low[N],sta[N],top,col[N],num,cnt;
bool insta[N];
inline void tarjan(int u) {
	dfn[u]=low[u]=++num; sta[++top]=u; insta[u]=1;
	L(i,u) if (!dfn[to[i]]) {
		tarjan(to[i]); low[u]=min(low[u],low[to[i]]);
	}
	else if (insta[to[i]]) low[u]=min(low[u],dfn[to[i]]);
	if (dfn[u]==low[u]) {
		cnt++;
		while (1) {
			int x=sta[top--]; insta[x]=0; 
			col[x]=cnt; if (x==u) break;
		}
	}
}
int dy(int x, int y){return y*m+x;}//0:not 1:cho
bool ck(int mid){
	int tot=m*2;
	rep(i,1,m*6)insta[i]=col[i]=head[i]=dfn[i]=0;edgenum=1;cnt=num=top=0;
	rep(i,1,m)if(D[i]>mid)addedge(dy(i,1),dy(i,0));
	rep(u,1,n)rep(i,0,SZ(e[u])-1){
		int j=i;while(j+1<SZ(e[u])&&e[u][i].se==e[u][j+1].se)j++;
		if(j-i+1>2)return 0;
		if(j-i+1==2){
			int x=e[u][i].th,y=e[u][j].th;
			addedge(dy(x,0),dy(y,1));addedge(dy(y,0),dy(x,1));
		}
		i=j;
	}
	rep(u,1,n){
		static int qz[N],hz[N];
		rep(i,0,SZ(e[u])-1){
			qz[i]=++tot,hz[i]=++tot;
			addedge(qz[i],dy(e[u][i].th,0)),addedge(hz[i],dy(e[u][i].th,0));
		}
		rep(i,0,SZ(e[u])-2)addedge(qz[i+1],qz[i]),addedge(hz[i],hz[i+1]);
		rep(i,0,SZ(e[u])-1){
			if(i-1>=0)addedge(dy(e[u][i].th,1),qz[i-1]);
			if(i+1<SZ(e[u]))addedge(dy(e[u][i].th,1),hz[i+1]);
		}
	}
	rep(i,1,tot)if(!dfn[i])tarjan(i);
	rep(i,1,m)if(col[dy(i,0)]==col[dy(i,1)])return 0;
	ans.clear();rep(i,1,m)if(col[dy(i,0)]>col[dy(i,1)])ans.pb(i);
	return 1;
}
int main() {
	read(n);read(m);static int s[N];
	rep(i,1,m)read(A[i]),read(B[i]),read(C[i]),read(D[i]),s[i]=D[i];
	rep(i,1,m)
		e[A[i]].pb(Pii(B[i],C[i],i,D[i])),e[B[i]].pb(Pii(A[i],C[i],i,D[i]));
	rep(u,1,n)sort(e[u].begin(),e[u].end(),cmp);
	sort(s+1,s+m+1);
	if(!ck(s[m])){puts("No");return 0;}
	int l=0,r=m;
	while(l<r){
		int mid=(l+r)>>1;
		if(ck(s[mid]))r=mid;else l=mid+1;
	}
	ck(s[l]);
	puts("Yes");printf("%d %d\n",s[l],SZ(ans));
	rep(i,0,SZ(ans)-1)printf("%d ",ans[i]);
	return 0;
}