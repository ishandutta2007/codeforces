#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
vector<ll>bun(ll a)
{
	vector<ll>ret;
	for(ll i=2;;i++)
	{
		if(i*i>a)
		{
			break;
		}
		if(a%i==0)
		{
			ret.push_back(i);
			if(i!=a/i)
			{
				ret.push_back(a/i);
			}
		}
	}
	sort(ret.begin(),ret.end());
	return ret;
}
bool dp[100000];
int main()
{
	ll num;
	scanf("%I64d",&num);
	vector<ll>vec=bun(num);
	if(vec.empty())
	{
		printf("1\n0\n");
		return 0;
	}
	vec.push_back(num);
	for(int i=0;i<vec.size();i++)
	{
		bool han=false,vis=false;
		for(int j=0;j<i;j++)
		{
			if(vec[i]%vec[j]==0)
			{
				if(!dp[j])
				{
					han=true;
				}
				vis=true;
			}
		}
		if(han||(!vis))
		{
			dp[i]=true;
		}
		else
		{
			dp[i]=false;
		}
	}
	if(dp[vec.size()-1])
	{
		printf("1\n");
		for(int i=0;i<vec.size();i++)
		{
			if(!dp[i])
			{
				printf("%I64d\n",vec[i]);
				return 0;
			}
		}
	}
	else
	{
		printf("2\n");
	}
}