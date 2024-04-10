#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 262144
#define INF 2100000000LL
typedef long long ll;
class segtree
{
public:
	ll seg[SIZE*2];
	void update(int a,ll b)
	{
		a+=SIZE;
		seg[a]=b;
		for(;;)
		{
			a/=2;
			if(a==0)break;
			seg[a]=max(seg[a*2],seg[a*2+1]);
		}
	}
	ll get(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb)return 0;
		if(beg<=lb&&ub<=end)return seg[node];
		return max(get(beg,end,node*2,lb,(lb+ub)/2),get(beg,end,node*2+1,(lb+ub)/2+1,ub));
	}
};
segtree tree;
typedef pair<ll,ll>pii;
ll to[SIZE];
pii nex[20][SIZE];
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		vec.push_back(make_pair(za,zb));
	}
	for(int i=num-1;i>=0;i--)
	{
		ll maxi=vec[i].first+vec[i].second;
		int upp=upper_bound(vec.begin(),vec.end(),make_pair(vec[i].first+vec[i].second,INF))-vec.begin()-1;
		maxi=max(maxi,tree.get(i,upp,1,0,SIZE-1));
		tree.update(i,maxi);
		to[i]=maxi;
	}
	for(int i=0;i<num;i++)
	{
		int upp=upper_bound(vec.begin(),vec.end(),make_pair(to[i],INF))-vec.begin()-1;
		if(upp==num-1)nex[0][i]=make_pair(num-1,0);
		else nex[0][i]=make_pair(upp+1,vec[upp+1].first-to[i]);
		//printf("%d  %d %d\n",to[i],nex[0][i].first,nex[0][i].second);
	}
	for(int i=1;i<20;i++)
	{
		for(int j=0;j<num;j++)
		{
			nex[i][j]=make_pair(nex[i-1][nex[i-1][j].first].first,nex[i-1][j].second+nex[i-1][nex[i-1][j].first].second);
			//if(i<=2)printf("%d %d   ",nex[i][j].first,nex[i][j].second);
		}
		//if(i<=2)printf("\n");
	}
	int query;
	scanf("%d",&query);
	for(int p=0;p<query;p++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		ll ret=0;
		for(int i=19;i>=0;i--)
		{
			if(nex[i][za].first-1<zb)
			{
				ret+=nex[i][za].second;
				za=nex[i][za].first;
			}
		}
		printf("%I64d\n",ret);
	}
}