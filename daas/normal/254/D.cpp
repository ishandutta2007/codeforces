#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<bitset>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,D,change[4][2]={{0,1},{0,-1},{1,0},{-1,0}},bjx=-1,bjy,pcnt,map[1010][1010];
char s[1010];
struct data
{
	int dl[200][3],h,t,vis[1010][1010];
	bitset<290> S;
	void init()
	{
		while(t)
		{
			vis[dl[t][0]][dl[t][1]]=0;
			if(map[dl[t][0]][dl[t][1]]>0) S.reset(map[dl[t][0]][dl[t][1]]-1);
			--t;
		}
		h=t=0;
	}
	void bfs(int x,int y)
	{
		if(map[x][y]>0) S.set(map[x][y]-1);
		dl[++t][0]=x;
		dl[t][1]=y;
		dl[t][2]=0;
		vis[x][y]=1;
		while(h!=t)
		{
			int ux=dl[++h][0];
			int uy=dl[h][1];
			int ud=dl[h][2];
			if(ud==D) continue;
			for(int i=0;i<4;++i)
			{
				int vx=ux+change[i][0];
				int vy=uy+change[i][1];
				if(vx<1 || vx>n || vy<1 || vy>m || map[vx][vy]==-1 || vis[vx][vy]==1) continue;
				vis[vx][vy]=1;
				if(map[vx][vy]>0) S.set(map[vx][vy]-1);
				dl[++t][0]=vx;
				dl[t][1]=vy;
				dl[t][2]=ud+1;
			}
		}
	}
}mem[5];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read(),m=read(),D=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			switch(s[j])
			{
				case 'X':map[i][j]=-1;break;
				case '.':map[i][j]=0;break;
				case 'R':map[i][j]=++pcnt,bjx=i,bjy=j;break;
			}
	}
	if(pcnt>290) {puts("-1");return 0;}
	mem[0].bfs(bjx,bjy);
	for(int p1=1;p1<=mem[0].t;++p1)
	{
		mem[1].init();
		mem[1].bfs(mem[0].dl[p1][0],mem[0].dl[p1][1]);
		bjx=-1;
		if(mem[1].S.count()==pcnt)
		{
			for(int i=1;i<=n && bjx==-1;++i)
				for(int j=1;j<=m && bjx==-1;++j)
					if(map[i][j]!=-1 && (i!=mem[0].dl[p1][0] || j!=mem[0].dl[p1][1]))
						bjx=i,bjy=j;
			printf("%d %d %d %d\n",mem[0].dl[p1][0],mem[0].dl[p1][1],bjx,bjy);
			return 0;
		}
		for(int i=1;i<=n && bjx==-1;++i)
			for(int j=1;j<=m && bjx==-1;++j)
				if(map[i][j]>0 && !mem[1].vis[i][j])
					bjx=i,bjy=j;
		mem[2].init();
		mem[2].bfs(bjx,bjy);
		for(int p2=1;p2<=mem[2].t;++p2)
		{
			mem[3].init();
			mem[3].bfs(mem[2].dl[p2][0],mem[2].dl[p2][1]);
			bitset<290> SS=mem[1].S|mem[3].S;
			if(SS.count()==pcnt) {printf("%d %d %d %d\n",mem[0].dl[p1][0],mem[0].dl[p1][1],mem[2].dl[p2][0],mem[2].dl[p2][1]);return 0;}
		}
	}
	puts("-1");
	return 0;
}
//ore no turn,draw