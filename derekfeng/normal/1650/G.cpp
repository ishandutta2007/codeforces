#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,m,s,t;
int f[200004][2],lv[200004][2];
vector<int>g[200004];
void sol(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++)g[i].clear(),lv[i][0]=lv[i][1]=-1,f[i][0]=f[i][1]=0;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	f[s][0]=1,lv[s][0]=0;
	queue<int>qu,qv;qu.push(s),qv.push(0);
	while(!qu.empty()){
		int u=qu.front(),v=qv.front();qu.pop(),qv.pop();
		int w=f[u][v],d=lv[u][v];
		for(auto x:g[u]){
			if(lv[x][0]<0||lv[x][0]==d+1){
				if(lv[x][0]<0)qu.push(x),qv.push(0);
				lv[x][0]=d+1,(f[x][0]+=w)%=M;
			}else if(lv[x][0]==d){
				if(lv[x][1]<0)qu.push(x),qv.push(1);
				lv[x][1]=d+1,(f[x][1]+=w)%=M;
			}
		}
	}
	printf("%d\n",(f[t][0]+f[t][1])%M);
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}