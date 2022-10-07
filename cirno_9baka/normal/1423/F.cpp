#include<bits/stdc++.h>
using namespace std;
int n,p,i,a,b;
long long s=0,ss=0;
int main()
{
	scanf("%d %d",&n,&p);
	for(i=1;i<=p;++i)
	{
		scanf("%d %d",&a,&b);
		s+=b;
		ss=(ss+1ll*(a-1)*b)%n;
	}
	puts((s<n||(s==n&&ss==1ll*(n-1)*n/2%n))?"1":"-1");
}