#include<iostream>
using namespace std;
#define ok(x,y) x>=0&&x<n&&y>=0&&y<m
int n,m,k;
string pic[500];
bool mar[500][500];
const int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y)
{
	mar[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(ok(nx,ny))
			if(pic[nx][ny]=='.'&&!mar[nx][ny])
				dfs(nx,ny);
	}
	if(k>0)
	{
		k--;
		pic[x][y]='X';
	}
}
int main()
{
	cin>>n>>m>>k;
	int i;
	for(i=0;i<n;i++)
		cin>>pic[i];
	for(i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(pic[i][j]=='.')
				dfs(i,j);
	for(i=0;i<n;i++)
		cout<<pic[i]<<"\n";
	return 0;
}
/*1
3 4 2
#..#
..#.
#...
*/
/*2
5 4 5
#...
#.#.
.#..
...#
.#.#
*/