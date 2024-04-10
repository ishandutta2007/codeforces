#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int> > con;
string gra[1000];
int n,m,her[1000][1000],see[1000][1000];
const int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool mar[1000][1000];
void dfs(int x,int y)
{
	con.push_back(make_pair(x,y));
	mar[x][y]=true;
	for(int i=0;i<4;i++)
		if(x+dir[i][0]>=0&&x+dir[i][0]<n&&y+dir[i][1]>=0&&y+dir[i][1]<m)
			if(gra[x+dir[i][0]][y+dir[i][1]]=='.'&&!mar[x+dir[i][0]][y+
			dir[i][1]])
				dfs(x+dir[i][0],y+dir[i][1]);
}
int main()
{
	vector<int> ans;
	int tim,i,j,k;
	cin>>n>>m>>tim;
	for(i=0;i<n;i++)
		cin>>gra[i];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(gra[i][j]=='.')
				for(k=0;k<4;k++)
					if(i+dir[k][0]>=0&&i+dir[k][0]<n&&j+dir[k][1]>=0&&j+
					dir[k][1]<m)
						if(gra[i+dir[k][0]][j+dir[k][1]]=='*')
							her[i][j]++;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(!mar[i][j]&&gra[i][j]=='.')
			{
				con.clear();
				dfs(i,j);
				int sum=0;
				for(k=0;k<con.size();k++)
					sum+=her[con[k].first][con[k].second];
				for(k=0;k<con.size();k++)
					see[con[k].first][con[k].second]=sum;
			}
	for(i=1;i<=tim;i++)
	{
		int x,y;
		cin>>x>>y;
		ans.push_back(see[x-1][y-1]);
	}
	for(i=0;i<tim;i++)
		cout<<ans[i]<<"\n";
	return 0;
}
/*1
5 6 3
******
*..*.*
******
*....*
******
2 2
2 5
4 3
*/
/*2
4 4 1
****
*..*
*.**
****
3 2
*/