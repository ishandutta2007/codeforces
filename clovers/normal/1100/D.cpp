#include<bits/stdc++.h>
using namespace std;
const int inf=200000000;
int dx[]={-1,-1,1,1};
int dy[]={-1,1,-1,1};

struct node{
	int x,y;
}a[667];
int mp[1020][1020];

void init()
{
	memset(mp,0,sizeof(mp));
	for(int i=0;i<=666;i++) 
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if (i) mp[a[i].x][a[i].y]++;
	}
}

void print()
{
	printf("%d %d\n",a[0].x,a[0].y);
	fflush(stdout);
}

void up()
{
	a[0].x--;
	print();
}

void down()
{
	a[0].x++;
	print();
}

void left()
{
	a[0].y--;
	print();
}

void right()
{
	a[0].y++;
	print();
} 

void leftup()
{
	if(mp[a[0].x-1][a[0].y-1]) 
	{
		up();
		//flag=1;
		return;
	}
	a[0].x--; a[0].y--;
	print();
}

void leftdown()
{
	if(mp[a[0].x+1][a[0].y-1]) 
	{
		down();
		//flag=1;
		return;
	}
	a[0].x++; a[0].y--;
	print();
}

void rightdown()
{
	if(mp[a[0].x+1][a[0].y+1]) 
	{
		down();
		//flag=1;
		return;
	}
	a[0].x++; a[0].y++;
	print();
}

void rightup() 
{
	if(mp[a[0].x-1][a[0].y+1]) 
	{
		up();
		//flag=1;
		return;
	}
	a[0].x--; a[0].y++;
	print();
}

void read()
{
	int id,xx,yy;
	scanf("%d%d%d",&id,&xx,&yy);
	if(id==-1) 
	{
		//flag=1;
		exit(0);
	}
	mp[a[id].x][a[id].y]--;
	a[id].x=xx; a[id].y=yy;
	mp[a[id].x][a[id].y]++;
}

void ready()
{
	while(a[0].x<500)
	{
		down();
		read();
		//if(flag) exit(0);
	}
	while(a[0].x>500)
	{
		up();
		read();
		//if(flag) exit(0);
	}
	while(a[0].y>500)
	{
		left();
		read();
		//if(flag) exit(0);
	}
	while(a[0].y<500)
	{
		right();
		read();
		//if(flag) exit(0);
	}
}

int dir,minn=inf,tmp;
void judge_direction()
{
	int cnt[4]={0,0,0,0};//0:leftup 1:rightup 2:leftdown 3:rightdown
	for(int i=1;i<=999;i++)
	{
		for(int j=1;j<=999;j++)
		{
			if(i<500)
			{
				if(j<500) cnt[0]+=mp[i][j];
				if(j>500) cnt[1]+=mp[i][j];
			} 
			if(i>500)
			{
				if(j<500) cnt[2]+=mp[i][j];
				if(j>500) cnt[3]+=mp[i][j];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		if(minn>cnt[i]) minn=cnt[i],tmp=i;
	}
	dir=3-tmp;
}

void move(int dir)
{
	if(dir==0) leftup();
	else if(dir==1) rightup();
	else if(dir==2) leftdown();
	else rightdown();
}

void solve()
{
	while(1)
	{
		move(dir);
		read();
	}
}

int main()
{
	init();
	ready();
	judge_direction();
	solve();
	return 0;
}