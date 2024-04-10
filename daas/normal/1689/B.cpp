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
int T,n,p[1010],q[1010],pd[1010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) p[i]=read();
		if(n==1) {puts("-1");continue;}
		memset(pd,0,sizeof(pd));
		for(int i=1;i<n-1;++i)
		{
			for(int j=1;j<=n;++j) if(!pd[j] && j!=p[i])
			{
				pd[j]=1;
				q[i]=j;
				break;
			}
		}
		int x=0,y=0;
		for(int i=1;i<=n;++i) if(!pd[i])
		{
			if(!x) x=i;
			else y=i;
		}
		if(p[n-1]!=x && p[n]!=y) q[n-1]=x,q[n]=y;
		else q[n-1]=y,q[n]=x;
		for(int i=1;i<=n;++i) printf("%d ",q[i]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!