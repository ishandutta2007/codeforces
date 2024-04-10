#include<stdio.h>
#include<vector>
#include<algorithm>
#define SIZE 262144
using namespace std;
class fortunetelling_tree
{
public:
	int seg[SIZE];
	int flip[SIZE];
	int update(int beg,int end,int node,int lb,int ub)
	{
		if(beg>ub||lb>end)
		{
			return seg[node];
		}
		if(beg<=lb&&ub<=end)
		{
			flip[node]^=1;
			return seg[node]=ub-lb+1-seg[node];
		}
		if(flip[node])
		{
			seg[node*2]=(ub-lb+1)/2-seg[node*2];
			flip[node*2]^=1;
			seg[node*2+1]=(ub-lb+1)/2-seg[node*2+1];
			flip[node*2+1]^=1;
		}
		flip[node]=0;
		return seg[node]=update(beg,end,node*2,lb,(lb+ub)/2)+update(beg,end,node*2+1,(lb+ub)/2+1,ub);
	}
	int sum(int beg,int end,int node,int lb,int ub)
	{
		if(beg>ub||lb>end)
		{
			return 0;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[node];
		}
		if(flip[node])
		{
			seg[node*2]=(ub-lb+1)/2-seg[node*2];
			flip[node*2]^=1;
			seg[node*2+1]=(ub-lb+1)/2-seg[node*2+1];
			flip[node*2+1]^=1;
		}
		flip[node]=0;
		return sum(beg,end,node*2,lb,(lb+ub)/2)+sum(beg,end,node*2+1,(lb+ub)/2+1,ub);
	}
};
vector<int>tobit(int a)
{
	vector<int>ret;
	for(int i=0;i<20;i++)
	{
		ret.push_back(a%2);
		a/=2;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
typedef long long ll;
fortunetelling_tree tree[20];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<20;i++)
	{
		fill(tree[i].seg,tree[i].seg+SIZE,0);
		fill(tree[i].flip,tree[i].flip+SIZE,0);
	}
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vector<int>zv=tobit(zan);
		for(int j=0;j<20;j++)
		{
			if(zv[j])
			{
				tree[j].update(i,i,1,0,SIZE/2-1);
			}
		}
	}
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(zan==1)
		{
			int za,zb;
			scanf("%d%d",&za,&zb);
			za--;
			zb--;
			ll ret=0;
			for(int j=0;j<20;j++)
			{
				ret*=2LL;
				ret+=tree[j].sum(za,zb,1,0,SIZE/2-1);
			}
			printf("%I64d\n",ret);
		}
		else
		{
			int za,zb,zc;
			scanf("%d%d%d",&za,&zb,&zc);
			za--;
			zb--;
			vector<int>zv=tobit(zc);
			for(int j=0;j<20;j++)
			{
				if(zv[j])
				{
					tree[j].update(za,zb,1,0,SIZE/2-1);
				}
			}
		}
	}
}