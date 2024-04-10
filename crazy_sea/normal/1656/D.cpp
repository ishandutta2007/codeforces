#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int T;
ll n,x,y;
int chk(int n)
{
	for(int i=2;i*(i-1)/2<n;i++)
		if((n-i*(i-1)/2)%i==0) return i;
	return -1;
}
ll calc(ll n)
{
	if(n<=10) return chk(n);
	else
	{
		x=n&(-n),y=n/x; x<<=1;
		if(y==1) return -1;
		return min(x,y);
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		printf("%lld\n",calc(n));
	}
}