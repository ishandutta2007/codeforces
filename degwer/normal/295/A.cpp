#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<pii,ll>pi3;
ll kai[100001];
ll ans[100001];
ll pl[100000];
int main()
{
	int num,ope,query;
	scanf("%d%d%d",&num,&ope,&query);
	vector<pi3>vec;
	for(int i=0;i<num;i++)
	{
		scanf("%I64d",&pl[i]);
	}
	for(int i=0;i<ope;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		vec.push_back(make_pair(make_pair(za,zb),zc));
	}
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		kai[za]++;
		kai[zb+1]--;
	}
	for(int i=1;i<=ope;i++)
	{
		kai[i]+=kai[i-1];
	}
	for(int i=0;i<ope;i++)
	{
		ans[vec[i].first.first]+=vec[i].second*kai[i];
		ans[vec[i].first.second+1]-=vec[i].second*kai[i];
	}
	for(int i=1;i<=num;i++)
	{
		ans[i]+=ans[i-1];
	}
	for(int i=0;i<num;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%I64d",ans[i]+pl[i]);
	}
	printf("\n");
}