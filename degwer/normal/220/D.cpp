#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll po(ll a,ll b)
{
	vector<int>vec;
	for(;;)
	{
		if(b==0)
		{
			break;
		}
		vec.push_back(b%2);
		b/=2;
	}
	reverse(vec.begin(),vec.end());
	ll ret=1;
	for(int i=0;i<vec.size();i++)
	{
		ret*=ret;
		ret%=mod;
		if(vec[i])
		{
			ret*=a;
			ret%=mod;
		}
	}
	return ret;
}
ll inv(ll a)
{
	return po(a,mod-2);
}
ll kai[100001];
void calc()
{
	kai[0]=1;
	for(int i=1;i<=100000;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=mod;
	}
}
ll com2(ll a,ll b)
{
	if(a<b)
	{
		return 0;
	}
	ll ret=kai[a];
	ret*=inv(kai[b]);
	ret%=mod;
	ret*=inv(kai[a-b]);
	ret%=mod;
	return ret;
}
ll com(ll a,ll b)
{
	if(b==2)
	{
		a=(a-1)%mod+1;
		return (a*(a-1)/2)%mod;
	}
	else
	{
		a=(a-2)%mod+2;
		ll ret=a;
		ret*=(a-1);
		ret/=2;
		ret%=mod;
		ret*=(a-2);
		ret%=mod;
		ret*=inv(3);
		ret%=mod;
		return ret;
	}
}
		
ll dp[4003][4003];
ll gcd(ll a,ll b)
{
	if(a>b)
	{
		swap(a,b);
	}
	for(;;)
	{
		b%=a;
		if(!b)
		{
			return a;
		}
		swap(a,b);
	}
}
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	mx++;
	my++;
	ll a,b,c,d;
	a=((mx+1)/2)*((my+1)/2);
	b=(mx/2)*((my+1)/2);
	c=((mx+1)/2)*(my/2);
	d=(mx/2)*(my/2);
	ll ret=0;
	ll sum=a+b+c+d;
	ret+=com(a,3);
	ret+=com(b,3);
	ret+=com(c,3);
	ret+=com(d,3);
	ret+=com(a,2)*(sum-a);
	ret+=com(b,2)*(sum-b);
	ret+=com(c,2)*(sum-c);
	ret+=com(d,2)*(sum-d);
	ret%=mod;
	for(int i=1;i<mx;i++)
	{
		for(int j=1;j<my;j++)
		{
			dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j]-dp[i][j]+gcd(i,j)-1)%mod;
			ret-=dp[i+1][j+1]+dp[i+1][j+1];
			ret=(ret+mod+mod)%mod;
		}
	}
	ret-=mx*com(my,3);
	ret-=my*com(mx,3);
	ret%=mod;
	if(ret<0)
	{
		ret+=mod;
	}
	ret*=6;
	ret%=mod;
	printf("%I64d\n",ret);
}