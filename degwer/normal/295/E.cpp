#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<ll,pii>pi3;
typedef pair<pii,pii>pi4;
#define SIZE (1LL<<31LL)
#define SEG 1048576
class segtree
{
public:
	ll segans[SEG*2];
	ll segl[SEG*2];
	ll segr[SEG*2];
	ll flag[SEG*2];
	ll xl[SEG*2];
	ll xr[SEG*2];
	void init(vector<ll>vec)
	{
		for(int i=0;i<vec.size()-1;i++)
		{
			xl[SEG+i]=vec[i];
			xr[SEG+i]=vec[i+1]-1;
		}
		for(int i=vec.size()-1;i<SEG;i++)
		{
			xl[SEG+i]=SIZE;
			xr[SEG+i]=SIZE-1;
		}
		for(int i=SEG-1;i>=1;i--)
		{
			xl[i]=xl[i*2];
			xr[i]=xr[i*2+1];
		}
	}
	void update(ll pl,int node,int num)
	{
		if(xr[node]<pl||pl<xl[node])
		{
			return;
		}
		if(node>=SEG)
		{
			if(num==1)
			{
				segl[node]=0;
				segr[node]=xr[node]+1-xl[node];
				flag[node]=1;
			}
			else
			{
				segl[node]=0;
				segr[node]=0;
				flag[node]=0;
			}
			return;
		}
		update(pl,node*2,num);
		update(pl,node*2+1,num);
		flag[node]=flag[node*2]+flag[node*2+1];
		segans[node]=segans[node*2]+segans[node*2+1]+segr[node*2]*flag[node*2+1]+segl[node*2+1]*flag[node*2];
		segl[node]=segl[node*2]+(xr[node*2]-xl[node*2]+1)*flag[node*2+1]+segl[node*2+1];
		segr[node]=segr[node*2]+(xr[node*2+1]-xl[node*2+1]+1)*flag[node*2]+segr[node*2+1];
	}
	pi4 calc(ll beg,ll end,int node)
	{
		if(xr[node]<beg||end<xl[node])
		{
			return make_pair(make_pair(0,0),make_pair(0,0));
		}
		if(beg<=xl[node]&&xr[node]<=end)
		{
			return make_pair(make_pair(segans[node],flag[node]),make_pair(segl[node],segr[node]));
		}
		pi4 zl=calc(beg,end,node*2);
		pi4 zr=calc(beg,end,node*2+1);
		ll ra=zl.first.first+zr.first.first+zr.second.first*zl.first.second+zl.second.second*zr.first.second;
		ll rb=zl.first.second+zr.first.second;
		ll rl=zl.second.first+zr.second.first+(xr[node*2]-xl[node*2]+1)*zr.first.second;
		ll rr=zl.second.second+zr.second.second+(xr[node*2+1]-xl[node*2+1]+1)*zl.first.second;
		return make_pair(make_pair(ra,rb),make_pair(rl,rr));
	}
};
segtree tree;
ll pla[100000];
ll zp[100000];
vector<ll>zat(vector<ll>vec)
{
	sort(vec.begin(),vec.end());
	vector<ll>ret;
	ll now=-SIZE*2;
	for(int i=0;i<vec.size();i++)
	{
		if(now!=vec[i])
		{
			now=vec[i];
			ret.push_back(now);
		}
	}
	return ret;
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<ll>zv;
	vector<ll>ini;
	zv.push_back(-SIZE);
	zv.push_back(SIZE-1);
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		pla[i]=zan;
		zp[i]=zan;
		zv.push_back(zan);
		zv.push_back(zan+1);
		ini.push_back(zan);
	}
	int query;
	scanf("%d",&query);
	vector<pi3>que;
	for(int p=0;p<query;p++)
	{
		int za;
		ll zb,zc;
		scanf("%d%I64d%I64d",&za,&zb,&zc);
		que.push_back(make_pair(za,make_pair(zb,zc)));
		if(za==1)
		{
			zb--;
			zp[zb]+=zc;
			zv.push_back(zp[zb]);
			zv.push_back(zp[zb]+1);
		}
		else
		{
			zv.push_back(zb);
			zv.push_back(zb+1);
			zv.push_back(zc);
			zv.push_back(zc+1);
		}
	}
	vector<ll>vec=zat(zv);
	tree.init(vec);
	for(int i=0;i<num;i++)
	{
		tree.update(ini[i],1,1);
	}
	for(int p=0;p<query;p++)
	{
		int za;
		ll zb,zc;
		za=que[p].first;
		zb=que[p].second.first;
		zc=que[p].second.second;
		if(za==1)
		{
			zb--;
			tree.update(pla[zb],1,-1);
			pla[zb]+=zc;
			tree.update(pla[zb],1,1);
		}
		else
		{
			pi4 zan=tree.calc(zb,zc,1);
			printf("%I64d\n",zan.first.first);
		}
	}
}