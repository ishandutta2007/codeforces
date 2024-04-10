#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 131072
int data[30]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
class segtree
{
public:
	short segmax[SIZE*2];
	int segnum[SIZE*2];
	short flag[SIZE*2];
	int gval;
	inline void init(vector<int>vec)
	{
		for(int i=0;i<vec.size();i++)
		{
			segmax[i+SIZE]=vec[i];
		}
		for(int i=SIZE;i<SIZE*2;i++)
		{
			segnum[i]=1;
		}
		for(int i=SIZE-1;i>=1;i--)
		{
			int l=i+i,r=l+1;
			segmax[i]=max(segmax[l],segmax[r]);
			segnum[i]=segnum[l]*(segmax[i]==segmax[l])+segnum[r]*(segmax[i]==segmax[r]);
		}
	}
	inline void update(int beg,int end,int node,int lb,int ub,int num)
	{
		if(beg<=lb&&ub<=end)
		{
			segmax[node]+=num;
			flag[node]+=num;
			return;
		}
		int l=node+node,r=l+1;
		if(flag[node])
		{
			segmax[l]+=flag[node];
			segmax[r]+=flag[node];
			flag[l]+=flag[node];
			flag[r]+=flag[node];
			flag[node]=0;
		}
		if(beg<=(lb+ub)/2)
		{
			update(beg,end,l,lb,(lb+ub)/2,num);
		}
		if(end>=(lb+ub)/2+1)
		{
			update(beg,end,r,(lb+ub)/2+1,ub,num);
		}
		segmax[node]=max(segmax[l],segmax[r]);
		segnum[node]=segnum[l]*(segmax[node]==segmax[l])+segnum[r]*(segmax[node]==segmax[r]);
	}
	inline int get(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb||segmax[node]!=gval)
		{
			return 0;
		}
		if(beg<=lb&&ub<=end)
		{
			return segnum[node];
		}
		int l=node+node,r=l+1;
		if(flag[node])
		{
			segmax[l]+=flag[node];
			segmax[r]+=flag[node];
			flag[l]+=flag[node];
			flag[r]+=flag[node];
			flag[node]=0;
		}
		return get(beg,end,l,lb,(lb+ub)/2)+get(beg,end,r,(lb+ub)/2+1,ub);
	}
	inline void kill(int node)
	{
		if(node>=SIZE)
		{
			segmax[node]=-20000;
			return;
		}
		int l=node*2,r=node*2+1;
		if(flag[node])
		{
			segmax[l]+=flag[node];
			segmax[r]+=flag[node];
			flag[l]+=flag[node];
			flag[r]+=flag[node];
			flag[node]=0;
		}
		if(segmax[l]>gval)
		{
			kill(l);
		}
		if(segmax[r]>gval)
		{
			kill(r);
		}
		segmax[node]=max(segmax[l],segmax[r]);
		segnum[node]=segnum[l]*(segmax[node]==segmax[l])+segnum[r]*(segmax[node]==segmax[r]);
	}
};
segtree tree[30];
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	for(int i=0;i<30;i++)
	{
		tree[i].gval=data[i];
		tree[i].init(vec);
	}
	for(int p=0;p<query;p++)
	{
		char tp,gav;
		scanf(" %c",&tp);
		if(tp=='a')
		{
			int za,zb,zc;
			scanf("%c%c%d%d%d",&gav,&gav,&za,&zb,&zc);
			za--;
			zb--;
			for(int i=0;i<30;i++)
			{
				tree[i].update(za,zb,1,0,SIZE-1,zc);
			}
		}
		else
		{
			int za,zb;
			scanf("%c%c%c%c%d%d",&gav,&gav,&gav,&gav,&za,&zb);
			za--;
			zb--;
			int sum=0;
			for(int i=0;i<30;i++)
			{
				if(tree[i].segmax[1]>data[i])
				{
					tree[i].kill(1);
				}
				sum+=tree[i].get(za,zb,1,0,SIZE-1);
			}
			printf("%d\n",sum);
		}
	}
}