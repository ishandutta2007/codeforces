#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
vector<ll>v[200000];
int main()
{
	int num;
	ll mod;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(make_pair(zan,i));
	}
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(make_pair(zan,i));
	}
	scanf("%I64d",&mod);
	sort(vec.begin(),vec.end());
	ll now=vec[0].first;
	int pt=0;
	for(int i=0;i<vec.size();i++)
	{
		if(now!=vec[i].first)
		{
			now=vec[i].first;
			pt++;
			v[pt].push_back(vec[i].second);
		}
		else
		{
			v[pt].push_back(vec[i].second);
		}
	}
	ll ans=1;
	for(int i=0;i<vec.size();i++)
	{
		if(v[i].empty())
		{
			break;
		}
		sort(v[i].begin(),v[i].end());
		int d=0;
		for(int j=0;j<v[i].size()-1;j++)
		{
			if(v[i][j]==v[i][j+1])
			{
				d++;
			}
		}
		ll nowtim=v[i].size();
		for(int j=0;j<v[i].size()-2*d;j++)
		{
			ans*=nowtim;
			ans%=mod;
			nowtim--;
		}
		for(int j=0;j<d;j++)
		{
			ll tim=(nowtim*(nowtim-1)/2)%mod;
			ans*=tim;
			ans%=mod;
			nowtim-=2;
		}
	}
	printf("%I64d\n",ans);
}