#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 300001
int f[N];
I int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
vector<int>G[N];
bool vis[N],chose[N];
I void DFS(int x,vector<int>&A){
	vis[x]=true;
	bool tag=false;
	for(int T:G[x]){
		tag=tag||chose[T];
	}
	if(tag==false){
		chose[x]=true;
		A.push_back(x);
	}
	for(int T:G[x]){
		if(vis[T]==false){
			DFS(T,A);
		}
	}
}
I void Solve(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		f[i]=i;
		vector<int>().swap(G[i]);
		chose[i]=vis[i]=false;
	}
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		if(GetF(x)!=GetF(y)){
			f[f[x]]=y;
		}
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(R i=2;i<=n;i++){
		if(GetF(i)!=GetF(1)){
			puts("NO");
			return;
		}
	}
	puts("YES");
	vector<int>A;
	DFS(1,A);
	printf("%d\n",A.size());
	for(int T:A){
		printf("%d ",T);
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}