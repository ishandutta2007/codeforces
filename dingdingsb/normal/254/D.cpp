#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=150;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m,d;char mp[N][N];
int id[N][N],cnt,xx[2*M*M],yy[2*M*M];
bitset<2*M>flag[2*M*M];bool vis[N][N];
void add(int x,int y,int id){
	int&a=::id[x][y];
	if(!a)a=++cnt,xx[a]=x,yy[a]=y;
	flag[a].set(id,1);
}
#define In(a,b) (1<=(a)&&(a)<=n&&1<=(b)&&(b)<=m)
void bfs(int x,int y,int id){
	queue<tuple<int,int,int>>q;q.push({x,y,0});
	while(q.size()){
		auto [x,y,dp]=q.front();q.pop();
		add(x,y,id);if(dp==d)continue;++dp;
		for(int i=0;i<4;i++)if(In(x+dx[i],y+dy[i])&&mp[x+dx[i]][y+dy[i]]!='X')
			q.push({x+dx[i],y+dy[i],dp});
	}
}
signed main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int rats=0;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++)
			rats+=mp[i][j]=='R';
	}
	if(rats>290)return puts("-1"),0;
	rats=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='R')bfs(i,j,++rats);
	for(int i=1;i<=cnt;i++)
		if(flag[i].count()==rats){
			for(int x=1;x<=n;x++)
				for(int y=1;y<=m;y++)
					if((x!=xx[i]||y!=yy[i])&&mp[x][y]!='X')
						return printf("%d %d %d %d\n",xx[i],yy[i],x,y),0;
			return puts("-1"),0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='R'){
				queue<tuple<int,int,int>>q;q.push({i,j,0});
				while(q.size()){
					auto [x,y,dp]=q.front();q.pop();
					vis[x][y]=1;
					for(int k=1;k<=cnt;k++)
						if((flag[id[x][y]]|flag[k]).count()==rats)
							return printf("%d %d %d %d\n",x,y,xx[k],yy[k]),0;
					if(dp==d)continue;++dp;
					for(int i=0;i<4;i++)if(In(x+dx[i],y+dy[i])&&mp[x+dx[i]][y+dy[i]]!='X'&&!vis[x+dx[i]][y+dy[i]])
						q.push({x+dx[i],y+dy[i],dp});
				}
				return puts("-1"),0;
			}
}