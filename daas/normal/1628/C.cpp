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
int T,n,a[1010][1010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				a[i][j]=read();
		int ans=0;
		for(int i=2;i<=2*n;i+=4)
		{
			if(i<=n+1)
			{
				for(int j=i-1;j>=1;j-=2)
				{
					ans^=a[j][i-j]^a[n-j+1][i-j];
				}
			}
			else
			{
				for(int j=n;i-j<=n;j-=2)
				{
					ans^=a[j][i-j]^a[n-j+1][i-j];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!