#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
int s[MN+5],d[MN+5];
typedef pair<int,int> pi;
priority_queue<pi,vector<pi>,greater<pi> > pq;
int main()
{
	int n=read(),i,j;long long ans=0;
	for(i=1;i<=n;++i)
	{
		s[i]=read();
		pq.push(make_pair(d[i]=s[i]+read(),i)); 
	}
	while(!pq.empty())
	{
		pi x=pq.top();pq.pop();
		if(x.first>d[x.second])continue;
		if(x.first+1<d[x.second-1])
			pq.push(make_pair(d[x.second-1]=x.first+1,x.second-1));
		if(x.first+1<d[x.second+1])
			pq.push(make_pair(d[x.second+1]=x.first+1,x.second+1));
	}
	for(i=1;i<=n;++i)if(d[i]<s[i])return 0*puts("-1");else ans+=d[i]-s[i];
	printf("%I64d\n",ans);
	for(i=1;i<=n;++i)printf("%d ",d[i]);
}