#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef pair<int,int>pii;
int gcd(int a,int b)
{
	for(;;)
	{
		if(a<b)swap(a,b);
		a%=b;
		if(a==0)return b;
	}
}
map<int,int>dp[301];
set<int>se[301];
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(make_pair(zan,0));
	}
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec[i].second=zan;
	}
	for(int i=0;i<num;i++)
	{
		map<int,int>::iterator it=dp[i].begin();
		dp[i+1]=dp[i];
		if(dp[i+1][vec[i].first]==0)dp[i+1][vec[i].first]=vec[i].second;
		else dp[i+1][vec[i].first]=min(dp[i+1][vec[i].first],vec[i].second);
		for(;;)
		{
			if(it==dp[i].end())break;
			pii zan=*it;
			it++;
			if(dp[i+1][gcd(vec[i].first,zan.first)]==0)dp[i+1][gcd(vec[i].first,zan.first)]=zan.second+vec[i].second;
			else dp[i+1][gcd(vec[i].first,zan.first)]=min(dp[i+1][gcd(vec[i].first,zan.first)],zan.second+vec[i].second);
		}
	}
	if(dp[num][1]==0)printf("-1\n");
	else printf("%d\n",dp[num][1]);
}