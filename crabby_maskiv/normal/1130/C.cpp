#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
	inline void read(T &x,Args &...args){
	read(x);read(args...);
}
int n,m;
bool maze[55][55],vis[55][55];
int col[55][55];
int dis[255][255];
int k[255][255];
int sx,sy,tx,ty,sc,tc;
int f(int x){
	if(x<0) return -x;
	return x;
}
int dist(int x1,int y1,int x2,int y2){
	return f(x1-x2)+f(y1-y2);
}
int cost(int x1,int y1,int x2,int y2){
	return f(x1-x2)*f(x1-x2)+f(y1-y2)*f(y1-y2);
}
void bfs(int x,int y,int c){
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	col[x][y]=c;vis[x][y]=1;
	while(!q.empty()){
		pair<int,int> cur=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int tx=cur.first+dx[i],ty=cur.second+dy[i];
			if(tx<1||tx>n||ty<1||ty>n) continue;
			if(vis[tx][ty]||maze[tx][ty]) continue;
			col[tx][ty]=c;vis[tx][ty]=1;
			q.push(make_pair(tx,ty));
		}
	}
	return;
}
int route(int c1,int c2){
	int i1,i2,i3,i4;
	int ans=inf;
	for(i1=1;i1<=n;i1++){
		for(i2=1;i2<=n;i2++){
			if(col[i1][i2]!=c1) continue;
			for(i3=1;i3<=n;i3++){
				for(i4=1;i4<=n;i4++){
					if(col[i3][i4]!=c2) continue;
					int tmp=cost(i1,i2,i3,i4);
					ans=min(ans,tmp);
				}
			}
		}
	}
	return ans;
}
int main()
{
	int i,j;
	read(n);
	read(sx,sy,tx,ty);
	for(i=1;i<=n;i++){
		string tmp;
		cin>>tmp;
		for(j=0;j<n;j++){
			maze[i][j+1]=tmp[j]-'0';
		}
	}
	int cnt=0;
	cnt=1;
	cnt=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(!vis[i][j]&&!maze[i][j]) bfs(i,j,++cnt);
			//cout<<col[i][j];
		}
		//cout<<endl;
	}
	sc=col[sx][sy];tc=col[tx][ty];
	cout<<route(sc,tc);
	return 0;
}