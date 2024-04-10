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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[100001],b[100001],na,nb;
double ans;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		na=nb=0;
		for(int i=1;i<=2*n;++i)
		{
			int x=read(),y=read();
			if(!x) a[++na]=y*y;
			if(!y) b[++nb]=x*x;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		ans=0;
		for(int i=1;i<=n;++i) ans+=sqrt(a[i]+b[i]);
		printf("%.10lf\n",ans);
	}
	return 0;
}