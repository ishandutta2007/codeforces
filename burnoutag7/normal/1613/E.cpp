#include<bits/stdc++.h>
using namespace std;

int n,m;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
string g[1000005];

bool inside(int x,int y){
	return x>=0&&y>=0&&x<n&&y<m;
}

void bfs(int sx,int sy){
	queue<pair<int,int>> q;
	q.emplace(sx,sy);
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int d=0;d<4;d++){
			int nx=x+dx[d],ny=y+dy[d];
			if(inside(nx,ny)&&g[nx][ny]=='.'){
				int cnt=0;
				for(int nd=0;nd<4;nd++){
					int gx=nx+dx[nd],gy=ny+dy[nd];
					cnt+=inside(gx,gy)&&g[gx][gy]=='.';
				}
				if(cnt<=1){
					g[nx][ny]='+';
					q.emplace(nx,ny);
				}
			}
		}
	}
}

void mian(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>g[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]=='L'){
		bfs(i,j);
		break;
	}
	for(int i=0;i<n;i++)cout<<g[i]<<'\n';
}

int main(){

	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	int T;
	cin>>T;
	while(T--)mian();

}