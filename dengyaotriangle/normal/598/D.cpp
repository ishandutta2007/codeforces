#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};

int n,m;
bool ok[maxn][maxn];
int vis[maxn][maxn];
int cp;
int cnt[maxn*maxn];

void dfs(int x,int y){
	vis[x][y]=cp;
	for(int i=0;i<4;i++){
		int cx=dx[i]+x,cy=dy[i]+y;
		if(ok[cx][cy]){
			cnt[cp]++;
		}else if(vis[cx][cy]!=cp){
			dfs(cx,cy);
		}
	}		
} 
int main(){
	int q;
	ios::sync_with_stdio(0);	
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		char _[maxn];
		cin>>(_+1);
		for(int j=1;j<=m;j++)ok[i][j]=(_[j]=='*');
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cp++;
			if(!ok[i][j]&&!vis[i][j])dfs(i,j);
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<cnt[vis[x][y]]<<'\n';	 
	}
	return 0;
}