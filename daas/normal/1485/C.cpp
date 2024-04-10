#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
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
int T,n,m,ans;
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		ans=0;
		for(int i=1;i*(i+2)<=n && i+1<=m;++i) ans+=min((n-i*(i+2))/i,m-i-1)+1;
		printf("%lld\n",ans);
	}
	return 0;
}