/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define y1 weogoafjowejfweajgop
#define pb push_back
#define X first
#define Y second
#define mp make_pair
const int N=1000,M=1000,S=40;
int n,m,s,qu; 
int a[N+1][M+1];
vector<pair<int,int> > pos[S+1];
pair<int,int> q[N*M];
int head,tail;
bool vis[S+1];
int dep[N+1][M+1];
int dis[N+1][M+1][S+1];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool valid(int x,int y){return 1<=x&&x<=n&&1<=y&&y<=m;}
void bfs(int x){
	head=tail=0;
	memset(vis,0,sizeof(vis));
	vis[x]=true;
	memset(dep,-1,sizeof(dep));
	for(int i=0;i<pos[x].size();i++)q[tail++]=pos[x][i],dep[pos[x][i].X][pos[x][i].Y]=0;
	while(head<tail){
		int y=q[head].X,z=q[head].Y;
//		printf("%d %d\n",y,z);
		head++;
		for(int i=0;i<4;i++){
			int y0=y+dx[i],z0=z+dy[i];
			if(valid(y0,z0)&&!~dep[y0][z0])q[tail++]=mp(y0,z0),dep[y0][z0]=dep[y][z]+1;
		}
		if(!vis[a[y][z]]){
			int col=a[y][z];
			vis[col]=true;
			for(int i=0;i<pos[col].size();i++)
				if(!~dep[pos[col][i].X][pos[col][i].Y])
					q[tail++]=pos[col][i],dep[pos[col][i].X][pos[col][i].Y]=dep[y][z]+1;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dis[i][j][x]=dep[i][j]/*,printf("dis[%d][%d][%d]=%d\n",i,j,x,dep[i][j])*/;
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		int x;
		cin>>x;
		a[i][j]=x;
		pos[x].pb(mp(i,j));
	}
	for(int i=1;i<=s;i++)bfs(i);
	cin>>qu;
	while(qu--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=abs(x1-x2)+abs(y1-y2);
		for(int i=1;i<=s;i++)ans=min(ans,dis[x1][y1][i]+1+dis[x2][y2][i]);
		printf("%d\n",ans);
	}
	return 0;
}
/*1
3 4 5
1 2 1 3
4 4 5 5
1 2 1 3
2
1 1 3 4
2 2 2 2
*/
/*2
4 4 8
1 2 2 8
1 3 4 7
5 1 7 6
2 3 8 8
4
1 1 2 2
1 1 3 4
1 1 2 4
1 1 4 4
*/