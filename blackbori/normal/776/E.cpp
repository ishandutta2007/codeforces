#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

typedef long long LL;

LL f(LL p)
{
	LL ret=p,i,j;
	for(i=2;i*i<=p;i++){
		if(p%i==0){
			while(p%i==0) p/=i;
			ret = ret/i * (i-1);
		}
	}
	if(p!=1) ret = ret/p * (p-1);

	return ret;
}

int main()
{
	LL n,k;
	
	scanf("%lld%lld",&n,&k);
	k = (k+1)/2;

	for(;k--;){
		n = f(n);
		if(n==1){
			printf("1\n");
			return 0;
		}
	}
	printf("%lld\n",n%(int)(1e9+7));

	return 0;
}