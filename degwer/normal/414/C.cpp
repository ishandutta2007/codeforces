#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1048576
typedef long long ll;
ll dat[21];
ll rdat[21];
bool flag[21];
vector<int>dfs(vector<int>v,int node,int siz,int dep)
{
	vector<int>ret;
	if(siz==1)
	{
		return v;
	}
	vector<int>v1,v2;
	for(int i=0;i<siz/2;i++)
	{
		v1.push_back(v[i]);
	}
	for(int i=siz/2;i<siz;i++)
	{
		v2.push_back(v[i]);
	}
	v1=dfs(v1,node*2,siz/2,dep-1);
	v2=dfs(v2,node*2+1,siz/2,dep-1);
	int pt1=0,pt2=0;
	for(;;)
	{
		if(pt1==siz/2&&pt2==siz/2)
		{
			break;
		}
		if(pt1==siz/2)
		{
			ret.push_back(v2[pt2]);
			pt2++;
		}
		else
		{
			if(pt2==siz/2)
			{
				ret.push_back(v1[pt1]);
				pt1++;
				dat[dep]+=pt2;
			}
			else
			{
				if(v1[pt1]<=v2[pt2])
				{
					ret.push_back(v1[pt1]);
					pt1++;
					dat[dep]+=pt2;
				}
				else
				{
					ret.push_back(v2[pt2]);
					pt2++;
				}
			}
		}
	}
	pt1=0;
	pt2=0;
	swap(v1,v2);
	for(;;)
	{
		if(pt1==siz/2&&pt2==siz/2)
		{
			break;
		}
		if(pt1==siz/2)
		{
			pt2++;
		}
		else
		{
			if(pt2==siz/2)
			{
				pt1++;
				rdat[dep]+=pt2;
			}
			else
			{
				if(v1[pt1]<=v2[pt2])
				{
					pt1++;
					rdat[dep]+=pt2;
				}
				else
				{
					pt2++;
				}
			}
		}
	}
	return ret;
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<(1<<num);i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	dfs(vec,1,(1<<num),num);
	int query;
	scanf("%d",&query);
	fill(flag,flag+21,true);
	for(int i=0;i<query;i++)
	{
		int zan;
		scanf("%d",&zan);
		for(int j=0;j<=zan;j++)
		{
			flag[j]=!flag[j];
		}
		ll ret=0;
		for(int j=0;j<=num;j++)
		{
			if(flag[j])
			{
				ret+=dat[j];
			}
			else
			{
				ret+=rdat[j];
			}
		}
		printf("%I64d\n",ret);
	}
}