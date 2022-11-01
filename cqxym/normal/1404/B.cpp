#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline void
vector<int>G[100001];
int dis[100001];
I PreDFS(int x,int F){
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		if(*T!=F){
			dis[*T]=dis[x]+1;
			PreDFS(*T,x);
		}
	}
}
I Solve(){
	int n,a,b,da,db,x,y;
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	for(R i=1;i<=n;i++){
		G[i].clear();
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dis[a]=0;
	PreDFS(a,0);
	if(dis[b]<=da){
		puts("Alice");
		return;
	}
	int maxid=0;
	for(R i=1;i<=n;i++){
		if(dis[i]>dis[maxid]){
			maxid=i;
		}
	}
	dis[maxid]=0;
	PreDFS(maxid,0);
	int maxdis=0;
	for(R i=1;i<=n;i++){
		if(dis[i]>maxdis){
			maxdis=dis[i];
		}
	}
	if(maxdis<=da<<1){
		puts("Alice");
		return;
	}
	if(da<<1<db){
		puts("Bob");
	}else{
		puts("Alice");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}