#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1<<21|3;
int n,a[N],b[N],ans[N],f[N],vis[N],deg[N];

int head[N],to[N],nxt[N],edgenum=1;
int sta[N],top;bool used[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u){
	while(head[u]){
		int i=head[u];head[u]=nxt[i];
		if(used[i>>1])continue;
		used[i>>1]=1;dfs(to[i]);sta[++top]=i;
	}
}
void solve(int k){
	rep(i,0,(1<<k)-1)f[i+1]=i+1,deg[i+1]=vis[i+1]=0;
	rep(i,1,n){
		int u=a[i]&((1<<k)-1),v=b[i]&((1<<k)-1);
		u++;v++;
		deg[u]++;deg[v]--;vis[u]=vis[v]=1;
		to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
		to[++edgenum]=u;nxt[edgenum]=head[v];head[v]=edgenum;
	}
	rep(i,0,(1<<k)-1)if(vis[i+1]){
		dfs(i+1);
	}
	int len=0;
//	per(i,top,1)printf("%d ",sta[i]);puts("");
	per(i,top,1){
		int x=(sta[i]>>1)*2-1,y=(sta[i]>>1)*2;
		if(sta[i]&1)swap(x,y);
		ans[++len]=x;ans[++len]=y;
	}
}
bool ck(int k){
	rep(i,0,(1<<k)-1)f[i+1]=i+1,deg[i+1]=vis[i+1]=0;
	rep(i,1,n){
		int u=a[i]&((1<<k)-1),v=b[i]&((1<<k)-1);
		u++;v++;
		f[find(u)]=find(v);
		deg[u]++;deg[v]++;vis[u]=vis[v]=1;
	}
	rep(i,0,(1<<k)-1)if(deg[i+1]%2)return 0;
	set<int>Set;
	rep(i,0,(1<<k)-1)if(vis[i+1]){
		Set.insert(find(i+1));if(SZ(Set)>1)return 0;
	}
	return 1;
}
int main() {
	read(n);rep(i,1,n)read(a[i]),read(b[i]);
	rep(i,1,n*2)ans[i]=i;
	int k=1;
	while(k<=20&&ck(k))k++;
	k--;
	if(k)solve(k);
	printf("%d\n",k);
	rep(i,1,2*n)printf("%d ",ans[i]);
	return 0;
}