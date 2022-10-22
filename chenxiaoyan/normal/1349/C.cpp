/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=1000;
int n,m,qu;
char a[N+1][M+5];
int in[N+1][M+1];
int cnt;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
bool vld(int x,int y){return 1<=x&&x<=n&&1<=y&&y<=m;}
int num[N*M+1];
void dfs(int x,int y){
	in[x][y]=cnt;num[cnt]++;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(vld(xx,yy)&&!in[xx][yy]&&a[x][y]==a[xx][yy])dfs(xx,yy);
	}
}
vector<int> nei[N*M+1];
int dep[N*M+1];
void bfs(){
	queue<int> q;
	for(int i=1;i<=cnt;i++)if(num[i]>1)q.push(i),dep[i]=1;
	while(q.size()){
		int x=q.front();
//		cout<<x<<"!\n";
		q.pop();
		for(int i=0;i<nei[x].size();i++){
			int y=nei[x][i];
			if(!dep[y])q.push(y),dep[y]=dep[x]+1;
		}
	}
}
int main(){
	cin>>n>>m>>qu;
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!in[i][j])cnt++,dfs(i,j);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(i+1<=n&&in[i][j]!=in[i+1][j])nei[in[i][j]].push_back(in[i+1][j]),nei[in[i+1][j]].push_back(in[i][j]);
		if(j+1<=m&&in[i][j]!=in[i][j+1])nei[in[i][j]].push_back(in[i][j+1]),nei[in[i][j+1]].push_back(in[i][j]);
	}
	bfs();
//	for(int i=1;i<=cnt;i++)cout<<dep[i]<<"\n";
	while(qu--){
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(!dep[in[x][y]])putchar(a[x][y]);
		else if(dep[in[x][y]]-1<=z)putchar((a[x][y]^48^((dep[in[x][y]]^z^1)&1))^48);
		else putchar(a[x][y]);
		putchar('\n');
	}
	return 0;
}