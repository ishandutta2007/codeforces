#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int>pii;
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	vector<pii>vec;
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		vec.push_back(make_pair(za*a+zb*b,i+1));
	}
	sort(vec.begin(),vec.end());
	ll sum=0;
	vector<int>ans;
	for(int i=0;i<num;i++)
	{
		sum+=vec[i].first;
		if(sum>gen)
		{
			break;
		}
		ans.push_back(vec[i].second);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	printf("\n");
}