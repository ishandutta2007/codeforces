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
const int MAXN=2e5+10;
const int MAXM=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m;
struct node
{
	int head[MAXN],tot;
	int to[MAXM],nextn[MAXM];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
int dis[MAXN],pd[MAXN],val[MAXN];
struct data
{
	int id,dis;
	data(int _id=0,int _dis=0) {id=_id,dis=_dis;}
	bool operator <(const data &Z) const {return dis>Z.dis;}
};
#include<queue>
priority_queue<data> Q;
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		Ed.ADD(v,u);
		++val[u];
	}
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0;
	Q.push(data(n,0));
	while(!Q.empty())
	{
		data u=Q.top();
		Q.pop();
		if(pd[u.id]) continue;
		pd[u.id]=1;
		for(int i=Ed.head[u.id];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(dis[v]>u.dis+val[v])
			{
				dis[v]=u.dis+val[v];
				Q.push(data(v,dis[v]));
			}
			--val[v];
		}
	}
	printf("%d\n",dis[1]);
	return 0;
}
//tetu no isi to hagane no tuyosa