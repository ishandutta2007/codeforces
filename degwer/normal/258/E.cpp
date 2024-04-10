#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#define SIZE 131072
using namespace std;
typedef pair<int,int>pii;
vector<int>pat[100000];
vector<int>ko[100000];
int ban[100000];
bool flag[100000];
vector<int>topo;
int ans[100000];
int to[100000];
vector<pii>dat[100000];
int now=0;
class segtree
{
public:
	int segmin[SIZE*2];
	int segnum[SIZE*2];
	int flag[SIZE*2];
	void init()
	{
		fill(flag,flag+SIZE*2,0);
		for(int i=0;i<SIZE;i++)
		{
			segmin[i+SIZE]=0;
			segnum[i+SIZE]=1;
		}
		for(int i=SIZE-1;i>=1;i--)
		{
			segmin[i]=0;
			segnum[i]=segnum[i*2]+segnum[i*2+1];
		}
	}
	void update(int beg,int end,int node,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return;
		}
		if(beg<=lb&&ub<=end)
		{
			segmin[node]+=num;
			flag[node]+=num;
			return;
		}
		if(flag[node])
		{
			flag[node*2+1]+=flag[node];
			flag[node*2]+=flag[node];
			segmin[node*2]+=flag[node];
			segmin[node*2+1]+=flag[node];
			flag[node]=0;
		}
		update(beg,end,node*2,lb,(lb+ub)/2,num);
		update(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
		segmin[node]=min(segmin[node*2],segmin[node*2+1]);
		if(segmin[node*2]==segmin[node*2+1])
		{
			segnum[node]=segnum[node*2]+segnum[node*2+1];
		}
		else
		{
			if(segmin[node*2]==segmin[node])
			{
				segnum[node]=segnum[node*2];
			}
			else
			{
				segnum[node]=segnum[node*2+1];
			}
		}
	}
};
segtree tree;
void dfs(int node)
{
	if(flag[node])
	{
		return;
	}
	ban[node]=topo.size();
	topo.push_back(node);
	flag[node]=true;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			dfs(pat[node][i]);
			ko[node].push_back(pat[node][i]);
		}
	}
	to[node]=topo.size()-1;
}
void calc(int node)
{
	for(int i=0;i<dat[node].size();i++)
	{
		tree.update(dat[node][i].first,dat[node][i].second,1,0,SIZE-1,1);
	}
	ans[node]=SIZE-tree.segnum[1];
	for(int i=0;i<ko[node].size();i++)
	{
		calc(ko[node][i]);
	}
	for(int i=0;i<dat[node].size();i++)
	{
		tree.update(dat[node][i].first,dat[node][i].second,1,0,SIZE-1,-1);
	}
}
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	for(int i=0;i<num-1;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	tree.init();
	fill(flag,flag+num,false);
	dfs(0);
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		dat[za].push_back(make_pair(ban[za],to[za]));
		dat[za].push_back(make_pair(ban[zb],to[zb]));
		dat[zb].push_back(make_pair(ban[za],to[za]));
		dat[zb].push_back(make_pair(ban[zb],to[zb]));
	}
	calc(0);
	for(int i=0;i<num;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",max(0,ans[i]-1));
	}
	printf("\n");
}