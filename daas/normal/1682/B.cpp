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
int T,n,p[200010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) p[i]=read();
		int ans=-1;
		for(int i=1;i<=n;++i) if(p[i]!=i-1)
		{
			if(ans==-1) ans=p[i];
			else ans&=p[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!