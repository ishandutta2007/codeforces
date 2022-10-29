#include<stdio.h>
#include<vector>
using namespace std;
double eps=0.000000001;
int main()
{
	int nin;
	double dri;
	scanf("%d%lf",&nin,&dri);
	double sum=dri;
	vector<int>vec;
	for(int i=0;i<nin;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		sum+=zan;
	}
	sum/=nin;
	vector<double>ans;
	for(int j=0;j<nin;j++)
	{
		if(sum+eps<vec[j])
		{
			printf("-1\n");
			return 0;
		}
		ans.push_back(sum-vec[j]);
	}
	for(int k=0;k<nin;k++)
	{
		printf("%.10lf\n",ans[k]);
	}
}