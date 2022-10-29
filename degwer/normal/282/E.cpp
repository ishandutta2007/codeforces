#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define SIZE (1LL<<40LL)
class segtree
{
public:
	int seg[10000000];
	ll lko[10000000];
	ll rko[10000000];
	int pt;
	void init()
	{
		fill(seg,seg+10000000,0);
		fill(lko,lko+10000000,-1);
		fill(rko,rko+10000000,-1);
		pt=1;
	}
	void update(ll pl,int node,ll lb,ll ub,int num)
	{
		if(pl<lb||ub<pl)
		{
			return;
		}
		if(lb<=pl&&pl<=ub)
		{
			seg[node]+=num;
		}
		if(lb==ub)
		{
			return;
		}
		if(lko[node]==-1)
		{
			lko[node]=pt++;
		}
		if(rko[node]==-1)
		{
			rko[node]=pt++;
		}
		update(pl,lko[node],lb,(lb+ub)/2,num);
		update(pl,rko[node],(lb+ub)/2+1,ub,num);
	}
	ll calc(int node,ll lb,ll ub,int depth,ll num)
	{
		if(seg[node]==0)
		{
			return -1;
		}
		if(lb==ub)
		{
			return lb;
		}
		if(((num>>(depth-1))&1LL)==1)
		{
			if(seg[lko[node]]!=0)
			{
				return calc(lko[node],lb,(lb+ub)/2,depth-1,num);
			}
			else
			{
				return calc(rko[node],(lb+ub)/2+1,ub,depth-1,num);
			}
		}
		else
		{
			if(seg[rko[node]]!=0)
			{
				return calc(rko[node],(lb+ub)/2+1,ub,depth-1,num);
			}
			else
			{
				return calc(lko[node],lb,(lb+ub)/2,depth-1,num);
			}
		}
	}
};
segtree tree;
int main()
{
	tree.init();
	int num;
	scanf("%d",&num);
	vector<ll>vec;
	vec.push_back(0);
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
	}
	vec.push_back(0);
	ll now=0;
	vector<ll>pushed;
	for(int i=vec.size()-1;i>=0;i--)
	{
		now^=vec[i];
		tree.update(now,0,0,SIZE-1,1);
		pushed.push_back(now);
	}
	ll maxi=0;
	now=0;
	for(int i=0;i<vec.size()-1;i++)
	{
		now^=vec[i];
		tree.update(pushed[pushed.size()-1],0,0,SIZE-1,-1);
		pushed.pop_back();
		maxi=max(maxi,now^tree.calc(0,0,SIZE-1,40,now));
	}
	printf("%I64d\n",maxi);
}