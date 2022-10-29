#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
using namespace std;
ll dp[1000001];
typedef pair<int,int>pii;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	vector<int>imp;
	imp.push_back(0);
	for(int i=1;i<num-1;i++)
	{
		if((vec[i]>=vec[i-1]&&vec[i]>=vec[i+1])||(vec[i]<=vec[i-1]&&vec[i]<=vec[i+1]))imp.push_back(i);
	}
	imp.push_back(num-1);
	vector<pii>quer;
	for(int i=0;i<imp.size()-1;i++)
	{
		quer.push_back(make_pair(imp[i]+1,imp[i+1]));
		quer.push_back(make_pair(imp[i]+1,imp[i+1]+1));
		quer.push_back(make_pair(imp[i]+2,imp[i+1]));
		quer.push_back(make_pair(imp[i]+2,imp[i+1]+1));
	}
	for(int i=0;i<quer.size();i++)
	{
		if(quer[i].first>quer[i].second)continue;
		dp[quer[i].second]=max(dp[quer[i].second],dp[quer[i].first-1]+abs(vec[quer[i].first-1]-vec[quer[i].second-1]));
	}
	printf("%I64d\n",dp[num]);
}