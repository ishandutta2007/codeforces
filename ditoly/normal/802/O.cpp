#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
#define MN 500000
#define p(x,y) make_pair(x,y)
priority_queue< pair<ll,int> > pq;
int a[MN+5],b[MN+5];
int main()
{
	int n,k,i,l=0,r=2e9,mid,cnt;ll x,s;
	n=read();k=read();
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)b[i]=read();
	while(l<=r)
	{
		mid=l+(r-l>>1);
		for(s=cnt=0,i=1;i<=n;++i)
		{
			pq.push(p(-a[i],0));
			x=b[i]-mid-pq.top().first;
			if(x<0)s+=x,pq.pop(),pq.push(p(b[i]-mid,1));
		}
		while(!pq.empty())cnt+=pq.top().second,pq.pop();
		if(cnt==k)return 0*printf("%I64d",s+1LL*k*mid);
		if(cnt<k)l=mid+1;else r=mid-1;
	}
}