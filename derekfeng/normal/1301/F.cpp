#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int dist[1000045],dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int n,m,K,a[1003][1003],num[44][1003][1003];
bool vis[1000045];
vector<int>g[2][1000045];
void DQ(int s){
	queue <int> q1,q2;
	memset (vis,0,sizeof(vis));
	for (int i=0;i<1000045;i++) dist[i]=1e7;
	q1.push(s),dist[s]=0; 
	while (!q1.empty() || !q2.empty()){
		int x;
		if (!q1.empty()) x=q1.front(),q1.pop();
		else x=q2.front(),q2.pop();
		if (vis[x]) continue;vis[x]=1;
		for (int i=0;i<g[0][x].size();i++) if (dist[g[0][x][i]]>dist[x]) q1.push(g[0][x][i]),dist[g[0][x][i]]=dist[x];
		for (int i=0;i<g[1][x].size();i++) if (dist[g[1][x][i]]>dist[x]+1) q2.push(g[1][x][i]),dist[g[1][x][i]]=dist[x]+1;
	}
	for (int i=1;i<=n;i++)for (int j=1;j<=m;j++) num[s][i][j]=dist[K+(i-1)*m+j];
}
int main(){
	read(n),read(m),read(K);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			read(a[i][j]);
			g[1][K+(i-1)*m+j].push_back(a[i][j]),g[0][a[i][j]].push_back(K+(i-1)*m+j);
			for (int k=0;k<4;k++){
				int u=i+dir[k][0],v=j+dir[k][1];
				if (u<1 || v<1 || u>n || v>m) continue;
				g[1][K+(i-1)*m+j].push_back(K+(u-1)*m+v); 
			}
		}
	for (int i=1;i<=K;i++) DQ(i);
	int q;read(q);
	while (q--){
		int r1,c1,r2,c2;read(r1),read(c1),read(r2),read(c2);
		int ans=abs(r1-r2)+abs(c1-c2);
		for (int i=1;i<=K;i++) ans=min(ans,num[i][r1][c1]+num[i][r2][c2]+1); 
		write(ans),puts("");
	}
}