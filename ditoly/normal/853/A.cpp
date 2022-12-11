#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 300000
int c[MN+5],ans[MN+5];
long long s,cnt;
priority_queue< pair<int,int> > pq;
int main()
{
	int n,k,i;
	n=read();k=read();
	for(i=1;i<=n;++i)c[i]=read();
	for(i=1;i<=n+k;++i)
	{
		if(i<=n)cnt+=c[i],pq.push(make_pair(c[i],i));
		if(i>k)ans[pq.top().second]=i,cnt-=pq.top().first,pq.pop();
		s+=cnt;
	}
	printf("%I64d\n",s);
	for(i=1;i<=n;++i)printf("%d ",ans[i]);
}