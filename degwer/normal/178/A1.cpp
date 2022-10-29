#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d",&num);
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
	}
	vector<ll>rui;
	ll now=1;
	for(int j=0;j<60;j++)
	{
		rui.push_back(now);
		now*=2;
	}
	ll ret=0;
	for(int k=0;k<num-1;k++)
	{
		int low=upper_bound(rui.begin(),rui.end(),num-k-1)-rui.begin()-1;
		ret+=vec[k];
		vec[k+rui[low]]+=vec[k];
		vec[k]=0;
		printf("%I64d\n",ret);
	}
}