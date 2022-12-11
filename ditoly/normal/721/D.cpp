#include<cstdio>
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-f;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
#include<queue>
using namespace std;
#define ll long long
#define MAXN 200000
inline ll jdz(ll x){return x<0?-x:x;}
struct node
{
	ll x;int f;
	friend bool operator<(node a,node b){return jdz(a.x)>jdz(b.x);}
}nd;
priority_queue<node> pq;
ll a[MAXN+5];
int main()
{
	int n,k,x,i,t=0,r;
	n=read();k=read();x=read();
	for(i=0;i<n;i++)
	{
		if((r=read())<0)t++;
		pq.push((node){r,i});
	}
	if(~t&1)
	{
		nd=pq.top();pq.pop();
		if(nd.x<0)for(;k&&nd.x<=0;k--)nd.x+=x;
		else for(;k&&nd.x>=0;k--)nd.x-=x;
		pq.push(nd);
	}
	for(;k;k--)
	{
		nd=pq.top();pq.pop();
		if(nd.x<0)nd.x-=x;
		else nd.x+=x;
		pq.push(nd);
	}
	while(pq.size())
	{
		a[pq.top().f]=pq.top().x;
		pq.pop();
	}
	for(i=0;i<n;i++)printf("%I64d ",a[i]);
}