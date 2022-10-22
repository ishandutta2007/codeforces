#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll mod=1000000007ll;
int n,m;
int cnt;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char a[N][N];
bool vis[N][N],vis2[N][N];
void bfs1(int x,int y){
	queue<pair<int,int> > q;
	q.push({x,y});
	while(!q.empty()){
		pair<int,int> p=q.front();q.pop();
		int cx=p.first,cy=p.second;
		for(int i=0;i<4;i++){
			int tx=cx+dx[i],ty=cy+dy[i];
			if(tx<1||tx>n||ty<1||ty>m||vis[tx][ty]) continue;
			if(a[tx][ty]=='*'){
				cnt++;
				continue;
			}
			vis[tx][ty]=1;
			q.push({tx,ty});
		}
	}
}
int ans[N][N];
void bfs2(int x,int y){
	queue<pair<int,int> > q;
	q.push({x,y});
	while(!q.empty()){
		pair<int,int> p=q.front();q.pop();
		int cx=p.first,cy=p.second;
		ans[cx][cy]=cnt;
		for(int i=0;i<4;i++){
			int tx=cx+dx[i],ty=cy+dy[i];
			if(tx<1||tx>n||ty<1||ty>m||vis2[tx][ty]) continue;
			if(a[tx][ty]=='*') continue;
			vis2[tx][ty]=1;
			q.push({tx,ty});
		}
	}
}
int main() {
	int i,j;
	int T;
	cin>>n>>m>>T;
	for(i=1;i<=n;i++){
		cin>>(a[i]+1);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!vis[i][j]&&a[i][j]!='*'){
				vis[i][j]=1;
				cnt=0;
				bfs1(i,j);
				bfs2(i,j);
			}
		}
	}
	while(T--){
		int x,y;cin>>x>>y;
		cout<<ans[x][y]<<endl;
	}
    return 0;
}