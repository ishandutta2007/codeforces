#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
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
int T,n,p[210],mem[210],pd[210],pos[210],ans[210];
int check()
{
	memset(pd,0,sizeof(pd));
	for(int i=1;i<=n;++i) if(!pd[i])
	{
		int x=i;
		while(!pd[x])
		{
			pd[x]=i;
			x=mem[x];
		}
	}
	for(int i=1;i<n;++i) if(pd[i]!=pd[i+1]) {swap(mem[i],mem[i+1]);return 1;}
	return 0;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) mem[i]=p[i]=read();
		while(check()) ;
		for(int i=1;i<=n;++i) pos[p[i]]=i;
		for(int i=1,cur=1;i<=n;++i,cur=mem[cur]) ans[i]=pos[mem[cur]];
		for(int i=n;i>=1;--i) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!