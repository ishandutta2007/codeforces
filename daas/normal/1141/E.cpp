#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline ll read()
{
    ll kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-')
        c=getchar(),x=-1;
    while(c>='0' && c<='9')
        kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
    return kkk*x;
}
ll H,n,a[200001],sum,b[200001],ans;
int main()
{
	H=read(),n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read(),sum-=a[i],b[i]=b[i-1]+a[i];
	ll minn=0;
	for(register int i=1;i<=n;++i)
		if(b[i]<minn)
			minn=b[i];
	H+=minn;
	if(H<=0)
	{
		H-=minn;
		for(register int i=1;i<=n;++i)
			if(H+b[i]<=0)
			{
				printf("%I64d\n",i);
				return 0;
			}
	}
	if(sum<=0)
	{
		puts("-1");
		return 0;
	}
	ll round=H/sum;
	if(H%sum!=0)
		++round;
	ans+=round*n;
	H-=round*sum;
	H-=minn;
	for(register int i=1;i<=n;++i)
		if(H+b[i]<=0)
		{
			printf("%I64d\n",ans+i);
			return 0;
		}
    return 0;
}