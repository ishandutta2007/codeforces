#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int first[maxn];
int nxt[maxn*2];
int des[maxn*2];
int n;
int tot=0;
long long ans[3];
inline void addEdge(int x,int y){
	tot++;
	des[tot]=y;
	nxt[tot] = first[x];
	first[x] = tot;
}
void dfs(int node,int father,int flag){
	ans[flag]++;
	for (int t = first[node];t;t=nxt[t]){
		if (des[t]==father){
			continue;
		}
		dfs(des[t],node,flag^1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	dfs(1,0,0);
	cout<<max(0LL,ans[0]*ans[1]-n+1)<<endl;
	return 0;
}