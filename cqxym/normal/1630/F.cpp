#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 50001
#define K 200005
#define M 3600000
#define INF 999999
I int Min(const int x,const int y){
	return x<y?x:y;
}
vector<int>D[N];
int Last[K],id[N],a[N],Ecur[K],gap[K],dis[K],Next[M],End[M],Cap[M],ct;
I void Link(int x,int y,int c){
	ct++;
	End[ct]=y;
	Cap[ct]=c;
	Next[ct]=Last[x];
	Last[x]=ct;
	ct++;
	Cap[ct]=0;
	End[ct]=x;
	Next[ct]=Last[y];
	Last[y]=ct;
}
I void BFS(int T,const int n){
	queue<int>Q;
	Q.push(T);
	for(R i=1;i<=n;i++){
		dis[i]=n;
		gap[i]=0;
	}
	gap[0]=dis[T]=0;
	while(Q.empty()==false){
		int x=Q.front();
		Q.pop();
		for(R i=Last[x];i!=0;i=Next[i]){
			int y=End[i];
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				Q.push(y);
			}
		}
	}
	for(R i=1;i<=n;i++){
		Ecur[i]=Last[i];
		gap[dis[i]]++;
	}
}
I int ISAP(int u,int flow,const int S,const int T,const int n){
	if(u==T){
		return flow;
	}
	int f,tem=0,v;
	for(R&i=Ecur[u];i!=0;i=Next[i]){
		v=End[i];
		if(Cap[i]!=0&&dis[v]==dis[u]-1){
			f=ISAP(v,Min(Cap[i],flow-tem),S,T,n);
			Cap[i]-=f;
			Cap[i^1]+=f;
			tem+=f;
			if(flow==tem||dis[S]==n){
				return tem;
			}
		}
	}
	gap[dis[u]]--;
	if(gap[dis[u]]==0){
		dis[S]=n;
	}
	dis[u]++;
	gap[dis[u]]++;
	Ecur[u]=Last[u];
	return tem;
}
I int MaxFlow(int S,int T,const int n){
	BFS(T,n);
	int res=0;
	while(dis[S]<n){
		res+=ISAP(S,INF,S,T,n);
	}
	return res;
}
I void Solve(){
	ct=1;
	int n,S,T;
	cin>>n;
	S=n<<2|1;
	T=S^3;
	for(R i=0;i!=n;i++){
		cin>>a[i];
		id[a[i]]=i;
		Link(S,i<<2|1,1);
		Link(i<<2|2,i<<2|3,1);
		Link(i+1<<2,T,1);
	}
	for(R i=0;i!=n;i++){
		for(int T:D[a[i]]){
			if(id[T]!=-1){
				Link(i<<2|1,id[T]<<2|2,INF);
				Link(i<<2|3,id[T]+1<<2,INF);
			}
		}
	}
	for(R i=0;i!=n;i++){
		id[a[i]]=-1;
	}
	printf("%d\n",MaxFlow(S,T,T));
	for(R i=1;i<=T;i++){
		Last[i]=0;
	}
}
int main(){
	for(int i=1;i!=N;i++){
		id[i]=-1;
		for(R j=i<<1;j<N;j+=i){
			D[j].push_back(i);
		}
	}
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}