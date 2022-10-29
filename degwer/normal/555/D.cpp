#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
int g1[200002];
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	vector<ll>vec;
	vector<pii>zat;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
		zat.push_back(make_pair(zan,i+1));
	}
	vec.push_back(-1000000000000000LL);
	vec.push_back(1000000000000000LL);
	zat.push_back(make_pair(-1000000000000000LL,0));
	zat.push_back(make_pair(1000000000000000LL,num+1));
	sort(vec.begin(),vec.end());
	sort(zat.begin(),zat.end());
	for(int i=0;i<zat.size();i++)
	{
		g1[zat[i].second]=i;
	}
	for(int p=0;p<query;p++)
	{
		int now;
		ll len;
		scanf("%d%I64d",&now,&len);
		now=g1[now];
		for(;;)
		{
			int upp=upper_bound(vec.begin(),vec.end(),vec[now]+len)-vec.begin()-1;
			int nx=now;
			ll mn=0;
			if(upp>now)
			{
				nx=upp;
				mn=vec[upp]-vec[now];
			}
			int low=lower_bound(vec.begin(),vec.end(),vec[nx]-(len-mn))-vec.begin();
			if(low==now)
			{
				if(nx==now)
				{
					printf("%d\n",zat[now].second);
					break;
				}
				len%=2*(vec[nx]-vec[now]);
			}
			else
			{
				len-=(vec[nx]-vec[now])+(vec[nx]-vec[low]);
				now=low;
			}
		}
	}
}