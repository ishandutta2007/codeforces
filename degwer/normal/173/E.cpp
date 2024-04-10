#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 131072
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
class BIT
{
public:
	int bit[SIZE+1];
	void add(int a,int b)
	{
		for(;;)
		{
			if(a==SIZE)
			{
				break;
			}
			bit[a]+=b;
			a+=a&-a;
		}
	}
	int sum(int a)
	{
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
class segtree
{
public:
	int seg[SIZE*2];
	void update(int a,int b)
	{
		a+=SIZE;
		seg[a]=max(seg[a],b);
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
	int maxi(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return 0;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[node];
		}
		return max(maxi(beg,end,node*2,lb,(lb+ub)/2),maxi(beg,end,node*2+1,(lb+ub)/2+1,ub));
	}
};
BIT bi;
vector<int>pat[100000];
vector<pi3>qu[100000];
int ans[100000];
int ret[100000];
segtree rmq;
vector<int>uni(vector<int>vec)
{
	vector<int>ret;
	int now=-1;
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
	int num,gen;
	scanf("%d%d",&num,&gen);
	vector<pii>vec;
	vector<int>age;
	vector<int>resp;
	for(int i=0;i<num;i++)
	{
		int za;
		scanf("%d",&za);
		resp.push_back(za);
	}
	for(int i=0;i<num;i++)
	{
		int zb;
		scanf("%d",&zb);
		age.push_back(zb);
		vec.push_back(make_pair(resp[i],zb));
	}
	sort(age.begin(),age.end());
	sort(resp.begin(),resp.end());
	age=uni(age);
	resp=uni(resp);
	for(int i=0;i<num;i++)
	{
		int low=lower_bound(resp.begin(),resp.end(),vec[i].first)-resp.begin();
		vec[i].first=low;
		pat[low].push_back(i);
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<pat[i].size();j++)
		{
			int low=lower_bound(age.begin(),age.end(),vec[pat[i][j]].second)-age.begin();
			bi.add(low+2,1);
		}
		for(int j=0;j<pat[i].size();j++)
		{
			int low=lower_bound(age.begin(),age.end(),vec[pat[i][j]].second-gen)-age.begin();
			int upp=upper_bound(age.begin(),age.end(),vec[pat[i][j]].second+gen)-age.begin()-1;
			ans[pat[i][j]]=bi.sum(upp+2)-bi.sum(low+1);
		}
	}
	int query;
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		if(vec[za].first<vec[zb].first)
		{
			swap(za,zb);
		}
		qu[vec[za].first].push_back(make_pair(make_pair(vec[za].second,vec[zb].second),i));
	}
	for(int i=num-1;i>=0;i--)
	{
		for(int j=0;j<pat[i].size();j++)
		{
			int low=lower_bound(age.begin(),age.end(),vec[pat[i][j]].second)-age.begin();
			rmq.update(low,ans[pat[i][j]]);
		}
		for(int j=0;j<qu[i].size();j++)
		{
			if(qu[i][j].first.first>qu[i][j].first.second)
			{
				swap(qu[i][j].first.first,qu[i][j].first.second);
			}
			if(qu[i][j].first.second-qu[i][j].first.first>gen*2)
			{
				ret[qu[i][j].second]=0;
				continue;
			}
			int low=lower_bound(age.begin(),age.end(),qu[i][j].first.second-gen)-age.begin();
			int upp=upper_bound(age.begin(),age.end(),qu[i][j].first.first+gen)-age.begin()-1;
			if(low>upp)
			{
				ret[qu[i][j].second]=0;
				continue;
			}
			ret[qu[i][j].second]=rmq.maxi(low,upp,1,0,SIZE-1);
		}
	}
	for(int i=0;i<query;i++)
	{
		if(ret[i]==0)
		{
			ret[i]=-1;
		}
		printf("%d\n",ret[i]);
	}
}