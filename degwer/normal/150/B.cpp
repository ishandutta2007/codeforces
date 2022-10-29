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
ll com(ll a,ll b)
{
	ll ret=kai[a];
	ret*=inv(kai[b]);
	ret%=mod;
	ret*=inv(kai[a-b]);
	ret%=mod;
	return ret;
}
int main()
{
	calc();
	int len,gen,lon;
	scanf("%d%d%d",&len,&gen,&lon);
	if(len<lon||lon==1)
	{
		printf("%I64d\n",po(gen,len));
		return 0;
	}
	if(len==lon)
	{
		printf("%I64d\n",po(gen,(len+1)/2));
		return 0;
	}
	if(lon%2==0)
	{
		printf("%d\n",gen);
		return 0;
	}
	else
	{
		printf("%I64d\n",(po(gen,2)));
	}
}