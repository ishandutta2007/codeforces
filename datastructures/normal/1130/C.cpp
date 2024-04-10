#include <iostream>
#include <cstdio>
using namespace std;
int n,xa,ya,xb,yb;
int book1[105][105],book2[105][105];
int ans=2e9;
char s[105][105];
inline void dfs1(int x,int y){
	if (x<1||x>n||y<1||y>n)return;
	if (book1[x][y]==1||s[x][y]=='1')return;
	book1[x][y]=1; 
	dfs1(x-1,y);
	dfs1(x,y-1);
	dfs1(x+1,y);
	dfs1(x,y+1);
	return;
}
inline void dfs2(int x,int y){
	if (x<1||x>n||y<1||y>n)return;
	if (book2[x][y]==1||s[x][y]=='1')return;
	book2[x][y]=1;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			if (book1[i][j]==1)
				ans=min(ans,(x-i)*(x-i)+(y-j)*(y-j)); 
	dfs2(x,y-1);
	dfs2(x-1,y);
	dfs2(x,y+1);
	dfs2(x+1,y);
	return;
} 
int main(){
	cin>>n>>xa>>ya>>xb>>yb;
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	dfs1(xa,ya);
	dfs2(xb,yb);
	cout<<ans<<endl;
	return 0;
}