#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=400010;
struct edge{
	int next,to;
}e[maxn];
int head[maxn],len;
void add(int x,int y){
	e[++len]={head[x],y};
	head[x]=len;
}
int i,j,k,n,m,T,vis[maxn],deep[maxn];
void dfs(int now,int fa){
	deep[now]=deep[fa]+1;
	vis[deep[now]&1]++;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		dfs(u,now);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i=1;i<n;i++){
		int a=read(),b=read();
		add(a,b);
		add(b,a);
	}dfs(1,0);
	cout<<max(0,min(vis[0],vis[1])-1)<<endl;
}