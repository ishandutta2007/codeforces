#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	if(num==1||num%2==0)
	{
		printf("-1\n");
		return 0;
	}
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	int ret=0;
	for(int i=num-1;i>=2;i-=2)
	{
		int dis=max(vec[i],vec[i-1]);
		ret+=dis;
		vec[i]=max(0,vec[i]-dis);
		vec[i-1]=max(0,vec[i-1]-dis);
		vec[i/2-1]=max(0,vec[i/2-1]-dis);
	}
	ret+=vec[0];
	printf("%d\n",ret);
}