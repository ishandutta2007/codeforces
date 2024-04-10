#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
struct node
{
	int x,y;
	int p,prenum;
}q[30000];
using namespace std;
char g[110][110];
int n,m,dx,dy,inv1,inv2;
int v[110][110];
char way[5];
int ans[20000];

void bfs()
{
	int head=0;
	int tail=1;
	q[1].x=1;
	q[1].y=1;
	memset(v,0,sizeof(v));
	v[1][1]=1;
	int tx,ty;
	while (head<tail)
	{
		node x=q[++head];
		for(int i=1;i<=4;i++)
		{
			node y=x;
			if (i==1)y.x--;
			if (i==2)y.y++;
			if (i==3)y.x++;
			if (i==4)y.y--;
			if (y.x<1||y.y<1||y.x>n||y.y>m||g[y.x][y.y]=='*'||v[y.x][y.y])continue;
			v[y.x][y.y]=1;
			y.p=i;
			y.prenum=head;
			if (y.x==dx&&y.y==dy)
			{
				int tot=0;
				while (y.x!=1||y.y!=1)
				{
					ans[++tot]=y.p;
					y=q[y.prenum];
				}
				for(int i=tot;i>=1;i--)
				{
					cout<<way[ans[i]]<<endl;
					fflush(stdout);
					cin>>tx>>ty;
				}
				return;
			}
			q[++tail]=y;
		}
	}
}
void getright()
{
	inv1=inv2=0;
	int x,y,pre;
	if (n>1&&g[2][1]!='*')
	{
		cout<<way[1]<<endl;
		fflush(stdout);
		cin>>x>>y;
		if (x==2)
		{
			if (x==dx&&y==dy)exit(0);
			swap(way[1],way[3]);
			cout<<way[1]<<endl;
			fflush(stdout);
			cin>>x>>y;
		}
		x=1; y=1;
		while (n>1&&g[x][y+1]=='*')
		{
			cout<<way[3]<<endl;
			fflush(stdout);
			cin>>x>>y;
			if (x==dx&&y==dy)exit(0);
		}
		cout<<way[4]<<endl;
		fflush(stdout);
		pre=y;
		cin>>x>>y;
		if (y==pre+1)
		{
			if (x==dx&&y==dy)exit(0);
			swap(way[2],way[4]);
			inv2=1;
			cout<<way[4]<<endl;
			fflush(stdout);
			cin>>x>>y;
		}
		while (x!=1||y!=1)
		{
			cout<<way[1]<<endl;
			fflush(stdout);
			cin>>x>>y;
		}
	}
	else
	if (m>1&&g[1][2]!='*')
	{
		cout<<way[4]<<endl;
		fflush(stdout);
		cin>>x>>y;
		if (y==2)
		{
			if (x==dx&&y==dy)exit(0);
			swap(way[2],way[4]);
			inv2=1;
			cout<<way[4]<<endl;
			fflush(stdout);
			cin>>x>>y;
		}

		x=1; y=1;
		while (n>1&&g[x+1][y]=='*')
		{
			cout<<way[2]<<endl;
			fflush(stdout);
			cin>>x>>y;
			if (x==dx&&y==dy)exit(0);
		}
		cout<<way[1]<<endl;
		fflush(stdout);
		pre=x;
		cin>>x>>y;
		if (x==pre+1)
		{
			if (x==dx&&y==dy)exit(0);
			swap(way[1],way[3]);
			inv2=1;
			cout<<way[1]<<endl;
			fflush(stdout);
			cin>>x>>y;
		}
		while (x!=1||y!=1)
		{
			cout<<way[4]<<endl;
			fflush(stdout);
			cin>>x>>y;
		}

	}
}
int main()
{	
	//freopen("1.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
			{
				scanf("%c",&g[i][j]);
				if (g[i][j]=='F')dx=i,dy=j;
			}
	}	
	way[1]='U';
	way[2]='R';
	way[3]='D';
	way[4]='L';
	getright();
	bfs();
	return 0;
}