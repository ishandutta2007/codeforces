#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	inline int read()
	{
		static int an;an=0;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an;
	}
}using io::read;
int n,p[1010][1010];
double f[1010],g[1010];
bool vis[1010];
priority_queue<pair<double,int> >q;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			p[i][j]=read();
	for(int i=1;i<=n;++i)g[i]=1;
	q.push(make_pair(0,n));
	int x,y;
	double dis;
	while(!q.empty())
	{
		x=q.top().second;dis=-q.top().first;q.pop();
		if(vis[x])continue;
		vis[x]=1;
	//	printf("%d %lf\n",x,dis);
		if(x==1)return printf("%.12lf",dis),0;
		for(int i=1;i<=n;++i)
			if(!vis[i])
			{
				f[i]=f[i]+g[i]*(p[i][x]/100.0)*(dis+1);
				g[i]=g[i]*(100-p[i][x])/100.0;
				if(1-g[i]>1e-9)q.push(make_pair(-(f[i]+g[i])/(1-g[i]),i));
			}
	}
	return 0;
}