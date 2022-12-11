#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
long long h,c,t;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld %lld",&h,&c,&t);
		if(2*t<=h+c)printf("2\n");
		else 
		{
			long long n=(h-c)/(2*t-h-c);
			if(n%2==0)--n;
			if(n<0)n+=2;
			long long a=((n+1)/2*h+(n-1)/2*c-t*n)*(n+2);
			long long b=(t*(n+2)-(n+3)/2*h-(n+1)/2*c)*n;
			if(a<=b)printf("%lld\n",n);
			else printf("%lld\n",n+2);
		}
	}
	return 0;
}