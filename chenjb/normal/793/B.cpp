#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#define LL long long 
using namespace std;
struct node
{
	int x,y,way,turn;
}q[9000000];
int n,m,sx,sy,dx,dy;
string s[1001];
int v[1001][1001][5];
int bfs()
{
	int head=0;
	int tail=4;
	q[1]=(node){sx,sy,1,0};
	q[2]=(node){sx,sy,2,0};
	q[3]=(node){sx,sy,3,0};
	q[4]=(node){sx,sy,4,0};
	v[sx][sy][1]=v[sx][sy][2]=v[sx][sy][3]=v[sx][sy][4]=1;
	while(head<tail)
	{
		node x=q[++head];
		for(int i=1;i<=5;i++)
		{
			node t=x;
			if (i==1)t.way=1;
			if (i==2)t.way=2;
			if (i==3)t.way=3;
			if (i==4)t.way=4;
			if (i==5)
			{
				if (t.way==1)t.x++;
				if (t.way==2)t.x--;
				if (t.way==3)t.y++;
				if (t.way==4)t.y--;
			}
			if (t.x<0||t.y<0||t.x>=n||t.y>=m)continue;
			if (s[t.x][t.y]=='*')continue;
			if (t.way!=x.way&&x.way!=-1)t.turn++;
			if (t.turn>2)continue;
			if (v[t.x][t.y][t.way])continue;
			v[t.x][t.y][t.way]=1;
			if (t.x==dx&&t.y==dy)return 1;
			q[++tail]=t;
		}
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
		{
			getline(cin,s[i]);
			//cout<<s[i]<<endl;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			v[i][j][1]=v[i][j][2]=v[i][j][3]=v[i][j][4]=0;
			if (s[i][j]=='S')sx=i,sy=j;
			else if (s[i][j]=='T')dx=i,dy=j;
		}
	if (bfs())cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}