#include<bits/stdc++.h>
using namespace std;
int t,n,m,C;
int tot,id[20004][12][2];
vector<int>g[440005];
void adde(int u,int v){g[u].push_back(v);}
int cmp[440005],vis[440005],low[440005],T,cnt;
bool ins[440005];stack<int>sta;
void tarjan(int x){
	vis[x]=low[x]=++cnt;
	sta.push(x),ins[x]=1; 
	for(auto y:g[x]){
		if(!vis[y])tarjan(y);
		if(ins[y])low[x]=min(low[x],low[y]);
	}
	if(vis[x]==low[x]){
		T++;
		while(sta.top()!=x)cmp[sta.top()]=T,ins[sta.top()]=0,sta.pop();
		sta.pop(),cmp[x]=T,ins[x]=0;
	}
}
void sol(){
	scanf("%d%d%d",&n,&m,&C),tot=0;
	for(int i=1;i<=n;i++)for(int j=0;j<=C;j++)
		for(int k=0;k<2;k++)id[i][j][k]=++tot;
	for(int i=1;i<=tot;i++)g[i].clear(),cmp[i]=vis[i]=low[i]=ins[i]=0;
	for(int i=1;i<=n;i++){
		adde(id[i][C][1],id[i][C][0]);
		adde(id[i][0][0],id[i][0][1]);
		for(int j=1;j<=C;j++){
			adde(id[i][j-1][0],id[i][j][0]);
			adde(id[i][j][1],id[i][j-1][1]);
		}
		if(i>1){
			for(int j=0;j<=C;j++){
				adde(id[i][j][0],id[i-1][j][0]);
				adde(id[i-1][j][1],id[i][j][1]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		int op,x,y,w;scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&w);
			adde(id[x][w][0],id[x][w-1][0]);
			adde(id[x][w-1][1],id[x][w][1]);
		}
		if(op==2){
			scanf("%d%d%d",&x,&y,&w);
			for(int i=0;i<=C;i++){
				if(i+2>w){
					adde(id[x][i][1],id[x][i][0]);
					adde(id[y][i][1],id[y][i][0]);
				}else{
					int mx=w-i-1;if(mx>C)continue;
					adde(id[x][i][1],id[y][mx][0]);
					adde(id[y][i][1],id[x][mx][0]);
				}
			}
		}
		if(op==3){
			scanf("%d%d%d",&x,&y,&w);
			for(int i=0;i<=C;i++){
				if(i+C<w){
					adde(id[x][i][0],id[x][i][1]);
					adde(id[y][i][0],id[y][i][1]);
				}else{
					int mn=w-i;if(mn<1)continue;
					adde(id[x][i][0],id[y][mn-1][1]);
					adde(id[y][i][0],id[x][mn-1][1]);
				}
			}
		}
	}
	T=cnt=0;for(int i=1;i<=tot;i++)if(!vis[i])tarjan(i);
	for(int i=1;i<=n;i++)for(int j=0;j<=C;j++)
		if(cmp[id[i][j][0]]==cmp[id[i][j][1]]){puts("-1");return;}
	for(int i=1;i<=n;i++){
		int x=C,tmp;
		for(int j=C;j;j--)if(cmp[id[i][j][0]]<cmp[id[i][j][1]])tmp=j;
		printf("%d ",tmp);
	}
	puts("");
}
int main(){
	for(scanf("%d",&t);t--;sol());
}