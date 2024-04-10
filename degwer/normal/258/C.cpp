#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
vector<int>prime;
int pri[100001];
void primefind()
{
	for(int i=2;i<100001;i++)
	{
		int han=0;
		for(int j=0;j<prime.size();j++)
		{
			if(prime[j]*prime[j]>i)
			{
				break;
			}
			if(i%prime[j]==0)
			{
				han=1;
				break;
			}
		}
		if(han==0)
		{
			prime.push_back(i);
			pri[i]=1;
		}
	}
}
vector<pii>bun(int a)
{
	vector<pii>ret;
	for(int i=0;i<prime.size();i++)
	{
		if(prime[i]*prime[i]>a)
		{
			break;
		}
		if(a%prime[i]==0)
		{
			ret.push_back(make_pair(prime[i],0));
			for(;;)
			{
				if(a%prime[i]==0)
				{
					ret[ret.size()-1].second++;
					a/=prime[i];
				}
				else
				{
					break;
				}
			}
		}
	}
	if(a!=1)
	{
		ret.push_back(make_pair(a,1));
	}
	return ret;
}
vector<int>tob(vector<pii>vec)
{
	vector<int>ret;
	ret.push_back(1);
	for(int i=0;i<vec.size();i++)
	{
		vector<int>zan;
		int now=1;
		for(int j=0;j<=vec[i].second;j++)
		{
			for(int k=0;k<ret.size();k++)
			{
				zan.push_back(ret[k]*now);
			}
			now*=vec[i].first;
		}
		ret=zan;
	}
	return ret;
}
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
int main()
{
	primefind();
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	ll ret=1;
	for(int i=vec[vec.size()-1];i>=2;i--)
	{
		ll sum=1;
		ll sum2=1;
		vector<int>zan=tob(bun(i));
		sort(zan.begin(),zan.end());
		int bef=vec.size();
		for(int j=zan.size()-1;j>=0;j--)
		{
			int low=lower_bound(vec.begin(),vec.end(),zan[j])-vec.begin();
			sum*=po(j+1,bef-low);
			bef=low;
			sum%=mod;
		}
		bef=vec.size();
		for(int j=zan.size()-2;j>=0;j--)
		{
			int low=lower_bound(vec.begin(),vec.end(),zan[j])-vec.begin();
			sum2*=po(j+1,bef-low);
			bef=low;
			sum2%=mod;
		}
		ret=(ret+mod+sum-sum2)%mod;
	}
	printf("%I64d\n",ret);
}