#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
ll n,k,a[1000005],ans;
int main()
{
	scanf("%lld %lld",&n,&k);n&=1;
	for(re i=1;i<=k;i++)
	{
		scanf("%lld",&a[i]);a[i]&=1;
		re now=k-i;now&=1;
		if(!a[i]) 
		{
			if(ans) ans=1;
			else ans=0;
		}
		else if(i!=k)
		{
			if(n)
			{
				if(ans) ans=0;
				else ans=1;
			}
			else
			{
				if(ans) ans=1;
				else ans=0;
			}
		}
		else 
		{
			if(a[i])
			{
				if(ans) ans=0;
				else ans=1;
			}
		}
	}
	puts(ans?"odd":"even");
	return 0;
}