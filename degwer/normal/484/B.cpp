#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int ans[1000001];
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
	sort(vec.begin(),vec.end());
	fill(ans,ans+1000001,-1);
	int maxi=0;
	for(int i=0;i<num;i++)
	{
		if(ans[vec[i]]!=-1)continue;
		for(int j=vec[i]*2;;j+=vec[i])
		{
			if(j-vec[i]>1000000)break;
			int low=lower_bound(vec.begin(),vec.end(),j)-vec.begin()-1;
			if(low<0)continue;
			if(vec[low]-j+vec[i]>=vec[i])continue;
			if(vec[low]<vec[i])continue;
			maxi=max(maxi,vec[low]-j+vec[i]);
			ans[vec[i]]=0;
		}
	}
	printf("%d\n",maxi);
}