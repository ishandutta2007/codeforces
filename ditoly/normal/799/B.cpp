#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 200000
struct shirt{int p,a,b;}p[MN+5];
bool cmp(shirt a,shirt b){return a.p<b.p;}
int u[MN+5];
queue<int> v[4];
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)p[i].p=read();
	for(i=1;i<=n;++i)p[i].a=read();
	for(i=1;i<=n;++i)p[i].b=read();
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;++i)v[p[i].a].push(i),v[p[i].b].push(i);
	for(i=read();i--;)
	{
		n=read();
		while(v[n].size()&&u[v[n].front()])v[n].pop();
		if(v[n].size())printf("%d\n",p[v[n].front()].p),u[v[n].front()]=1;
		else puts("-1");
	}
}