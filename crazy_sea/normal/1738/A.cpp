#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
vector<int> v[2];
ll calc(int x)
{
	if(x==0) return min(v[0][0],v[1][0]);
	ll s=0;
	if(x>0)
	{
		for(int i=0;i<x;i++)
			s+=v[0][i];
		return s;
	}
	for(int i=0;i<-x;i++)
		s+=v[1][i];
	return s;
}
int T,n,tp[1000010],a;
ll sum;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tp[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			sum+=a;
			v[tp[i]].push_back(a);
		}
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		printf("%lld\n",sum*2-calc(v[0].size()-v[1].size()));
		v[0].clear(),v[1].clear();
	}
}