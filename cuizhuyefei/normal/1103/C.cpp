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
const int N = 505000;
int n,m,k,head[N],to[N<<1],nxt[N<<1],edgenum=1;
void add(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
int fa[N],dep[N],ch[N];Vi a[N];
void dfs(int u, int d){
	dep[u]=d;
	L(i,u)if(to[i]!=fa[u]){
		if(dep[to[i]]==-1){
			fa[to[i]]=u;dfs(to[i],d+1);ch[u]++;
		}
		else if(dep[to[i]]<dep[u]){
			a[u].pb(to[i]);
		}
	}
}
int main() {
	memset(dep,-1,sizeof(dep));
	read(n);read(m);read(k);
	rep(i,1,m){int u,v;read(u);read(v);add(u,v);add(v,u);}
	dfs(1,1);
	rep(i,1,n)if(1LL*dep[i]*k>=n){
		puts("PATH");
		Vi s;for(int u=i;u;u=fa[u])s.pb(u);
		printf("%d\n",SZ(s));rep(i,0,SZ(s)-1)printf("%d ",s[i]);
		return 0;
	}
	puts("CYCLES");
	rep(u,1,n)if(k&&!ch[u]){
		bool find=0;
		rep(j,0,1)if((dep[u]-dep[a[u][j]]+1)%3&&!find){
			find=1;Vi s;
			for(int i=u;;i=fa[i]){s.pb(i);if(i==a[u][j])break;}
			printf("%d\n",SZ(s));rep(i,0,SZ(s)-1)printf("%d ",s[i]);puts("");
		}
		if(!find){
			int x=a[u][0],y=a[u][1];if(dep[x]<dep[y])swap(x,y);
			//dep[x]>dep[y]
			Vi s;s.pb(u);
			for(int i=x;;i=fa[i]){s.pb(i);if(i==y)break;}
			printf("%d\n",SZ(s));rep(i,0,SZ(s)-1)printf("%d ",s[i]);puts("");
		}
		k--;
	}
	return 0;
}