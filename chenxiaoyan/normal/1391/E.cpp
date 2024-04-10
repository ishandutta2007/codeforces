/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=500000;
int n,m;
vector<int> nei[N+1];
bool vis[N+1];
int fa[N+1],dep[N+1];
void dfs(int x=1){// 
	vis[x]=true;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(vis[y])continue;
		fa[y]=x;dep[y]=dep[x]+1;
		dfs(y);
	}
}
vector<int> buc[N+1];
void mian(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)nei[i].clear(),buc[i].clear(),vis[i]=fa[i]=dep[i]=0;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].pb(y);nei[y].pb(x);
	}
	dep[1]=1;
	dfs();
	for(int i=1;i<=n;i++)
		if(dep[i]>=n+1>>1){// 
			puts("PATH");
			printf("%d\n",dep[i]);
			while(i)printf("%d ",i),i=fa[i];
			puts("");
			return;
		}
		else buc[dep[i]].pb(i);
	puts("PAIRING");// 
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=buc[i].size()>>1;// 
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++){// 
		for(int j=0;j+1<buc[i].size();j+=2)printf("%d %d\n",buc[i][j],buc[i][j+1]);// 
	}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}