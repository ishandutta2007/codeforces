#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1000010;
int i,j,k,n,m,T,F[maxn],vis[maxn],ROOT[maxn],DEEP[maxn],sum[maxn],cnt,FA[maxn][21],deep[maxn],dfn[maxn],tot,size[maxn];
namespace BIT{
	int tree[maxn];
	int lowbit(int x){return x&(-x);}
	void add(int x,int s){for(;x<=n;x+=lowbit(x))tree[x]+=s;}
	int find(int x){if(!x)return 0;int ans=0;for(;x;x-=lowbit(x))ans+=tree[x];return ans;}
}
struct edge{
	int next,to,w;
}e[maxn*2];
struct QUERY{
	int x,y,z,ans;
}Q[maxn*2];
int head[maxn],len;
void add(int x,int y,int z){
	e[++len]={head[x],y,z};
	head[x]=len;
}
int find(int x){
	return F[x]==x?x:F[x]=find(F[x]);
}
void dfs(int now,int fa){
	vis[now]=cnt;FA[now][0]=fa;deep[now]=deep[fa]+1;dfn[now]=++tot;size[now]=1;
	for(int i=1;i<=20;i++)FA[now][i]=FA[FA[now][i-1]][i-1];
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		DEEP[u]=DEEP[now]^e[i].w;
		dfs(u,now);
		size[now]+=size[u];
	}
}
int lca(int x,int y){
	if(deep[x]>deep[y])swap(x,y);
	for(int i=20;i>=0;i--)if(deep[x]<=deep[FA[y][i]])y=FA[y][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(FA[x][i]!=FA[y][i])x=FA[x][i],y=FA[y][i];
	return FA[x][0];
}
void work(int x,int y){
	if(x==y)return;
	BIT::add(dfn[x]+size[x],-1);
	BIT::add(dfn[x],1);
	work(FA[x][0],y);
}
int getsum(int x){
	return BIT::find(dfn[x]);
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)F[i]=i;
	for(i=1;i<=m;i++){
		int x,y,w;
		x=read();y=read();w=read();
		if(find(x)!=find(y)){
			add(x,y,w);
			add(y,x,w);
			F[find(x)]=y;
			Q[i].ans=1;
		}
		Q[i].x=x;Q[i].y=y;Q[i].z=w;
	}
	for(i=1;i<=n;i++)if(!vis[i])ROOT[++cnt]=i,dfs(i,0);
	for(i=1;i<=m;i++){
		if(!Q[i].ans){
			int x=Q[i].x,y=Q[i].y,w=Q[i].z;
			int z=lca(x,y);
			//cout<<x<<' '<<y<<' '<<w<<' '<<z<<endl;
			if(getsum(x)+getsum(y)==2*getsum(z)){
				if((DEEP[x]^DEEP[y])!=w){
					puts("YES");
					work(x,z);
					work(y,z);
				}else puts("NO");
			}else puts("NO");
		}else{
			puts("YES");
		}
	}
}