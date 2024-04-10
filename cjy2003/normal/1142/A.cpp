#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a,b;
long long mini=0x3f3f3f3f3f3f3f3fll,maxi,S;
long long gcd(long long x,long long y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
void calc(long long x,long long y)
{
	long long l=y-x;
	if(l<=0)l+=S;
	long long g=gcd(S,l);
	mini=min(mini,S/g);
	maxi=max(maxi,S/g);
}
int main()
{
	scanf("%d %d %d %d",&n,&k,&a,&b);
	S=1ll*n*k;
	long long x,y;
	x=1+a;
	for(int i=1;i<=n;++i)
	{
		y=(1ll*k*(i-1)+b)%S+1;
		calc(x,y);
		y=(1ll*k*(i-1)-b)%S+1;
		while(y<=0)y+=S;
		calc(x,y);
	}
	x=k+1-a;
	for(int i=1;i<=n;++i)
	{
		y=(1ll*k*(i-1)+b)%S+1;
		calc(x,y);
		y=(1ll*k*(i-1)-b)%S+1;
		while(y<=0)y+=S;
		calc(x,y);
	}
	printf("%I64d %I64d",mini,maxi);
	return 0;
}