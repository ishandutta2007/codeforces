#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int cnt;
int far[maxn*2];
void init()
{
	for(int i=0;i<maxn*2;i++)
		far[i]=i;
}
int Find(int x)
{
	if(x==far[x]) return x;
	return far[x]=Find(far[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x==y) return;
	far[y]=x;
	cnt--;
}
int main()
{
	init();
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	cnt=n+m;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Union(x,y+n);
	}
	printf("%d\n",cnt-1);
}