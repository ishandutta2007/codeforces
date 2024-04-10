#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int map[400][400];
bool flag[400][400][40][8];
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
vector<int>vec;
void dfs(int pt,int x,int y,int d)
{
	if(pt==vec.size())return;
	if(flag[x][y][pt][d])return;
	flag[x][y][pt][d]=true;
	for(int i=1;i<=vec[pt];i++)
	{
		map[x+dx[d]*i][y+dy[d]*i]=1;
	}
	dfs(pt+1,x+vec[pt]*dx[d],y+vec[pt]*dy[d],(d+1)%8);
	dfs(pt+1,x+vec[pt]*dx[d],y+vec[pt]*dy[d],(d+7)%8);
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int z;
		scanf("%d",&z);
		vec.push_back(z);
	}
	dfs(0,200,200,5);
	int c=0;
	for(int i=0;i<400;i++)for(int j=0;j<400;j++)c+=map[i][j];
	printf("%d\n",c);
}