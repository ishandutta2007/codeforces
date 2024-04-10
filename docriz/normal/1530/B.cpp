#include<bits/stdc++.h>
using namespace std;
int mov[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int cnt=0,T,bt=0,ans=0,vis[25][25],a[10005][2],h,w,sum=0;
int leg(int x,int y)
{
	return x&&y&&x<=h&&y<=w;
}
void ins(int x,int y)
{
	cnt++;
	a[cnt][0]=x;a[cnt][1]=y;
}
void gof(int x)
{
	for(int i=x;i<=cnt;i++)
	{
		for(int j=0;j<8;j++)
		{
			int nx=a[i][0]+mov[j][0];
			int ny=a[i][1]+mov[j][1];
			if(leg(nx,ny)&&vis[nx][ny])goto tag;
		}
		vis[a[i][0]][a[i][1]]=1;
		sum++;
		tag:;
	}
	for(int i=1;i<x;i++)
	{
		for(int j=0;j<8;j++)
		{
			int nx=a[i][0]+mov[j][0];
			int ny=a[i][1]+mov[j][1];
			if(leg(nx,ny)&&vis[nx][ny])goto tag2;
		}
		vis[a[i][0]][a[i][1]]=1;
		sum++;
		tag2:;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&h,&w);
		cnt=0;
		for(int i=1;i<=w;i++)
		{
			ins(1,i);
		}
		for(int i=2;i<h;i++)ins(i,w);
		for(int i=w;i>=1;i--)ins(h,i);
		for(int i=h-1;i>1;i--)ins(i,1);
		ans=0;bt=0;
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=h;j++)for(int k=1;k<=w;k++)vis[j][k]=0;
			sum=0;
			gof(bt);
			if(sum>ans)ans=sum,bt=i;
		}
		gof(bt);
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)printf("%d",vis[i][j]);
			printf("\n");
		}
	}
	return 0;
}