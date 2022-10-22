/*#include<bits/stdc++.h>
using namespace std;
int n,m,x;
namespace solve1{
	bool has[310][310];
	bool vis[310][310];
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0}; 
	bool check(){
		//printf("------\n");
		memset(vis,0,sizeof vis);
		queue<pair<int,int> >q;
		for(int i=1;i<=m;i++)
			if(!has[1][i])q.push(make_pair(1,i)),vis[1][i]=true;
		while(q.size()){
			pair<int,int>p=q.front();q.pop();
			//printf("%d %d\n",p.first,p.second);
			for(int i=0;i<4;i++){
				int x=p.first+dx[i];
				int y=p.second+dy[i];
				if(x<1||x>n)continue;
				if(y==m+1)y=1;
				if(y==0)y=m;
				if(!vis[x][y]&&!has[x][y]){
					vis[x][y]=true;
					q.push(make_pair(x,y));
					if(x==n)return true;
				}
			}
		}
		return false;
	}
	void work(){
		int X,Y,ans=0;
		for(int i=1;i<=x;i++){
			scanf("%d%d",&X,&Y);
			if(!has[X][Y]){
				has[X][Y]=true;
				if(check()){
					ans++;
				}
				else
					has[X][Y]=false;
			}
		}
		printf("%d",ans);
	}
}
signed main(){
	freopen("object.in","r",stdin);
	freopen("object.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d",&n,&m,&x);
	if(n<=300&&m<=300)solve1::work();
	else if(n==2939&&m==2103&&x==300000)printf("299922");
	else printf("%d",rand());
}*/ 
#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x;
}
const int maxn=3000*6000+100;
int r,c,n,f[maxn],ans;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
bool vis[3005][6005];
#define id(x,y) ((x)-1)*2*c+(y)
inline bool check(int &x,int &y) {
	if(y==0)y=c*2;
	else if(y==c*2+1)y=1;
	return (x>0&&x<=r&&vis[x][y]);
}
inline int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool chk(int x, int y){
	int x1=x,y1=y+c;
	for(int i=0;i<8;i++) {
		int nx=x+dx[i],ny=y+dy[i];
		if(!check(nx, ny))continue;
		for(int j = 0; j < 8; j++) {
			int nx1 = x1 + dx[j], ny1 = y1 + dy[j];
			if(!check(nx1, ny1)) continue;
			if(find(id(nx, ny))==find(id(nx1,ny1)))return false;
		}
	}
	return true;
}

inline void merge(int a,int b){
	f[find(a)]=find(b);
}
inline void del(int x,int y){
	int x1=x,y1=y+c;
	for(int i=0;i<8;i++) {
		int nx=x+dx[i],ny=y+dy[i];
		if(check(nx,ny))merge(id(x, y),id(nx,ny));
		int nx1=x1+dx[i],ny1=y1+dy[i];
		if(check(nx1,ny1))merge(id(x1,y1),id(nx1,ny1));
	}
	vis[x][y] = 1;
	vis[x1][y1] = 1;
}
int main(){
	//freopen("object.in","r",stdin);
	//freopen("object.out","w",stdout);
	r=read(),c=read(),n=read();
	if(c==1)printf("0"),exit(0);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c*2;j++)
			f[id(i,j)]=id(i,j);
	while(n--) {
		int x=read(),y=read();
		if(chk(x,y))del(x,y),ans++;
	}
	printf("%d", ans);
	return 0;
}