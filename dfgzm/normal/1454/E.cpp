#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
struct edge{
	int next,to;
}a[maxn*2];
int head[maxn],len,vis[maxn],is[maxn];
int B;vector<int>V;
void add(int x,int y){
	a[++len]={head[x],y};
	head[x]=len;
}
void dfs(int now,int fa){
	vis[now]=1;
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa || B)continue;
		if(vis[u])B=1,vis[u]=2;
		else dfs(u,now);
	}if(B==1)V.push_back(now),is[now]=1;
	if(vis[now]==2)B=2;
}
int i,j,k,n,m,T;ll size[maxn];ll ans,last;
void dfs2(int now,int fa){
	size[now]=1;
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa || is[u])continue;
		dfs2(u,now);
		size[now]+=size[u];
	}
}
int main(){
	int T=read();
	while(T--){
		B=0;n=read();V.clear();
		ans=last=len=0;for(i=1;i<=n;i++)size[i]=head[i]=vis[i]=is[i]=0;
		for(i=1;i<=n;i++){
			int x=read(),y=read();
			add(x,y);add(y,x);
		}dfs(1,0);
		for(i=0;i<V.size();i++){
			int now=V[i];
			dfs2(now,0);
//			cout<<"size "<<now<<" = "<<size[now]<<endl;
			ans+=size[now]*(size[now]-1)/2+size[now]*last*2;
			last+=size[now];
		}printf("%lld\n",ans);
	}
	return 0;
}