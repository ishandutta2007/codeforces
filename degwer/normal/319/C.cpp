#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef long double ld;
#define eps 1e-10
ll dp[100000];
int main()
{
	int num;
	scanf("%d",&num);
	vector<ll>va,vb;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		va.push_back(zan);
	}
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vb.push_back(zan);
	}
	dp[0]=0;
	vector<pii>sta;
	sta.push_back(make_pair(0,vb[0]));
	vector<ld>vec;
	for(int i=1;i<num;i++)
	{
		int low=lower_bound(vec.begin(),vec.end(),double(va[i])+eps)-vec.begin()-1;
		if(low==-1)
		{
			dp[i]=va[i]*vb[0];
		}
		else
		{
			dp[i]=sta[low+1].first+sta[low+1].second*va[i];
		}
		for(;;)
		{
			if(!vec.empty())
			{
				pii zan=sta[sta.size()-1];
				if(double(vec[vec.size()-1])-double(zan.first-dp[i])/double(vb[i]-zan.second)>eps)
				{
					vec.pop_back();
					sta.pop_back();
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		pii zan=sta[sta.size()-1];
		sta.push_back(make_pair(dp[i],vb[i]));
		vec.push_back(double(zan.first-dp[i])/double(vb[i]-zan.second));
	}
	printf("%I64d\n",dp[num-1]);
}