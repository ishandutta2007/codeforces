#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	vector<int>vec;
	for(int i=1;i<=a;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	printf("%d\n",vec[c]-vec[c-1]);
}