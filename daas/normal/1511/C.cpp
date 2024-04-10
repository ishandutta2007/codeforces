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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,h[51],pre[51][51];
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		int v=read();
		if(!h[v]) h[v]=i;
	}
	for(int i=1;i<=50;++i)
		for(int j=1;j<=50;++j)
			if(h[j]<=h[i]) pre[i][j]=1;
	while(q--)
	{
		int v=read();
		printf("%d ",h[v]);
		for(int i=1;i<=50;++i) if(i!=v)
		{
			if(!pre[i][v]) ++h[i];
			pre[i][v]=1;
			pre[v][i]=0;
		}
		h[v]=1;
	}
	return 0;
}