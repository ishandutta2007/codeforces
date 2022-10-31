#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
#define R register int
set<int>G[1001];
vector<int>V;
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		G[x].insert(y);
		G[y].insert(x);
	}
	for(int i=1;i<=n;i++){
		if(G[i].size()==1){
			V.push_back(i);
		}
	}
	while(V.size()>1){
		int u,v,l=V.size();
		u=V[l-1];
		v=V[l-2];
		V.pop_back();
		V.pop_back();
		printf("? %d %d\n",u,v);
		fflush(stdout);
		int ans;
		scanf("%d",&ans);
		if(ans==u||ans==v){
			printf("! %d",ans);
			return 0;
		}
		x=*G[u].begin();
		y=*G[v].begin();
		G[x].erase(u);
		if(G[x].size()==1){
			V.push_back(x);
		}
		G[y].erase(v);
		if(G[y].size()==1){
			V.push_back(y);
		}
	}
	printf("! %d",V[0]);
	return 0;
}