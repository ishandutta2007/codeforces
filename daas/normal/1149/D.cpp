#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,A,B,dis[101][101],mem[201][3],father[101],point[101],cnt[101],K,id[101];
int dl[10000000][2],h,t,pd[270000][71],D[270000][71],len;
int find(int k)
{	
	if(father[k]!=k)
		father[k]=find(father[k]);
	return father[k];
}
void merge(int x,int y)
{
	int ax=find(x),ay=find(y);
	if(ax!=ay)
		father[ax]=ay;
}
void SPFA()
{
	len=(1<<K)*n;
	memset(D,0x3f,sizeof(D));
	D[0][1]=0;
	dl[++t][1]=1;
	while(h!=t)
	{
		h=h%len+1;
		int state=dl[h][0],u=dl[h][1];
		pd[state][u]=0;
		for(int i=1;i<=n;++i)
		{
			int state_new=state;
			if(point[i]!=point[u])
			{
				if(id[point[i]])
				{
					if(state&(1<<(id[point[i]]-1)))
						continue;
				}
				if(id[point[u]])
					state_new|=(1<<(id[point[u]]-1));
			}
			if(D[state_new][i]>D[state][u]+dis[u][i])
			{
				D[state_new][i]=D[state][u]+dis[u][i];
				if(!pd[state_new][i])
				{
					pd[state_new][i]=1;
					t=t%len+1;
					dl[t][0]=state_new;
					dl[t][1]=i;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		int minn=0x7f7f7f7f;
		for(int j=0;j<(1<<K);++j)
			minn=min(minn,D[j][i]);
		printf("%d ",minn);
	}
}
int main()
{
	n=read(),m=read(),A=read(),B=read();
	if(A>B)
		swap(A,B);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)
		father[i]=i;
	for(int i=1;i<=m;++i)
	{
		mem[i][0]=read();
		mem[i][1]=read();
		mem[i][2]=read();
		if(mem[i][2]==A)
		{
			dis[mem[i][0]][mem[i][1]]=dis[mem[i][1]][mem[i][0]]=A;
			merge(mem[i][0],mem[i][1]);
		}
	}
	for(int i=1;i<=n;++i)
		dis[i][i]=0;
	for(int j=1;j<=n;++j)
		for(int i=1;i<=n;++i)
			for(int k=1;k<=n;++k)
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	for(int i=1;i<=n;++i)
	{
		point[i]=find(i);
		cnt[point[i]]++;
	}
	for(int i=1;i<=n;++i)
		if(point[i]==i)
		{
			if(cnt[i]>3)
				id[i]=++K;
		}
	for(int i=1;i<=m;++i)
		if(mem[i][2]==B && dis[mem[i][0]][mem[i][1]]==0x3f3f3f3f)
			dis[mem[i][0]][mem[i][1]]=dis[mem[i][1]][mem[i][0]]=B;
	SPFA();
	return 0;
}