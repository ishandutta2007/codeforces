#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,father[200001],pd[100001],Key[100001][2],cnt[100001];
int find(int k)
{
	if(father[k]!=k)
		father[k]=find(father[k]);
	return father[k];
}
void merge(int x,int y)
{
	int ax=find(x),ay=find(y);
	if(ax==ay)
		return;
	father[ax]=ay;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		pd[i]=read();
	for(int i=1;i<=m;++i)
	{
		father[i]=i;
		father[i+m]=i+m;
		int K=read();
		for(int j=1;j<=K;++j)
		{
			int id=read();
			Key[id][cnt[id]++]=i;
		}
	}
	for(int i=1;i<=n;++i)
		if(pd[i])
		{
			merge(Key[i][0],Key[i][1]);
			merge(Key[i][0]+m,Key[i][1]+m);
		}
		else
		{
			merge(Key[i][0]+m,Key[i][1]);
			merge(Key[i][0],Key[i][1]+m);
		}
	for(int i=1;i<=m;++i)
		if(find(i)==find(i+m))
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}