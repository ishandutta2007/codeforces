#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 524288
class segtree1
{
public:
	int seg[SIZE*2];
	int flag[SIZE*2];
	void update(int beg,int end,int node,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return;
		}
		if(beg<=lb&&ub<=end)
		{
			seg[node]=num;
			flag[node]=num;
			return;
		}
		if(flag[node])
		{
			flag[node*2]=flag[node];
			flag[node*2+1]=flag[node];
			seg[node*2]=flag[node];
			seg[node*2+1]=flag[node];
			flag[node]=0;
		}
		update(beg,end,node*2,lb,(lb+ub)/2,num);
		update(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
	}
	int get(int pl,int node,int lb,int ub)
	{
		if(pl==lb&&pl==ub)
		{
			return seg[node];
		}
		if(flag[node])
		{
			flag[node*2]=flag[node];
			flag[node*2+1]=flag[node];
			seg[node*2]=flag[node];
			seg[node*2+1]=flag[node];
			flag[node]=0;
		}
		if(pl<=(lb+ub)/2)
		{
			return get(pl,node*2,lb,(lb+ub)/2);
		}
		else
		{
			return get(pl,node*2+1,(lb+ub)/2+1,ub);
		}
	}
};
class segtree2
{
public:
	int seg[SIZE*2];
	void update(int a,int b)
	{
		a+=SIZE;
		seg[a]=b;
		for(;;)
		{
			a/=2;
			if(a==0)
			{
				break;
			}
			seg[a]=max(seg[a*2],seg[a*2+1]);
		}
	}
	int get(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return 0;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[node];
		}
		return max(get(beg,end,node*2,lb,(lb+ub)/2),get(beg,end,node*2+1,(lb+ub)/2+1,ub));
	}
};
segtree1 tree1;
segtree2 tree2;
vector<int>pat[500000];
vector<int>ko[500000];
vector<int>eul;
bool flag[500000];
int ord[500000];
int fin[500000];
int pto=0,ptf=0;
void dfs(int node)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	eul.push_back(node);
	ord[node]=pto++;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
	fin[node]=pto-1;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num-1;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	fill(flag,flag+num,false);
	dfs(0);
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		zb--;
		if(za==1)
		{
			tree1.update(ord[zb],fin[zb],1,0,SIZE-1,i+1);
		}
		if(za==2)
		{
			tree2.update(ord[zb],i+1);
		}
		if(za==3)
		{
			int a=tree1.get(ord[zb],1,0,SIZE-1);
			int b=tree2.get(ord[zb],fin[zb],1,0,SIZE-1);
			if(a==0||a<b)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
	}
}