#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int>pii;
int pl[300002];
class BIT
{
public:
	int bit[524289];
	void add(int a,int b)
	{
		a++;
		for(;;)
		{
			if(a==524288)
			{
				break;
			}
			bit[a]+=b;
			a+=a&-a;
		}
	}
	int sum(int a)
	{
		a++;
		int ret=0;
		for(;;)
		{
			if(a==0)
			{
				break;
			}
			ret+=bit[a];
			a-=a&-a;
		}
		return ret;
	}
};
BIT bi;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	vec.push_back(0);
	pl[0]=0;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		pl[zan]=i+1;
	}
	vec.push_back(num+1);
	pl[num+1]=num+1;
	int now=0;
	set<int>se;
	bi.add(now,1);
	se.insert(0);
	for(int i=1;i<vec.size();i++)
	{
		if(pl[i]<pl[i-1])
		{
			now=i;
			bi.add(i,1);
			se.insert(i);
		}
	}
	int query;
	scanf("%d",&query);
	for(int p=0;p<query;p++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		if(za==1)
		{
			printf("%d\n",bi.sum(zc)-bi.sum(zb)+1);
		}
		else
		{
			swap(vec[zb],vec[zc]);
			swap(pl[vec[zb]],pl[vec[zc]]);
			if(pl[vec[zb]-1]<zb)
			{
				if(se.find(vec[zb])!=se.end())
				{
					bi.add(vec[zb],-1);
					se.erase(vec[zb]);
				}
			}
			else
			{
				if(se.find(vec[zb])==se.end())
				{
					bi.add(vec[zb],1);
					se.insert(vec[zb]);
				}
			}
			if(pl[vec[zc]-1]<zc)
			{
				if(se.find(vec[zc])!=se.end())
				{
					bi.add(vec[zc],-1);
					se.erase(vec[zc]);
				}
			}
			else
			{
				if(se.find(vec[zc])==se.end())
				{
					bi.add(vec[zc],1);
					se.insert(vec[zc]);
				}
			}
			if(pl[vec[zb]+1]>zb)
			{
				if(se.find(vec[zb]+1)!=se.end())
				{
					bi.add(vec[zb]+1,-1);
					se.erase(vec[zb]+1);
				}
			}
			else
			{
				if(se.find(vec[zb]+1)==se.end())
				{
					bi.add(vec[zb]+1,1);
					se.insert(vec[zb]+1);
				}
			}
			if(pl[vec[zc]+1]>zc)
			{
				if(se.find(vec[zc]+1)!=se.end())
				{
					bi.add(vec[zc]+1,-1);
					se.erase(vec[zc]+1);
				}
			}
			else
			{
				if(se.find(vec[zc]+1)==se.end())
				{
					bi.add(vec[zc]+1,1);
					se.insert(vec[zc]+1);
				}
			}
		}
	}
}