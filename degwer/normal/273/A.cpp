#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num,query;
	scanf("%d",&num);
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
	}
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		ll za,zb;
		scanf("%I64d%I64d",&za,&zb);
		ll maxi=max(vec[0],vec[za-1]);
		printf("%I64d\n",maxi);
		vec[0]=maxi+zb;
	}
}