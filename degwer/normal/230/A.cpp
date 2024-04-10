#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
int main()
{
	int tai,num;
	scanf("%d%d",&tai,&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		vec.push_back(make_pair(za,zb));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<num;i++)
	{
		if(vec[i].first>=tai)
		{
			printf("NO\n");
			return 0;
		}
		tai+=vec[i].second;
	}
	printf("YES\n");
}