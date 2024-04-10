#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
#define SIZE 262144
#define INF 2100000000LL
ll minl[100002];
ll minr[100002];
ll maxl[100002];
ll maxr[100002];
int main()
{
	int num;
	scanf("%d",&num);
	vector<ll>vx,vy;
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		int t=za+zb;
		zb=za-zb;
		za=t;
		vec.push_back(make_pair(za,zb));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<num;i++)
	{
		vx.push_back(vec[i].first);
		vy.push_back(vec[i].second);
	}
	minl[0]=INF;
	minr[num+1]=INF;
	maxl[0]=-INF;
	maxr[num+1]=-INF;
	for(int i=0;i<vy.size();i++)
	{
		minl[i+1]=min(minl[i],vy[i]);
		maxl[i+1]=max(maxl[i],vy[i]);
	}
	for(int i=vy.size()-1;i>=0;i--)
	{
		minr[i+1]=min(minr[i+2],vy[i]);
		maxr[i+1]=max(maxr[i+2],vy[i]);
	}
	ll beg=0,end=INF*4;
	ll ret=INF*4;
	for(;;)
	{
		ll med=(beg+end)/2;
		int pt=0;
		ll ans=INF*4;
		for(int i=0;i<num;i++)
		{
			for(;;)
			{
				if(vec[i].first>vec[pt].first+med)
				{
					pt++;
				}
				else
				{
					break;
				}
			}
			ans=min(ans,max(maxl[pt-1+1],maxr[i+1+1])-min(minl[pt-1+1],minr[i+1+1]));
		}
		ret=min(ret,max(ans,med));
		if(beg==end)
		{
			break;
		}
		if(ans<med)
		{
			end=med;
		}
		else
		{
			beg=med+1;
		}
	}
	printf("%lf\n",double(ret)/2.0);
}