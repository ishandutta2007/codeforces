#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define mod 998244353
using namespace std;
int n,m,r,c,a,b;
char s[2005][2005];
int book[2005][2005],ans[2005][2005];
struct node{
	int x,y,a,b;
}q[10000005];
int head,tail;
inline bool check(int x,int y,int a,int b){
	if (x<1||x>n||y<1||y>m)return 0;
	if (book[x][y]==1||s[x][y]=='*')return 0;
	if (a<0||b<0)return 0;
	return 1;
}
inline void bfs(int x,int y,int a,int b){
	node c;
	if (!check(x,y,a,b))return;
	c.x=x,c.y=y,c.a=a,c.b=b;
	book[x][y]=ans[x][y]=1;
	q[head=tail]=c;
	while(head<=tail){
		c=q[head];
		head++;
		x=c.x,y=c.y,a=c.a,b=c.b;
		if (check(x-1,y,a,b)){
			c.x=x-1,c.y=y,c.a=a,c.b=b;
			book[c.x][c.y]=1,ans[c.x][c.y]=1;
			q[++tail]=c;
		}
		if (check(x+1,y,a,b)){
			c.x=x+1,c.y=y,c.a=a,c.b=b;
			book[c.x][c.y]=1,ans[c.x][c.y]=1;
			q[++tail]=c;
		}

		if (check(x,y+1,a,b-1)){
			c.x=x,c.y=y+1,c.a=a,c.b=b-1;
			book[c.x][c.y]=1,ans[c.x][c.y]=1;
			q[++tail]=c;
		}				
		if (check(x,y-1,a-1,b)){
			c.x=x,c.y=y-1,c.a=a-1,c.b=b;
			book[c.x][c.y]=1,ans[c.x][c.y]=1;
			q[++tail]=c;
		}
	}
	return;
}
int cnt;
inline void dfs(const int &x,const int &y,const int &a,const int &b){
	if (a<0||b<0||book[x][y]>=a||s[x][y]=='*'||x<1||x>n||y<1||y>m||cnt>2e6)return;
	cnt++;
	book[x][y]=a,ans[x][y]=1;
	dfs(x-1,y,a,b);
	dfs(x+1,y,a,b);
	dfs(x,y-1,a-1,b);
	dfs(x,y+1,a,b-1);
	return;
}
signed main(){
	cin>>n>>m>>r>>c>>a>>b;
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(book,-1,sizeof(book));
	bfs(r,c,a,b);
	memset(book,-1,sizeof(book));
	dfs(r,c,a,b);
	int ss=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)ss+=ans[i][j];
	cout<<ss<<endl;
	return 0;
}