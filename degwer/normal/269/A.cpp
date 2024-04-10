#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<ll,pii>pi3;
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		ll za,zb;
		scanf("%I64d%I64d",&za,&zb);
		vec.push_back(make_pair(za,zb));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<num-1;i++)
	{
		for(ll j=vec[i].first+1;j<=vec[i+1].first;j++)
		{
			vec[i].second=(vec[i].second+3)/4;
			if(vec[i].second==1)
			{
				break;
			}
		}
		vec[i+1].second=max(vec[i+1].second,vec[i].second);
	}
	ll ans=vec[num-1].first,now=vec[num-1].second;
	for(;;)
	{
		ans++;
		now=(now+3)/4;
		if(now==1)
		{
			printf("%I64d\n",ans);
			break;
		}
	}
}