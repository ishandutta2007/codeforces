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
inline int read()
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
long long sum,n,q[200001],a[200001],b[200001];
int main()
{
	n=read();
	for(register int i=1;i<n;++i)
		q[i]=q[i-1]+read(),sum+=q[i];
	long long t=n*(n+1)/2;
	long long rest=t-sum;
	if(rest%n!=0)
	{
		puts("-1");
		return 0;
	}
	long long p1=rest/n;
	a[1]=b[1]=p1;
	for(register int i=2;i<=n;++i)
		a[i]=b[i]=(q[i-1]+p1);
	sort(a+1,a+n+1);
	if(a[1]!=1)
	{
		puts("-1");
		return 0;
	}
	for(register int i=2;i<=n;++i)
		if(a[i]-a[i-1]!=1)
		{
			puts("-1");
			return 0;
		}
	for(register int i=1;i<=n;++i)
		printf("%I64d ",b[i]);
    return 0;
}