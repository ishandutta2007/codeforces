#include <bits/stdc++.h>

using namespace std;

long long n,i,k=1;

int main()
{
	scanf("%I64d",&n);
	
	for(i=2;(n>1)&&(i<1e7);i++){
		if(n%i==0)k*=i;
		while(n%i==0)n/=i;
	}
	
	if(n>1) k*=n;
	
	printf("%I64d\n",k);
	
	return 0;
}