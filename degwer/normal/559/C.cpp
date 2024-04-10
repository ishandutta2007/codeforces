#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[2002][2];
ll mod=1000000007;
typedef pair<ll,ll>pii;
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
ll kai[210001];
void calc()
{
	kai[0]=1;
	for(int i=1;i<=210000;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=mod;
	}
}
ll invk[210001];
ll com(ll a,ll b)
{
	ll ret=kai[a];
	ret*=invk[b];
	ret%=mod;
	ret*=invk[a-b];
	ret%=mod;
	return ret;
}
int main()
{
	ll mx,my;
	int num;
	scanf("%I64d%I64d%d",&mx,&my,&num);
	vector<pii>vec;
	calc();
	for(int i=0;i<=210000;i++)invk[i]=po(kai[i],mod-2);
	for(int i=0;i<num;i++)
	{
		ll za,zb;
		scanf("%I64d%I64d",&za,&zb);
		za--;
		zb--;
		vec.push_back(make_pair(za,zb));
	}
	vec.push_back(make_pair(0,0));
	vec.push_back(make_pair(mx-1,my-1));
	sort(vec.begin(),vec.end());
	dp[0][1]=1;
	for(int i=1;i<vec.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(vec[i].first>=vec[j].first&&vec[i].second>=vec[j].second)
			{
				dp[i][0]+=dp[j][1]*com((vec[i].first-vec[j].first)+(vec[i].second-vec[j].second),(vec[i].first-vec[j].first));
				dp[i][0]%=mod;
				dp[i][1]+=dp[j][0]*com((vec[i].first-vec[j].first)+(vec[i].second-vec[j].second),(vec[i].first-vec[j].first));
				dp[i][1]%=mod;
			}
		}
	}
	printf("%I64d\n",(dp[num+1][0]+mod-dp[num+1][1])%mod);
}