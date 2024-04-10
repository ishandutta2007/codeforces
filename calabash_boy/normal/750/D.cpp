#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[400][400][8][32], m[400][400];
int d[8][2]={-1,1 ,0,1 ,1,1 ,1,0 ,1,-1, 0,-1, -1,-1, -1,0};
int n, t[32],ans;

void dfs(int x,int y, int dir,int j){
	if (vis[x][y][dir][j]) return;
	if (j>n) return;
	vis[x][y][dir][j]=1;
	for(int i=0;i<t[j];i++){
		x += d[dir][0];
		y += d[dir][1];
		if (!m[x][y]) m[x][y]=1,ans++;
		}
	dfs(x,y,(dir+7)%8,j+1);
	dfs(x,y,(dir+1)%8,j+1);
	}
	

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>t[i];
	dfs(160,160,3,0);
	cout<<ans;
	}