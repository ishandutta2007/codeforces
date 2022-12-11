#include<cstdio>
#define ll long long
ll read()
{
	ll x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 300000
priority_queue<ll,vector<ll>,greater<ll> > pq;
struct team{ll t,w;}t[MAXN+5];
bool cmp(team a,team b){return a.t>b.t;}
int main()
{
	int n,i,ans;ll b;
	n=read();b=read();read();
	for(i=1;i<n;i++)t[i]=(team){read(),read()};
	sort(t+1,t+n,cmp);
	for(i=1;i<n&&t[i].t>b;i++)pq.push(t[i].w-t[i].t+1);
	ans=pq.size();
	while(pq.size())
	{
		if(b<pq.top())break;
		b-=pq.top();pq.pop();
		for(;i<n&&t[i].t>b;i++)pq.push(t[i].w-t[i].t+1);
		if(pq.size()<ans)ans=pq.size();
	}
	printf("%d",ans+1);
}