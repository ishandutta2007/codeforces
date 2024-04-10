#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int first[maxn],des[maxn*2],nxt[maxn*2],tot;
int n,m;
int ans;
bool vis[maxn];
int flag[maxn];
bool ok[maxn];
int cntE[maxn],cntV[maxn],bcc_cnt;
int d[maxn];
inline void addEdge(int x,int y){
	tot++;
	des[tot] = y;
	nxt[tot] = first[x];
	first[x] = tot;
	d[y]++;
}
void dfs(int u){
	vis[u] = true;
	flag[u] = bcc_cnt;
	for (int t = first[u];t;t=nxt[t]){
		int v =des[t];
		if (vis[v])continue;
		dfs(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			bcc_cnt++;
			dfs(i);
		}
	}
	for (int i=1;i<=n;i++){
		if (d[i]!=2)ok[flag[i]]=true;
		cntV[flag[i]]++;
		for (int t = first[i];t;t=nxt[t]){
			int v =des[t];
			cntE[flag[i]]++;
		}
	}
	int ans =0;
	for (int i=1;i<=bcc_cnt;i++){
		ans += !ok[i]&&cntE[i]==2*cntV[i];
	}
	cout<<ans<<endl;
	return 0;
}