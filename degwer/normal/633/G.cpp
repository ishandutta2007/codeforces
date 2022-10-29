#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
#define SIZE 131072
int mod;
class segtree
{
public:
	bitset<1024>seg[SIZE*2];
	int flag[SIZE*2];
	bitset<1024>al1;
	bitset<1024>al0;
	void init(vector<int>vec)
	{
		for(int i=0;i<mod;i++)al1[i]=true;
		for(int i=0;i<vec.size();i++)seg[i+SIZE][vec[i]%mod]=true;
		for(int i=SIZE-1;i>=1;i--)seg[i]=seg[i*2]|seg[i*2+1];
	}
	void update(int beg,int end,int node,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)return;
		if(beg<=lb&&ub<=end)
		{
			seg[node]=((seg[node]<<(num%mod))|(seg[node]>>(mod-num%mod)))&al1;
			flag[node]=(flag[node]+num)%mod;
			return;
		}
		if(flag[node])
		{
			seg[node*2]=((seg[node*2]<<(flag[node]))|(seg[node*2]>>(mod-flag[node])))&al1;
			seg[node*2+1]=((seg[node*2+1]<<(flag[node]))|(seg[node*2+1]>>(mod-flag[node])))&al1;
			flag[node*2]=(flag[node*2]+flag[node])%mod;
			flag[node*2+1]=(flag[node*2+1]+flag[node])%mod;
			flag[node]=0;
		}
		update(beg,end,node*2,lb,(lb+ub)/2,num);update(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
		seg[node]=seg[node*2]|seg[node*2+1];
	}
	bitset<1024>get(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb)return al0;
		if(beg<=lb&&ub<=end)
		{
			return seg[node];
		}
		if(flag[node])
		{
			seg[node*2]=((seg[node*2]<<(flag[node]))|(seg[node*2]>>(mod-flag[node])))&al1;
			seg[node*2+1]=((seg[node*2+1]<<(flag[node]))|(seg[node*2+1]>>(mod-flag[node])))&al1;
			flag[node*2]=(flag[node*2]+flag[node])%mod;
			flag[node*2+1]=(flag[node*2+1]+flag[node])%mod;
			flag[node]=0;
		}
		return get(beg,end,node*2,lb,(lb+ub)/2)|get(beg,end,node*2+1,(lb+ub)/2+1,ub);
	}
};
segtree tree;
vector<int>pat[100000];
int ord[100000];
int fin[100000];
int ordpt=0;
bool flag[100000];
int dat[100000];
void dfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	ord[node]=ordpt++;
	for(int i=0;i<pat[node].size();i++)
	{
		dfs(pat[node][i]);
	}
	fin[node]=ordpt-1;
}
int main()
{
	int num;
	scanf("%d%d",&num,&mod);
	for(int i=0;i<num;i++)
	{
		int z;
		scanf("%d",&z);
		dat[i]=z;
	}
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
	bitset<1024>ans;
	vector<int>pr;
	for(int i=2;i<1024;i++)
	{
		bool f=true;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)f=false;
		}
		if(f)
		{
			ans[i]=true;
			pr.push_back(i);
		}
	}
	vector<int>v;
	v.resize(num);
	for(int i=0;i<num;i++)
	{
		v[ord[i]]=dat[i];
	}
	int query;
	scanf("%d",&query);
	tree.init(v);
	for(int p=0;p<query;p++)
	{
		int z;
		scanf("%d",&z);
		if(z==1)
		{
			int za,zb;
			scanf("%d%d",&za,&zb);
			za--;
			tree.update(ord[za],fin[za],1,0,SIZE-1,zb);
		}
		else
		{
			int za;
			scanf("%d",&za);
			za--;
			bitset<1024>a=ans&tree.get(ord[za],fin[za],1,0,SIZE-1);
			int c=0;
			//for(int i=0;i<mod;i++)printf("%d",int(a[i]));printf("\n");
			for(int i=0;i<pr.size();i++)c+=a[pr[i]];
			printf("%d\n",c);
		}
	}
}