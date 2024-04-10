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
const int N = 2008000;
int n,m;
int head[N],to[N*8],nxt[N*8],edgenum;
//inline int inv(int a) {return (a&1)?a+1:a-1;}
inline void add(int u, int v) {
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
/*int dy(int x, int y){
	return x+y*n;
}*///(x,0)A (x,1)B
int main() {
	int T;read(T);while(T--){
		read(n);read(m);rep(i,0,2*n)head[i]=dfn[i]=col[i]=insta[i]=0;edgenum=0;
		num=cnt=top=0;
		rep(i,1,m){
			int u,v;read(u);read(v);
			if(u==v)continue;
			add(u,v);
		//	add(dy(u,0),dy(v,0));
		//	add(dy(v,1),dy(u,1));
		}
		rep(i,1,n)if(!dfn[i])tarjan(i);
		bool gg=0;
	//	rep(i,1,n)gg|=col[dy(i,0)]==col[dy(i,1)];
		if(cnt==1)puts("No");
		else{
			puts("Yes");
			Vi zuo,you;
			rep(i,1,n)if(col[i]==1)zuo.pb(i);else you.pb(i);
			printf("%d %d\n",SZ(zuo),SZ(you));
			rep(i,0,SZ(zuo)-1)printf("%d ",zuo[i]);puts("");
			rep(i,0,SZ(you)-1)printf("%d ",you[i]);puts("");
		}
	}
	return 0;
}