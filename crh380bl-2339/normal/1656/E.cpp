#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
vector<int>e[N];
int d[N],flg[N];
void DFS(int x,int f){
	int i,y;
	for(i=0;i<e[x].size();++i){
		y=e[x][i];
		if(y!=f){
			flg[y]=-flg[x];
			DFS(y,x);
		}
	}
}
int main(){
	int T,n,i,j,k,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			d[i]=0;
			e[i].clear();
		}
		for(i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			++d[x];++d[y];
			e[x].push_back(y);
			e[y].push_back(x);
		}
		flg[1]=1;
		DFS(1,0);
		for(i=1;i<=n;++i)printf("%d ",flg[i]*d[i]);puts("");
	}
	return 0;
}