#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3010,mod=998244353;
struct E{
	int x,y,z;
}e[maxn*maxn/4];
struct edge{
	int next,to;
}g[maxn];int head[maxn],len;
void add(int x,int y){
//	cout<<"add "<<x<<"->"<<y<<endl;
	g[++len]={head[x],y};
	head[x]=len;
}
int i,j,k,n,m,cnt;
bool cmp(E a,E b){
	return a.z<b.z;
}
int F[maxn],num[maxn],size[maxn],id[maxn];
int is=0;
int find(int x){
	return F[x]==x?x:F[x]=find(F[x]);
}
bool check(int x){
	return (num[x]*(num[x]-1)/2)==size[x];
}
int to[maxn],Size[maxn];ll ans[maxn][maxn],tmp[maxn];
void dfs(int now,int fa){
//	cout<<"dfs.. "<<now<<endl;
	ans[now][0]=1;Size[now]=1;
	for(int i=head[now];i;i=g[i].next){
		int u=g[i].to;
		if(u==fa)continue;
		dfs(u,now);
		for(int j=1;j<=Size[u];j++)
			for(int k=0;k<=Size[now];k++)
				tmp[j+k]+=ans[u][j]*ans[now][k]%mod;
		Size[now]+=Size[u];
		for(int j=1;j<=Size[now];j++)
			ans[now][j]=tmp[j]%mod,tmp[j]=0;
		ans[now][0]=0;
	}ans[now][1]++;
//	cout<<"end. "<<now<<endl;
//	for(int j=0;j<=Size[now];j++)cout<<ans[now][j]<<' ';cout<<endl;
}
bool vis[maxn];
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			if(i>j)e[++cnt]={i,j,x};
		}
	sort(e+1,e+1+cnt,cmp);
	for(i=1;i<=n;i++)F[i]=id[i]=i,num[i]=1;
	int w=n;
	for(i=1;i<=cnt;i++){
		int X=find(e[i].x),Y=find(e[i].y);
//		cout<<"X="<<X<<" Y="<<Y<<endl;
		if(X!=Y){
			F[X]=Y;
			num[Y]+=num[X];
			size[Y]+=size[X];
			size[Y]++;
		}else size[Y]++;
		if(check(Y)){
			++w;
			for(j=1;j<=n;j++)
				if(!vis[id[j]] && find(j)==Y)add(w,id[j]),vis[id[j]]=1,id[j]=w;
			is-=num[Y];
		}
	}dfs(w,0);
	for(j=1;j<=n;j++)printf("%lld ",ans[w][j]);cout<<endl;
	return 0;
}