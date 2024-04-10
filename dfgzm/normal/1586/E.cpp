#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=600010;
struct edge{
	int next,to,is,w;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y,int z=0){
	e[++len]={head[x],y,z,0};
	head[x]=len;
}
int i,j,k,n,m,T,q,vis[maxn],deep[maxn],X[maxn],Y[maxn];
int nl[maxn][3];
void dfs(int now,int fa){
	vis[now]=1;deep[now]=deep[fa]+1;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa || vis[u])continue;
		e[i].is=1;//e[((i-1)^1)+1].is=1;
		dfs(u,now);
	}
}
bool B=false;
int check(int now,int fa,int X){
	bool IS=0;
	if(now==X)return 1;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa || !e[i].is)continue;
		if(check(u,now,X))IS=1,e[i].w++;
	}
	return IS;
}
vector<int>ans[maxn];
int workout(int now,int fa,int X,int id){
	bool IS=0;
	if(now==X){ans[id].push_back(now);return 1;}
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa || !e[i].is)continue;
		if(workout(u,now,X,id))IS=1;
	}if(IS)ans[id].push_back(now);
	return IS;
}
int D[maxn],sum2[maxn],ANS;
void workNO(int now,int fa,int I){
	int F=0;
	if(now!=1)F=(e[I].w+e[((I-1)^1)+1].w)&1;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa || !e[i].is)continue;
		workNO(u,now,i);
		sum2[now]^=sum2[u];
	}
	if(sum2[now]!=F)sum2[now]^=1,++ANS;
}
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	cin>>q;
	dfs(1,0);
	int cnt=0;
	for(i=1;i<=n;i++)
		for(j=head[i];j;j=e[j].next){
			int u=e[j].to;
			if(e[j].is)nl[++cnt][1]=i,nl[cnt][2]=u;
		}
	memset(head,0,sizeof(head));len=0;
	for(i=1;i<=cnt;i++)add(nl[i][1],nl[i][2],1),add(nl[i][2],nl[i][1],1);
	for(i=1;i<=q;i++){
		int x=read(),y=read();
		X[i]=x;Y[i]=y;
		check(x,0,y);
	}
	bool IS=true;
	for(i=1;i<=2*m;i+=2)
		if((e[i].w+e[i+1].w)%2)IS=false;
	if(IS){
		cout<<"YES"<<endl;
		for(i=1;i<=q;i++){
			workout(X[i],0,Y[i],i);
			printf("%d\n",ans[i].size());
			assert(ans[i].size());
			for(j=ans[i].size()-1;j>=0;j--)printf("%d ",ans[i][j]);
			puts("");
		}
		return 0;
	}
	workNO(1,0,0);
	puts("NO");
	cout<<ANS/2<<endl;
}