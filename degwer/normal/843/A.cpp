#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool flag[100000];
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>v;
	vector<int>zv;
	for(int i=0;i<num;i++)
	{
		int z;
		scanf("%d",&z);
		v.push_back(z);
		zv.push_back(z);
	}
	sort(zv.begin(),zv.end());
	for(int i=0;i<num;i++)v[i]=lower_bound(zv.begin(),zv.end(),v[i])-zv.begin();
	vector<vector<int> >ans;
	for(int i=0;i<num;i++)
	{
		if(flag[i])continue;
		vector<int>r;
		int n=i;
		for(;;)
		{
			r.push_back(n);
			flag[n]=true;
			n=v[n];
			if(n==i)break;
		}
		ans.push_back(r);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d",ans[i].size());
		for(int j=0;j<ans[i].size();j++)printf(" %d",ans[i][j]+1);
		printf("\n");
	}
}