#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
void no()
{
	printf("-1");
	exit(0);
}
const int S=401,T=402,SS=403,TT=404;
struct bian
{
	int nxt,to,f,w;
}bi[10010];
int n1,n2,m,r,b;
char c1[210],c2[210];
int d1[210],d2[210],d[410],head[410],num=1,ans;
inline void add(int from,int to,int f,int w){bi[++num]=bian{head[from],to,f,w};head[from]=num;}
inline void ADD(int from,int to,int f,int w){add(from,to,f,w),add(to,from,0,-w);}
queue<int>q;
int dis[410],fb[410];
bool in[410];
bool spfa()
{
	memset(dis,0x3f,sizeof(dis));
	dis[SS]=0;q.push(SS);
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();in[x]=0;
		for(int i=head[x];i;i=bi[i].nxt)
			if(bi[i].f)
			{
				y=bi[i].to;
				if(dis[x]+bi[i].w<dis[y])
				{
					dis[y]=dis[x]+bi[i].w;
					fb[y]=i;
					if(!in[y])in[y]=1,q.push(y);
				}
			}
	}
	return dis[TT]!=0x3f3f3f3f;
}
int main()
{
	scanf("%d %d %d %d %d",&n1,&n2,&m,&r,&b);
	scanf("%s%s",c1+1,c2+1);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d %d",&x,&y),++d1[x],++d2[y];
		ADD(y+n1,x,1,r);--d[x],++d[y+n1];
		ADD(x,y+n1,1,b);
	}
	for(int i=1;i<=n1;++i)
	{
		if(c1[i]!='U'&&!d1[i])no();
		if(c1[i]=='R')ADD(S,i,d1[i]-1,0);
		else if(c1[i]=='B')ADD(S,i,d1[i]-1,0),d[S]-=d1[i]+1,d[i]+=d1[i]+1;
		else ADD(S,i,2*d1[i],0);
	}
	for(int i=1;i<=n2;++i)
	{
		if(c2[i]!='U'&&!d2[i])no();
		if(c2[i]=='R')ADD(i+n1,T,d2[i]-1,0);
		else if(c2[i]=='B')ADD(i+n1,T,d2[i]-1,0),d[i+n1]-=d2[i]+1,d[T]+=d2[i]+1;
		else ADD(i+n1,T,2*d2[i],0);
	}
	int sum=0;
	for(int i=1;i<=402;++i)
		if(d[i]<0)ADD(i,TT,-d[i],0);
		else if(d[i]>0)ADD(SS,i,d[i],0),sum+=d[i];
	ADD(T,S,0x3f3f3f3f,0);
//	for(int i=1;i<=404;++i)
//		for(int j=head[i];j;j=bi[j].nxt)
//			if(bi[j].f)printf("%d %d %d %d\n",i,bi[j].to,bi[j].f,bi[j].w);
	while(spfa())
	{
		int x=TT;ans+=dis[TT];
		while(x!=SS)--bi[fb[x]].f,++bi[fb[x]^1].f,x=bi[fb[x]^1].to;
		--sum;
	}
//	printf("%d\n",sum);
	if(sum)no();
	printf("%d\n",ans);
	for(int i=1;i<=m;++i)
	{
		if(!bi[(i-1)*4+2].f)printf("R");
		else if(bi[i*4].f)printf("U");
		else printf("B");
	}
	return 0;
}