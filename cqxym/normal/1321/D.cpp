#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define R register int
#define N 200001
vector<int>G[N],H[N];
bool vis[N];
int c[N],dis[N];
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		H[y].push_back(x);
	}
	int p;
	scanf("%d",&p);
	for(R i=0;i!=p;i++){
		scanf("%d",c+i);
	}
	queue<int>Q;
	vis[c[p-1]]=true;
	Q.push(c[p-1]);
	while(Q.empty()==false){
		int t=Q.front();
		Q.pop();
		int l=H[t].size();
		for(R i=0;i!=l;i++){
			if(vis[H[t][i]]==false){
				vis[H[t][i]]=true;
				dis[H[t][i]]=dis[t]+1;
				Q.push(H[t][i]);
			}
		}
	}
	int ans1=0,ans2=0;
	for(R i=1;i!=p;i++){
		x=c[i-1];
		y=c[i];
		if(dis[x]<dis[y]+1){
			ans1++;
			ans2++;
		}else{
			int l=G[x].size();
			for(R j=0;j!=l;j++){
				if(dis[x]==dis[G[x][j]]+1&&G[x][j]!=y){
					ans2++;
					break;
				}
			}
		}
	}
	printf("%d %d",ans1,ans2);
	return 0;
}