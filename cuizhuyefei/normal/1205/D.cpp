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
const int N = 6666;
struct node{int x,y,z;};vector<node>ans;
int n,len,sz[N],s[N];Vi e[N];int bel[N];int val[N],tota,totb,A;
bool cmp(int x, int y){return sz[x]>sz[y];}
void dfsa(int u, int fa){
	tota++;val[u]=tota;ans.pb((node){u,fa,val[u]-val[fa]});
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfsa(e[u][i],u);
}
void dfsb(int u, int fa){
	totb+=A;val[u]=totb;ans.pb((node){u,fa,val[u]-val[fa]});
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfsb(e[u][i],u);
}
void dfs(int u, int fa){
	sz[u]=1;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
		dfs(e[u][i],u),sz[u]+=sz[e[u][i]];
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	if(n==2){
		printf("1 2 1\n");
		return 0;
	}
	rep(rt,1,n){
		dfs(rt,0);
		len=0;rep(i,0,SZ(e[rt])-1)s[++len]=e[rt][i];
		sort(s+1,s+len+1,cmp);
		if((sz[s[1]])*3>2*n)continue;
		int cur=sz[s[1]];bel[rt]=1;//=bel[s[1]]=1;
		rep(i,2,len)if(cur*3<n&&(cur+sz[s[i]])*3<=2*n)
			cur+=sz[s[i]],bel[s[i]]=0;
		else bel[s[i]]=1;
	//	assert(cur>=1.0*n/3&&cur<=2.0*n/3);
		cerr<<"rt= "<<rt<<' '<<cur<<endl;
	//	assert(cur*(n-cur)*9>=2*n*n);
		A=cur;
		rep(i,1,len)if(bel[s[i]])dfsb(s[i],rt);else dfsa(s[i],rt);
		assert(SZ(ans)==n-1);
		rep(i,0,SZ(ans)-1)
			printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
		return 0;
	}
	return 0;
}