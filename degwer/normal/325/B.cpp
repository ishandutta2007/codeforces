#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
int main()
{
	ll z;
	scanf("%I64d",&z);
	vector<ll>ans;
	for(int i=0;i<=62;i++)
	{
		ll beg=0,end=max((1LL<<(min(62-i,32)))-1,1LL);
		for(;;)
		{
			ll med=(beg+end)/2;
			if(med*((med-3)/2+(1LL<<i))<z)
			{
				beg=med+1;
			}
			else
			{
				end=med;
			}
			if(beg==end)
			{
				if(beg*((beg-3)/2+(1LL<<i))==z&&beg%2==1)
				{
					ans.push_back(beg*(1LL<<i));
				}
				break;
			}
		}
	}
	sort(ans.begin(),ans.end());
	if(ans.empty())
	{
		printf("-1\n");
	}
	else
	{
		for(int i=0;i<ans.size();i++)
		{
			printf("%I64d\n",ans[i]);
		}
	}
}