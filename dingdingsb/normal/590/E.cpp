#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
const int N=800,M=1e7+10,E=N*N*2;
namespace G{
	int head[2*N],cur[2*N],dis[2*N],cnt;
	int v[E],w[E],nxt[E];
	void adde(int U,int V,int W){cnt++,v[cnt]=V,w[cnt]=W,nxt[cnt]=head[U],head[U]=cnt;}
	void add(int u,int v,int w){adde(u,v,w);adde(v,u,0);}
	int s,t;
	void init(int _s,int _t){
		s=_s,t=_t;cnt=1;
		memset(head,0,sizeof head);
	}
	bool bfs(){
		memset(dis,0xff,sizeof dis);
		memcpy(cur,head,sizeof cur);
		static int q[2*N];int hd=1,tl=0;
		dis[q[++tl]=s]=1;
		while(hd<=tl){
			int u=q[hd++];
			for(int i=head[u];i;i=nxt[i])if(w[i]&&dis[v[i]]==-1)
				dis[q[++tl]=v[i]]=dis[u]+1;
		}
		return dis[t]!=-1;
	}
	int dfs(int u,int flow){
		if(u==t)return flow;
		int rest=flow;
		for(int i=cur[u];i&&rest;i=nxt[i]){
			if(dis[v[i]]==dis[u]+1&&w[i]){
				int tmp=dfs(v[i],min(rest,w[i]));
				w[i]-=tmp,w[i^1]+=tmp,rest-=tmp;
			}
			cur[u]=i;
		}
		if(rest)dis[u]=-1;
		return flow-rest;
	}
	int dinic(){
		int ans=0;
		while(bfs())
			while(int wyh=dfs(s,2e9))
				ans+=wyh;
		return ans;
	}
	bool vis[2*N];
	void dfs(int u){
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])if(w[i]&&!vis[v[i]])dfs(v[i]);
	}
}
int n;string s[M];
int ch[M][2],ed[M],fail[M],cnt;
void ins(int id){
	int now=0;
	for(int i=0;i<(int)s[id].size();i++){
		int c=s[id][i]-'a';
		if(!ch[now][c])ch[now][c]=++cnt;
		now=ch[now][c];
	}
	ed[now]=id;
}
void getfail(){
	static int q[M];int hd=1,tl=0;
	for(int i=0;i<2;i++)if(ch[0][i])q[++tl]=ch[0][i];
	while(hd<=tl){
		int u=q[hd++];
		for(int i=0;i<2;i++)
			if(ch[u][i]){
				fail[q[++tl]=ch[u][i]]=ch[fail[u]][i];
				if(!ed[ch[u][i]])ed[ch[u][i]]=ed[fail[ch[u][i]]];
			}else ch[u][i]=ch[fail[u]][i];
	}
}
bool vis[N],f[N][N];
void calc(int id){
	int now=0;
	for(int i=0;i<(int)s[id].size();i++){
		now=ch[now][s[id][i]-'a'];
		vis[ed[now]]=1;vis[ed[fail[now]]]=1;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i],ins(i);
	getfail();
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		calc(i);
		for(int j=1;j<=n;j++)if(i!=j&&vis[j])
			f[i][j]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]|=(f[i][k]&f[k][j]);
	G::init(2*n+1,2*n+2);
	for(int i=1;i<=n;i++)G::add(G::s,i,1),G::add(i+n,G::t,1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(f[i][j])G::add(i,j+n,1);
	cout<<n-G::dinic()<<endl;
	G::dfs(G::s);
	vector<int>ans;for(int i=1;i<=n;i++)if(G::vis[i]&&!G::vis[i+n])ans.pb(i);
	sort(ans.begin(),ans.end());for(auto x:ans)cout<<x<<" ";
}