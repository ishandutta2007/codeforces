#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll dp[200050];
vector<ll>dat[2000001];
class BIT
{
public:
	ll bit[131073];
	void add(ll a,ll b)
	{
		for(;;)
		{
			if(a>131072)
			{
				break;
			}
			bit[a]+=b;
			bit[a]%=mod;
			a+=a&-a;
		}
	}
	ll sum(ll a)
	{
		ll ret=0;
		for(;;)
		{
			if(a==0)
			{
				break;
			}
			ret+=bit[a];
			ret%=mod;
			a-=a&-a;
		}
		return ret;
	}
};
BIT bi;
int main()
{
	int num;
	scanf("%d",&num);
	vector<ll>vec;
	for(int i=1;i<=1000000;i++)
	{
		dat[i].push_back(-1);
	}
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		dat[zan].push_back(i);
	}
	bi.add(1,1);
	for(ll i=1;i<=1000000;i++)
	{
		for(int j=1;j<dat[i].size();j++)
		{
			dp[dat[i][j]]=((bi.sum(dat[i][j]+1)-bi.sum(dat[i][j-1]+1))*i)%mod;
			bi.add(dat[i][j]+2,dp[dat[i][j]]);
		}
	}
	ll ret=0;
	for(int i=0;i<num;i++)
	{
		ret+=dp[i];
		ret%=mod;
	}
	printf("%I64d\n",(ret+mod)%mod);
}