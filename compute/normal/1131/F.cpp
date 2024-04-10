#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int far[maxn];
int nxt[maxn];
int fil[maxn];
void init()
{
	for(int i=0;i<maxn;i++)
	{
		far[i]=i;
		fil[i]=i;
		nxt[i]=-1;
	}
}
int Find(int x)
{
	if(x==far[x]) return x;
	return far[x]=Find(far[x])	;
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	nxt[fil[x]]=y;
	fil[x]=fil[y];
	far[y]=x;
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	for(int i=0,x,y;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		Union(x,y);
	}
	int fa=Find(1);
	while(fa!=-1)
	{
		printf("%d ",fa);
		fa=nxt[fa];
	}
	puts("");
}