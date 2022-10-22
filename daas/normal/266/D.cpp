#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
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
int n,m,dis[210][210],mem[40010][3],S,id[210];
vector<int> Q[210];
double ans=1e9;
int cmp(int x,int y) {return dis[x][S]>dis[y][S];}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),l=read();
		mem[i][0]=u,mem[i][1]=v,mem[i][2]=l;
		Q[u].push_back(i);
		dis[u][v]=min(dis[u][v],l);
		dis[v][u]=dis[u][v];
	}
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int j=1;j<=n;++j)
		for(int i=1;i<=n;++i)
			for(int k=1;k<=n;++k)
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	for(int i=1;i<=n;++i) id[i]=i;
	for(int p=1;p<=n;++p)
	{
		S=p;
		sort(id+1,id+n+1,cmp);
		for(int t=0;t<Q[p].size();++t)
		{
			int u=mem[Q[p][t]][0],v=mem[Q[p][t]][1];
			double L=0,maxn=-1e9;
			for(int i=1;i<=n;++i)
			{
				double R=min((double)mem[Q[p][t]][2],(double)(dis[id[i]][v]+mem[Q[p][t]][2]-dis[id[i]][u])/2.0);
				/*dis[i][u]+x;
				maxn-x;*/
				double mid=(maxn-dis[id[i]][u])/2;
				/*printf("%.2lf %.2lf\n",L,R);
				printf("%.2lf %.2lf %.2lf\n",(double)dis[id[i]][u],maxn,mid);*/
				if(L<=mid && mid<=R) ans=min(ans,dis[id[i]][u]+mid);
				else if(mid<L) ans=min(ans,max(dis[id[i]][u]+L,maxn-L));
				else if(R<mid) ans=min(ans,max(dis[id[i]][u]+R,maxn-R));
				L=max(L,(double)(dis[id[i]][v]+mem[Q[p][t]][2]-dis[id[i]][u])/2.0);
				maxn=max(maxn,(double)dis[id[i]][v]+mem[Q[p][t]][2]);
			}
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}
//ore no turn,draw!