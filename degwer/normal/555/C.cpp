#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define SIZE 262144
class segtree
{
public:
	int flag[SIZE*2];
	void update(int beg,int end,int node,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)return;
		if(beg<=lb&&ub<=end)
		{
			flag[node]=max(flag[node],num);
			return;
		}
		if(flag[node])
		{
			flag[node*2]=max(flag[node*2],flag[node]);
			flag[node*2+1]=max(flag[node*2+1],flag[node]);
			flag[node]=0;
		}
		update(beg,end,node*2,lb,(lb+ub)/2,num);
		update(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
	}
	int get(int pl,int node,int lb,int ub)
	{
		if(ub<pl||pl<lb)return 0;
		if(pl==lb&&pl==ub)return flag[node];
		if(flag[node])
		{
			flag[node*2]=max(flag[node*2],flag[node]);
			flag[node*2+1]=max(flag[node*2+1],flag[node]);
			flag[node]=0;
		}
		return max(get(pl,node*2,lb,(lb+ub)/2),get(pl,node*2+1,(lb+ub)/2+1,ub));
	}
};
vector<int>uni(vector<int>v)
{
	int now=-1;
	vector<int>ret;
	for(int i=0;i<v.size();i++)
	{
		if(now!=v[i])
		{
			now=v[i];
			ret.push_back(now);
		}
	}
	return ret;
}
segtree t1,t2;
typedef pair<int,int>pii;
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	vector<int>zx,zy;
	vector<pii>vec;
	for(int i=0;i<query;i++)
	{
		int za,zb;
		char zc;
		scanf("%d%d %c",&za,&zb,&zc);
		zx.push_back(za);
		zy.push_back(zb);
		if(zc=='U')vec.push_back(make_pair(za,0));
		else vec.push_back(make_pair(za,1));
	}
	sort(zx.begin(),zx.end());
	sort(zy.begin(),zy.end());
	zx=uni(zx);
	zy=uni(zy);
	set<int>se1,se2;
	for(int p=0;p<query;p++)
	{
		if(vec[p].second==0)
		{
			if(se1.find(vec[p].first)!=se1.end())
			{
				printf("0\n");
				continue;
			}
			se1.insert(vec[p].first);
			int low=lower_bound(zx.begin(),zx.end(),vec[p].first)-zx.begin();
			int g=t2.get(low,1,0,SIZE-1);
			printf("%d\n",(num+1-vec[p].first)-g);
			int low2=lower_bound(zy.begin(),zy.end(),g)-zy.begin();
			int low3=lower_bound(zy.begin(),zy.end(),num+1-vec[p].first)-zy.begin();
			t1.update(low2,low3,1,0,SIZE-1,vec[p].first);
		}
		else
		{
			if(se2.find(vec[p].first)!=se2.end())
			{
				printf("0\n");
				continue;
			}
			se2.insert(vec[p].first);
			int low=lower_bound(zy.begin(),zy.end(),num+1-vec[p].first)-zy.begin();
			int g=t1.get(low,1,0,SIZE-1);
			printf("%d\n",vec[p].first-g);
			int low2=lower_bound(zx.begin(),zx.end(),g)-zx.begin();
			int low3=lower_bound(zx.begin(),zx.end(),vec[p].first)-zx.begin();
			t2.update(low2,low3,1,0,SIZE-1,num+1-vec[p].first);
		}
	}
}