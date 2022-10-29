#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>f(vector<int>vec,vector<int>mov)
{
	vector<int>ret;
	ret.resize(vec.size());
	for(int i=0;i<vec.size();i++)
	{
		ret[i]=vec[mov[i]];
	}
	return ret;
}
vector<int>invf(vector<int>vec,vector<int>mov)
{
	vector<int>ret;
	ret.resize(vec.size());
	for(int i=0;i<vec.size();i++)
	{
		ret[mov[i]]=vec[i];
	}
	return ret;
}
void vecprint(vector<int>a)
{
	for(int i=0;i<a.size();i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int num,dou;
	scanf("%d%d",&num,&dou);
	vector<int>mov,mok,vec1,vec2;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		mov.push_back(zan-1);
	}
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		mok.push_back(zan-1);
		vec1.push_back(i);
	}
	vec2=vec1;
	int left=-1,right=-1;
	for(int i=0;i<=dou;i++)
	{
		if(vec1==mok)
		{
			left=i;
			break;
		}
		vec1=f(vec1,mov);
	}
	for(int i=0;i<=dou;i++)
	{
		if(vec2==mok)
		{
			right=i;
			break;
		}
		vec2=invf(vec2,mov);
	}
	if(left==0||right==0)
	{
		printf("NO\n");
		return 0;
	}
	if(left==1&&right==1)
	{
		if(dou!=1)
		{
			printf("NO\n");
			return 0;
		}
		else
		{
			printf("YES\n");
			return 0;
		}
	}
	if(left%2!=dou%2&&right%2!=dou%2)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
}