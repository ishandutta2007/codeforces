#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int exi(vector<int>vec,int fin)
{
	for(int i=0;i<vec.size();i++)
	{
		int low=lower_bound(vec.begin(),vec.end(),vec[i]+fin)-vec.begin();
		if(low!=vec.size())
		{
			if(vec[low]==vec[i]+fin)
			{
				return vec[i];
			}
		}
	}
	return -1;
}
int exi2(vector<int>vec,int x,int y,int len)
{
	for(int i=0;i<vec.size();i++)
	{
		int low=lower_bound(vec.begin(),vec.end(),vec[i]+y-x)-vec.begin();
		if(low!=vec.size())
		{
			if(vec[low]==vec[i]+y-x)
			{
				if(vec[i]+y<=len)
				{
					return vec[i]+y;
				}
				if(vec[i]-x>=0)
				{
					return vec[i]-x;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int num,len,x,y;
	scanf("%d%d%d%d",&num,&len,&x,&y);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	int ex=exi(vec,x),ey=exi(vec,y),exy=exi(vec,x+y);
	if(ex>=0&&ey>=0)
	{
		printf("0\n");
		return 0;
	}
	if(ex>=0)
	{
		printf("1\n%d\n",y);
		return 0;
	}
	if(ey>=0)
	{
		printf("1\n%d\n",x);
		return 0;
	}
	if(exy>=0)
	{
		printf("1\n%d\n",exy+x);
		return 0;
	}
	int e=exi2(vec,x,y,len);
	if(e>=0)
	{
		printf("1\n%d\n",e);
		return 0;
	}
	printf("2\n%d %d\n",x,y);
}