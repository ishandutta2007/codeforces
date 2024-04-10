#include <bits/stdc++.h>

using namespace std;

long long minl(long long a,long long b)
{
	return a<b? a:b;
}

long long calc(long long k)
{
	if(k%2) return (k/2+1) * (k/2+2);
	else return (k/2+1) * (k/2+1);
}

long long F(long long a,long long can,long long b)
{
	if(b-a > can) return 0;
	
	return calc(can - (b-a));
}

long long F2(long long a,long long can,long long b)
{
	if(a < b) return 0;
	
	return (minl(can , (a-b))+1) * (minl(can,(a-b))+2) / 2;
}

int main()
{
	long long a,b,c,l,i,sum=0,s1,s2,s3;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&l);
	
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	if(b<c) swap(b,c);
	
	for(i=0; i<=l; i++){
		s1 = F(b,l-i,a+i+c);
		s2 = F(c,l-i,a+i+b);
		s3 = F2(a+i,l-i,b+c);
		
		sum += (l-i+1) * (l-i+2) / 2 - s1 - s2 - s3;
//		printf("%lld %lld %lld %lld %lld\n",i,sum,s1,s2,s3);
	}
	
	printf("%lld\n",sum);
	
	return 0;
}