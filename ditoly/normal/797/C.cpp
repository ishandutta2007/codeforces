#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MN 100000
char s[MN+5];
int ls[MN+5],nx[MN+5],u[MN+5];
struct node
{
	char c;int x;
	bool operator<(const node&b)const{return c==b.c?x>b.x:c>b.c;}
};
priority_queue<node> pq;
int main()
{
	int n,i,l,x;
	scanf("%s",s+1);n=strlen(s+1);
	for(i=1;i<=n;++i)ls[i]=i-1,nx[i]=i+1,pq.push((node){s[i],i});
	for(i=l=1;i<=n;++i)
	{
		while((x=pq.top().x)<l||u[x])pq.pop();
		u[x]=1;putchar(pq.top().c);pq.pop();
		if(ls[x]<l&&ls[x])pq.push((node){s[ls[x]],ls[x]});
		l=ls[x];nx[ls[x]]=nx[x];ls[nx[x]]=ls[x];
	}
}