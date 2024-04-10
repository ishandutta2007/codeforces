#include<bits/stdc++.h>
using namespace std;
char maze[510][510];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",maze[i]);
	int ans=0;
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(maze[i][j]=='X'&&maze[i][j]==maze[i-1][j-1]&&maze[i][j]==maze[i-1][j+1]&&maze[i][j]==maze[i+1][j+1]&&maze[i][j]==maze[i+1][j-1]) ans++;
		}
	}
	printf("%d\n",ans);
}