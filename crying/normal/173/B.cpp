#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
using namespace std;
const int MAXN=1e3+10,INF=1e9,next_x[4]={0,-1,0,1},next_y[4]={-1,0,1,0},rev[4]={2,3,0,1}; // 
int n,m,matrix[MAXN][MAXN];
int vis[MAXN][MAXN][4],dis[MAXN][MAXN][4];
struct Node{
	int x,y,z;
};
deque<Node>q;
inline bool valid(int x,int y){
	return x>=0 && x<=n && y>=0 && y<=m;
}
void bfs(){
	rep(i,0,n)rep(j,0,m)dis[i][j][0]=dis[i][j][1]=dis[i][j][2]=dis[i][j][3]=INF;
	dis[n][m][2]=0;vis[n][m][2]=1;
	q.push_back((Node){n,m,2});
	while(!q.empty()){
		Node now=q.front();q.pop_front();
		int i=now.x,j=now.y,k=now.z;
		int x=i+next_x[rev[k]],y=j+next_y[rev[k]];
		if(valid(x,y) && !vis[x][y][k]){
			vis[x][y][k]=1;
			dis[x][y][k]=dis[i][j][k];
			q.push_front((Node){x,y,k});
		}
		if(matrix[i][j]){
			for(int idx=0;idx<4;idx++){
				int x=i+next_x[idx],y=j+next_y[idx];
				if(!valid(x,y))continue;
				if(vis[x][y][rev[idx]])continue;
				vis[x][y][rev[idx]]=1;
				dis[x][y][rev[idx]]=dis[i][j][k]+1;
				q.push_back((Node){x,y,rev[idx]});
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);char tmp;
	rep(i,1,n){
		rep(j,1,m){
			scanf(" %c",&tmp);matrix[i][j]=(tmp=='#');
		}
	} 
	bfs();
	if(dis[1][0][2]==INF){
		printf("-1");
	}else{
		printf("%d",dis[1][0][2]);
	}
	return 0;
}