#include <bits/stdc++.h>
using namespace std;
const int M=320;
int dir[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
int n,q,vis[2][100003];
bool isl[2][100003];
void bfs(int l,int r){
	for (int i=l;i<=r;i++) vis[0][i]=vis[1][i]=0;
	queue <int>qu,qv;
	if (!isl[0][r]){
		qu.push(0),qv.push(r);
		vis[0][r]=1;
	}
	if (!isl[1][r]){
		qu.push(1),qv.push(r);
		vis[1][r]=1;
	}
	while (!qu.empty()){
		int u=qu.front(),v=qv.front();qu.pop(),qv.pop();
		for (int i=0;i<4;i++){
			int uu=u+dir[i][0],vv=v+dir[i][1];
			if (uu>1 || vv<l || uu<0 || vv>r || vis[uu][vv] || isl[uu][vv]) continue;
			vis[uu][vv]=1;
			qu.push(uu),qv.push(vv); 
		}
	}
}
bool ok(){
	if (!vis[0][0]) return 0;
	for (int i=1;i<=n/M;i++){
		bool okt=1;
		for (int j=0;j<2;j++) if ((!isl[j][i*M-1]) && vis[j][i*M]){
			okt=0;break;
		}
		if (okt)return 0;
	}
	return 1;
}
int main(){
	cin>>n>>q;
	memset (vis,1,sizeof(vis));
	while (q--){
		int x,y;cin>>x>>y;x--,y--;
		isl[x][y]^=1;
		bfs(y/M*M,min(n,y/M*M+M-1));
		if (ok()) puts("Yes");
		else puts("No");
	}
}