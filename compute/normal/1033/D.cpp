#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const double eps=1e-9;
long long arr[505];
bool vis[505];
vector<int> factor[505];
map<long long,int> ans;
bool check(long long cur)
{
	long long sqr=round(sqrt(cur));
	if(sqr*sqr==cur)
	{
		if(round(sqrt(sqr))*round(sqrt(sqr))==sqr)
			ans[1LL*round(sqrt(sqr))]+=4;
		else ans[1LL*sqr]+=2;
		return 1;
	}
	else{
		long long cub=round(cbrt(cur));
		if(cub*cub*cub==cur) 
		{
			ans[1LL*cub]+=3;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(check(arr[i])) vis[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			long long gcd=__gcd(arr[i],arr[j]);
			if(gcd==arr[i]||gcd==1) continue;
			factor[i].push_back(gcd);factor[j].push_back(gcd);
		}
	}
	long long opt=1;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			if(factor[i].size()==0)
			{
				long long cnt=1;
				for(int j=i+1;j<n;j++)
				{
					if(vis[j]) continue;
					if(arr[i]==arr[j]) cnt++,vis[j]=1;
				}
				opt=(opt*(cnt+1)*(cnt+1))%mod;
			}
			else{
				ans[factor[i][0]]++,ans[arr[i]/factor[i][0]]++;
			}
		}
	}
	for(auto &p:ans) opt=opt*(p.second+1)%mod;
	printf("%lld\n",opt);

}