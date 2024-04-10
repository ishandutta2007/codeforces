#include<stdio.h>
#include<vector>
#include<algorithm>
#define SIZE 131072
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll powsum[SIZE+1][6];
void calcpow()
{
	ll now[6];
	fill(now,now+6,0);
	for(int i=1;i<=SIZE;i++)
	{
		ll pl=1;
		powsum[i][0]=i;
		for(int j=1;j<=5;j++)
		{
			pl=pl*i%mod;
			now[j]=(now[j]+pl)%mod;
			powsum[i][j]=now[j];
		}
	}
}
class segtree
{
public:
	vector<vector<ll> >seg;
	ll flag[SIZE*2];
	ll tim(ll a,ll b,ll c)
	{
		return (((a*b)%mod)*c)%mod;
	}
	vector<ll>unite(vector<ll>a,vector<ll>b,int asiz)
	{
		vector<ll>ret;
		ret.resize(6);
		ll d1=asiz;
		ll d2=d1*asiz%mod;
		ll d3=d2*asiz%mod;
		ll d4=d3*asiz%mod;
		ll d5=d4*asiz%mod;
		ret[0]=(a[0]+b[0])%mod;
		ret[1]=(a[1]+b[1]+d1*b[0])%mod;
		ret[2]=(a[2]+b[2]+tim(d1,2,b[1])+d2*b[0])%mod;
		ret[3]=(a[3]+b[3]+tim(d1,3,b[2])+tim(d2,3,b[1])+d3*b[0])%mod;
		ret[4]=(a[4]+b[4]+tim(d1,4,b[3])+tim(d2,6,b[2])+tim(d3,4,b[1])+d4*b[0])%mod;
		ret[5]=(a[5]+b[5]+tim(d1,5,b[4])+tim(d2,10,b[3])+tim(d3,10,b[2])+tim(d4,5,b[1])+d5*b[0])%mod;
		return ret;
	}
	void init(vector<ll>vec)
	{
		seg.resize(SIZE*2);
		for(int i=0;i<SIZE*2;i++)
		{
			flag[i]=-1;
			seg[i].resize(6);
		}
		for(int i=0;i<vec.size();i++)
		{
			for(int j=0;j<=5;j++)
			{
				seg[SIZE+i][j]=vec[i];
			}
		}
		dfs(1,SIZE);
	}
	void dfs(int node,int dist)
	{
		if(node>=SIZE)
		{
			return;
		}
		dfs(node*2,dist/2);
		dfs(node*2+1,dist/2);
		seg[node]=unite(seg[node*2],seg[node*2+1],dist/2);
	}
	void update(int beg,int end,int node,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return;
		}
		if(beg<=lb&&ub<=end)
		{
			for(int i=0;i<=5;i++)
			{
				seg[node][i]=(num*powsum[ub-lb+1][i])%mod;
			}
			flag[node]=num;
			return;
		}
		if(flag[node]!=-1)
		{
			for(int i=0;i<=5;i++)
			{
				seg[node*2][i]=(flag[node]*powsum[(ub-lb+1)/2][i])%mod;
				seg[node*2+1][i]=(flag[node]*powsum[(ub-lb+1)/2][i])%mod;
			}
			flag[node*2]=flag[node*2+1]=flag[node];
			flag[node]=-1;
		}
		update(beg,end,node*2,lb,(lb+ub)/2,num);
		update(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
		vector<ll>ret=unite(seg[node*2],seg[node*2+1],(ub-lb+1)/2);
		seg[node]=ret;
	}
	vector<ll>sum(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			vector<ll>z;
			for(int i=0;i<=5;i++)
			{
				z.push_back(0);
			}
			return z;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[node];
		}
		if(flag[node]!=-1)
		{
			for(int i=0;i<=5;i++)
			{
				seg[node*2][i]=(flag[node]*powsum[(ub-lb+1)/2][i])%mod;
				seg[node*2+1][i]=(flag[node]*powsum[(ub-lb+1)/2][i])%mod;
			}
			flag[node*2]=flag[node*2+1]=flag[node];
			flag[node]=-1;
		}
		vector<ll>va=sum(beg,end,node*2,lb,(lb+ub)/2),vb=sum(beg,end,node*2+1,(lb+ub)/2+1,ub);
		vector<ll>ret=unite(va,vb,min((ub-lb+1)/2,max((lb+ub)/2+1-beg,0)));
		return ret;
	}
};
segtree tree;
int main()
{
	calcpow();
	int num,query;
	scanf("%d%d",&num,&query);
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
	}
	tree.init(vec);
	for(int i=0;i<query;i++)
	{
		char za;
		int zb,zc;
		ll zd;
		scanf(" %c%d%d%I64d",&za,&zb,&zc,&zd);
		zb--;
		zc--;
		if(za=='=')
		{
			tree.update(zb,zc,1,0,SIZE-1,zd);
		}
		else
		{
			vector<ll>ret=tree.sum(zb,zc,1,0,SIZE-1);
			printf("%I64d\n",ret[zd]);
		}
	}
}