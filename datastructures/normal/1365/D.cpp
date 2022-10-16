#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,book[55][55];
char s[55][55];
inline void dfs(int x,int y){
	if (x<1||x>n||y<1||y>m||s[x][y]=='#'||book[x][y]==1)return;
	book[x][y]=1;
	dfs(x,y-1);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x+1,y);
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=0;i<=51;i++)
			for (int j=0;j<=51;j++)
				s[i][j]='$';
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				char ch;
				cin>>ch;
				s[i][j]=ch;
			}
		memset(book,0,sizeof(book));
		int fg=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (s[i][j]=='B'){
					if (s[i-1][j]=='G'||s[i][j-1]=='G'||s[i+1][j]=='G'||s[i][j+1]=='G')fg=0;
					else{
						if (s[i-1][j]!='B')s[i-1][j]='#';
						if (s[i+1][j]!='B')s[i+1][j]='#';
						if (s[i][j-1]!='B')s[i][j-1]='#';
						if (s[i][j+1]!='B')s[i][j+1]='#';
					}
				}
		if (fg==0){
			puts("No");
			continue;
		}
		dfs(n,m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (s[i][j]=='G'&&book[i][j]==0)fg=0;
		if (fg==0)puts("No");
		else puts("Yes");
	}
	return 0;
}