#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int mark,cap;
	scanf("%d%d",&mark,&cap);
	vector<pair<int,int> >hm;
	vector<pair<int,int> >cm;
	for(int i=1;i<=mark;i++)
	{
		pair<int,int>zan;
		scanf("%d%d",&zan.second,&zan.first);
		hm.push_back(zan);
	}
	sort(hm.begin(),hm.end());
	for(int i=1;i<=cap;i++)
	{
		pair<int,int>zan;
		scanf("%d%d",&zan.second,&zan.first);
		cm.push_back(zan);
	}
	sort(cm.begin(),cm.end());
	int ret1=0;
	int ret2=0;
	pair<int,int>now=make_pair(-1,-1);
	for(int j=1;j<=mark;j++)
	{
		if(now.first!=hm[j-1].first)
		{
			int upp1=upper_bound(cm.begin(),cm.end(),make_pair(hm[j-1].first,10000000))-cm.begin();
			int low1=lower_bound(cm.begin(),cm.end(),make_pair(hm[j-1].first,0))-cm.begin();
			int upp2=upper_bound(hm.begin(),hm.end(),make_pair(hm[j-1].first,10000000))-hm.begin();
			int low2=lower_bound(hm.begin(),hm.end(),make_pair(hm[j-1].first,0))-hm.begin();
			ret1+=min(upp1-low1,upp2-low2);
		}
		if(now!=hm[j-1])
		{
			int upp1=upper_bound(cm.begin(),cm.end(),hm[j-1])-cm.begin();
			int low1=lower_bound(cm.begin(),cm.end(),hm[j-1])-cm.begin();
			int upp2=upper_bound(hm.begin(),hm.end(),hm[j-1])-hm.begin();
			int low2=lower_bound(hm.begin(),hm.end(),hm[j-1])-hm.begin();
			ret2+=min(upp1-low1,upp2-low2);
		}
		now=hm[j-1];
	}
	printf("%d %d\n",ret1,ret2);
}