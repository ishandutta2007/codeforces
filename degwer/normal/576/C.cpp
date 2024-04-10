#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
vector<pi3>dat[1010];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		dat[za/1000].push_back(make_pair(make_pair(zb,za),i));
	}
	for(int i=0;i<=1001;i++)sort(dat[i].begin(),dat[i].end());
	vector<int>ans;
	for(int i=0;i<=1001;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<dat[i].size();j++)ans.push_back(dat[i][j].second);
		}
		else
		{
			for(int j=int(dat[i].size())-1;j>=0;j--)ans.push_back(dat[i][j].second);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",ans[i]+1);
	}
	printf("\n");
}