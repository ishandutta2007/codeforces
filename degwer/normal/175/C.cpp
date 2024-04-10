#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d",&num);
	vector<pair<ll,ll> >vec;
	for(int i=0;i<num;i++)
	{
		ll za,zb;
		scanf("%I64d%I64d",&za,&zb);
		vec.push_back(make_pair(zb,za));
	}
	sort(vec.begin(),vec.end());
	int hen;
	scanf("%d",&hen);
	vector<ll>bin;
	for(int j=0;j<hen;j++)
	{
		ll zan;
		scanf("%I64d",&zan);
		bin.push_back(zan);
	}
	vector<pair<pair<ll,ll>,int> >map;
	ll now=0;
	for(int k=0;k<num;k++)
	{
		map.push_back(make_pair(make_pair(now,vec[k].first),0));
		now+=vec[k].second;
	}
	for(int l=0;l<hen;l++)
	{
		map.push_back(make_pair(make_pair(bin[l],l+2),1));
	}
	map.push_back(make_pair(make_pair(now,0),2));
	sort(map.begin(),map.end());
	ll bon=1;
	ll zen=0;
	ll sum=0;
	ll ho=0;
	for(int m=0;m<map.size();m++)
	{
		if(map[m].second==0)
		{
			sum+=bon*(map[m].first.first-zen)*ho;
			ho=map[m].first.second;
		}
		if(map[m].second==1)
		{
			sum+=bon*(map[m].first.first-zen)*ho;
			bon++;
		}
		if(map[m].second==2)
		{
			sum+=bon*(map[m].first.first-zen)*ho;
			break;
		}
		zen=map[m].first.first;
	}
	printf("%I64d\n",sum);
}