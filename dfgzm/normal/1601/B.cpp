#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=6000100;
struct edge{
	int next,to,w;
}e[maxn*4];
int head[maxn],len;
void add(int x,int y,int z){
	//cout<<"ADD "<<x<<' '<<y<<' '<<z<<endl;
	e[++len]={head[x],y,z};
	head[x]=len;
}
priority_queue<pii>Q;
int i,j,k,n,m,T,a[maxn],b[maxn],id[maxn/20][21],cnt,Ln[maxn],Last[maxn];
int dis[maxn],vis[maxn];
void dfs(int now){
	if(Last[now])dfs(Last[now]);
	if(now>n && now<=2*n)printf("%d ",now-n-1);
}
int main(){
	cin>>n;cnt=n;
	Ln[0]=-1;for(i=1;i<=n;i++)Ln[i]=Ln[i/2]+1;
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=n;i++)b[i]=read();
	for(i=0;i<=n;i++)id[i][0]=++cnt,add(id[i][0],i+b[i],0);
	for(j=1;j<=19;j++)
		for(i=0;i+(1<<j)-1<=n;i++){
			if(!id[i][j])id[i][j]=++cnt/*,cout<<"id"<<i<<' '<<j<<' '<<cnt<<endl*/;
			add(id[i][j],id[i][j-1],0);
			add(id[i][j],id[i+(1<<j-1)][j-1],0);
		}
	for(i=1;i<=n;i++){
		int l=i-a[i],r=i,len=Ln[r-l+1];
		//cout<<l<<' '<<r<<' '<<len<<endl;
		add(i,id[l][len],1);
		add(i,id[r-(1<<len)+1][len],1);
	}
	memset(dis,0x3f,sizeof(dis));
	Q.push(make_pair(0,n));dis[n]=0;
	while(!Q.empty()){
		int x=Q.top().second;Q.pop();
		if(vis[x])continue;
		//cout<<"DFS "<<x<<' '<<Last[x]<<endl;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int u=e[i].to;
			if(dis[u]>dis[x]+e[i].w){
				dis[u]=dis[x]+e[i].w;
				Last[u]=x;
				Q.push((pii){-dis[u],u});
			}
		}
	}
	if(dis[0]==0x3f3f3f3f)puts("-1");
	else{
		cout<<dis[0]<<endl;
		dfs(0);
		cout<<endl;
	}
}