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
const int N = 466666,inf=0x3f3f3f3f;
int n,k,dis[N],pre[N],q[N];Vi e[N];
int s[N],len,ans[N];bool gg[N];
int bfs(int S){
	rep(i,0,n)dis[i]=inf;int f=0,r=1;q[f]=S;dis[S]=0;
	memset(pre,0,sizeof(pre));
	int res=S;
	while(f!=r){
		int u=q[f++];if(dis[u]>dis[res])res=u;
		rep(i,0,SZ(e[u])-1)if(dis[e[u][i]]>dis[u]+1){
			dis[e[u][i]]=dis[u]+1;q[r++]=e[u][i];pre[e[u][i]]=u;
		}
	}
	return res;
}
void GG(){puts("No");exit(0);}
int CUR;
void dfs(int u, int fa, int d){
//	gg[u]=1;
	if(!gg[u]&&d+CUR>=k&&d+len-CUR+1>=k)GG();
	if(CUR>len-CUR+1){
		ans[u]=(CUR+d)%k;if(!ans[u])ans[u]=k;
	}
	else{
		ans[u]=((CUR-d)%k+k)%k;if(!ans[u])ans[u]=k;
	}
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa&&!gg[e[u][i]])
		dfs(e[u][i],u,d+1);
}
void ini(int S, int T){
	for(int u=T;;u=pre[u]){s[++len]=u;if(u==S)break;}
	rep(i,1,len)ans[s[i]]=i%k==0?k:i%k,gg[s[i]]=1;
	for(CUR=1;CUR<=len;CUR++){
		dfs(s[CUR],0,0);
	}
}
void DFS(int u, int fa, int x){
	ans[u]=x;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
		DFS(e[u][i],u,3-x);
}
int main() {
	read(n);read(k);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	if(k==2){
		DFS(1,0,1);
		puts("Yes");rep(i,1,n)printf("%d ",ans[i]);return 0;
	}
	int s=bfs(1),t=bfs(s);
	if(dis[t]<=k-2){
		puts("Yes");rep(i,1,n)printf("1 ");return 0;
	}
	ini(s,t);
	puts("Yes");rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}