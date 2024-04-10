#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#define LL long long 
#define inf 1000000007
using namespace std;
LL n;
LL a[600000];
LL b[600000];
LL C[600000];
LL pw(LL x,LL p)
{
	LL ans=1;
	while (p>0)
	{
		if (p&1)ans=ans*x%inf;
		p=p>>1;
		x=x*x%inf;
	}
	return ans;
}
void work()
{
	LL tmp=n/2-1;
	LL ans1=0;
	LL ans2=0;
	LL ans;
	C[0]=1;
	for(int i=1;i<=tmp;i++)C[i]=(C[i-1]*(LL)(tmp-i+1)%inf)*pw(i,inf-2)%inf;
	int opt=1;
	for(int i=1;i<=n/2;i++)
	{
		tmp=(a[2*i-1]+inf)%inf;
		tmp=tmp*C[i-1]%inf;
		ans1=(ans1+tmp)%inf;

		tmp=(a[2*i]+inf)%inf;
		tmp=tmp*C[i-1]%inf;
		ans2=(ans2+tmp)%inf;
		opt=-opt;
	}
	if (opt==1)ans=ans1-ans2;
	else ans=ans2+ans1;
	ans=((ans%inf)+inf)%inf;
	cout<<ans<<endl;
}
int main()
{	
	scanf("%i64d",&n);
	for(int i=1;i<=n;i++)scanf("%i64d",&b[i]);
	if (n==1)
	{
		cout<<b[1]<<endl;
		return 0;
	}
	if (n%2==1)
	{
		for(int i=1;i<n;i++)
			if (i%2==1)a[i]=b[i]+b[i+1];
			else a[i]=b[i]-b[i+1];
		n--;
	}
	else for(int i=1;i<=n;i++)a[i]=b[i];
	
	if (n==1)
	{
		cout<<a[1]<<endl;
		return 0;
	}
	work();
	return 0;
}