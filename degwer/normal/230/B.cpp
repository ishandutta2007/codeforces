#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define LIMIT 1000000
typedef long long ll;
vector<int>prime;
bool map[LIMIT+1];
void primefind()
{
	fill(map,map+LIMIT+1,true);
	for(int i=2;;i++)
	{
		if(i*i>LIMIT)
		{
			break;
		}
		map[i]=false;
		bool han=true;
		for(int j=0;j<prime.size();j++)
		{
			if(prime[j]*prime[j]>i)
			{
				break;
			}
			if(i%prime[j]==0)
			{
				han=false;
				break;
			}
		}
		if(han)
		{
			prime.push_back(i);
			map[i]=true;
		}
	}
	for(int i=0;i<prime.size();i++)
	{
		for(int j=2;prime[i]*j<=LIMIT;j++)
		{
			map[prime[i]*j]=false;
		}
	}
}
vector<ll>ans;
int main()
{
	primefind();
	for(ll i=2;i<=LIMIT;i++)
	{
		if(map[i])
		{
			ans.push_back(i*i);
		}
	}
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		if(lower_bound(ans.begin(),ans.end(),zan)!=upper_bound(ans.begin(),ans.end(),zan))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}