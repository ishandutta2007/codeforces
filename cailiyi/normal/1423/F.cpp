#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,sum;
long long num;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1,a,b;i<=k;++i)
		scanf("%d %d",&a,&b),sum=(sum+1ll*(a-1)*b)%n,num+=b;
	if(num>n) return puts("-1"),0;
	if(num<n) return puts("1"),0;
	sum==(1ll*n*(n-1)>>1)%n?puts("1"):puts("-1");
	return 0;
}