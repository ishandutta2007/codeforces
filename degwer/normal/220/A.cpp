#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	vector<int>rem;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		rem.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	int ret=0;
	for(int i=0;i<num;i++)
	{
		if(rem[i]!=vec[i])
		{
			ret++;
		}
	}
	if(ret<=2)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}