#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	for(;;)
	{
		if(a<b)
		{
			swap(a,b);
		}
		if(a%b==0)
		{
			return b;
		}
		a%=b;
	}
}
int main()
{
	ll num;
	scanf("%I64d",&num);
	ll maxi=1;
	ll low=1;
	for(ll i=num-2;i>=1;i--)
	{
		if(gcd(num,i)==1)
		{
			low=i;
			break;
		}
	}
	for(ll i=low;i<=num;i++)
	{
		for(ll j=low;j<=num;j++)
		{
			for(ll k=low;k<=num;k++)
			{
				ll zan=i*j/gcd(i,j);
				maxi=max(maxi,zan*k/gcd(zan,k));
			}
		}
	}
	printf("%I64d\n",maxi);
}