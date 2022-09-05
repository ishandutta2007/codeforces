#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 804000;
int n,s,A[N],f[N];bool vis[N];
struct ele{int v,ind;}a[N];
bool cmp(ele a, ele b){return a.v<b.v;}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int head[N],to[N<<1],nxt[N<<1],edgenum;
void add(int u, int v){//printf("add %d %d\n",u,v);
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
int q;Vi ans[N];
inline void dfs(int u){
	while(head[u]){
		int i=head[u];head[u]=nxt[i];dfs(to[i]);if(u<=n)ans[q].pb(u);
	}
}
int main() {
	read(n);read(s);rep(i,1,n)read(a[i].v),a[i].ind=i,A[i]=a[i].v;
	sort(a+1,a+n+1,cmp);rep(i,1,n)vis[i]=A[i]==a[i].v;
	rep(i,1,n)f[i]=i;rep(i,1,n-1)if(a[i].v==a[i+1].v)f[find(i+1)]=find(i);
	rep(i,1,n)if(!vis[i])add(n+find(i),i);
	rep(i,1,n)if(!vis[a[i].ind])add(a[i].ind,n+find(i));
	rep(i,1,n)if(head[i])q++,ans[q].clear(),dfs(i),reverse(ans[q].begin(),ans[q].end()),q-=SZ(ans[q])<=1;
	int tot=0;rep(i,1,q)tot+=SZ(ans[i]);if(tot>s){puts("-1");return 0;}
	per(i,q,3)if(tot+i<=s){
		Vi x,y;//[q-i+1,q]
		rep(a,q-i+1,q){
			int len=SZ(ans[a]);rep(b,0,len-1)x.pb(ans[a][b]);
		}
		per(a,q,q-i+1)y.pb(ans[a][0]);
		q-=i;ans[++q]=x;ans[++q]=y;//order of x,y is important
		break;
	}
	printf("%d\n",q);rep(i,1,q){
		int len=SZ(ans[i]);printf("%d ",len);
		rep(j,0,len-1)printf("%d ",ans[i][j]);puts("");
	}
	return 0;
}