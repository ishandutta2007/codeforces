#include <cstdio>
#include <algorithm>

using namespace std;

long long D[20],n,i,sum,s=1e9+99,c;

long long x(long long a,long long b)
{
	return a>b?a:b;
}
long long y(long long a,long long b)
{
	return a<b?a:b;
}
int main()
{	
	scanf("%I64d",&n);
	for(i=0;i<n;i++)scanf("%I64d",D+i);
	sort(D,D+n);
	
	for(i=n-1;i>=0;i--){
		c=x(0,y(s-1,D[i]));
		sum += c;
		s=c;
	}
	
	printf("%I64d",sum);
	
	return 0;
}