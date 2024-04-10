#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	ll sum=0;
	for(int i=0;i<num;i++)
	{
		ll upp=upper_bound(vec.begin(),vec.end(),vec[i]+gen)-vec.begin()-1;
		upp-=i;
		sum+=upp*(upp-1)/2;
	}
	printf("%I64d\n",sum);
}