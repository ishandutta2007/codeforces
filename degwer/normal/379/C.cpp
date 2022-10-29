#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
ll ans[300000];
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(make_pair(zan,i));
	}
	sort(vec.begin(),vec.end());
	ans[vec[0].second]=vec[0].first;
	for(int i=1;i<num;i++)
	{
		vec[i].first=max(vec[i].first,vec[i-1].first+1);
		ans[vec[i].second]=vec[i].first;
	}
	for(int i=0;i<num;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%I64d",ans[i]);
	}
	printf("\n");
}