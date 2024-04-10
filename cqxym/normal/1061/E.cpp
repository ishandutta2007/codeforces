#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
#define N 1007
#define M 7009
#define INF 999999
int val[501],f[2][501],lim[2][501],Last[N],Next[M],End[M],Cap[M],Cost[M],dis[N],pre[N],deg[N];
vector<int>G[501];
I void DFS(int x,int F,int*Fa){
	Fa[x]=F;
	for(int T:G[x]){
		if(T!=F){
			DFS(T,x,Fa);
		}
	}
}
bool in[N];
I bool SPFA(int S,int T,const int n){
	for(R i=1;i<=n;i++){
		dis[i]=-999999999;
	}
	dis[S]=0;
	queue<int>Q;
	Q.push(S);
	while(Q.empty()==false){
		int x=Q.front();
		Q.pop();
		in[x]=false;
		for(R i=Last[x];i!=0;i=Next[i]){
			int y=End[i];
			if(Cap[i]!=0&&dis[y]<dis[x]+Cost[i]){
				dis[y]=dis[x]+Cost[i];
				pre[y]=i;
				if(in[y]==false){
					in[y]=true;
					Q.push(y);
				}
			}
		}
	}
	return dis[T]!=-999999999;
}
I int MaxCost(int S,int T,const int n,int&res){
	int sum=0;
	while(SPFA(S,T,n)==true){
		int flow=INF;
		for(R i=T;i!=S;i=End[pre[i]^1]){
			if(Cap[pre[i]]<flow){
				flow=Cap[pre[i]];
			}
		}
		res+=flow*dis[T];
		sum+=flow;
		for(R i=T;i!=S;i=End[pre[i]^1]){
			Cap[pre[i]]-=flow;
			Cap[pre[i]^1]+=flow;
		}
	}
	return sum;
}
int main(){
	int n,A,B,ct=1,x,y,S,T,S2,T2,q,sum=0,ans=0,cur;
	scanf("%d%d%d",&n,&A,&B);
	S=n<<1|1;
	T=n+B;
	S2=S+1;
	T2=S+2;
	for(R i=1;i<=n;i++){
		scanf("%d",val+i);
		lim[0][i]=lim[1][i]=-1;
	}
	auto ReadTree=[&](){
		for(R i=1;i!=n;i++){
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
	};
	ReadTree();
	DFS(A,0,f[0]);
	for(R i=1;i<=n;i++){
		G[i].clear();
	}
	ReadTree();
	DFS(B,0,f[1]);
	scanf("%d",&q);
	auto Exit=[](){
		printf("-1");
		exit(0);
	};
	for(R i=0;i!=q;i++){
		scanf("%d%d",&x,&y);
		if(lim[0][x]!=-1){
			if(lim[0][x]!=y){
				Exit();
			}
		}else{
			lim[0][x]=y;
		}
	}
	auto Link=[&](int x,int y,int c,int w){
		ct++;
		End[ct]=y;
		Cap[ct]=c;
		Cost[ct]=w;
		Next[ct]=Last[x];
		Last[x]=ct;
		ct++;
		End[ct]=x;
		Cost[ct]=-w;
		Next[ct]=Last[y];
		Last[y]=ct;
	};
	Link(S,A,lim[0][A],0);
	for(R i=1;i<=n;i++){
		if(i!=A){
			if(lim[0][i]==-1){
				Link(f[0][i],i,INF,0);
			}else{
				deg[f[0][i]]+=lim[0][i];
				deg[i]-=lim[0][i];
			}
		}
	}
	scanf("%d",&q);
	for(R i=0;i!=q;i++){
		scanf("%d%d",&x,&y);
		if(lim[1][x]!=-1){
			if(lim[1][x]!=y){
				Exit();
			}
		}else{
			lim[1][x]=y;
		}
	}
	if(lim[0][A]!=lim[1][B]){
		Exit();
	}
	for(R i=1;i<=n;i++){
		Link(i,i+n,1,val[i]);
		if(i!=B){
			if(lim[1][i]==-1){
				Link(i+n,f[1][i]+n,INF,0);
			}else{
				deg[i+n]+=lim[1][i];
				deg[f[1][i]+n]-=lim[1][i];
			}
		}
	}
	cur=ct;
	for(R i=1;i<=n<<1;i++){
		if(deg[i]>0){
			sum+=deg[i];
			Link(i,T2,deg[i],0);
		}else if(deg[i]!=0){
			Link(S2,i,-deg[i],0);
		}
	}
	Link(T,S,INF,-INF);
	if(sum!=MaxCost(S2,T2,T2,ans)){
		Exit();
	}
	ans+=INF*Cap[ct];
	for(R i=1;i<=S;i++){
		while(Last[i]>cur){
			Last[i]=Next[Last[i]];
		}
	}
	MaxCost(S,T,S,ans);
	if(Cap[2]!=0){
		Exit();
	}
	printf("%d",ans);
	return 0;
}