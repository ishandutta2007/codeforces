#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<long long,long long> > M;

long long t[300000],a[300000];
long long f[300000];const long long INF=1e17;

int main()
{
	int n=0;long long v=0;scanf("%d%lld",&n,&v);
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)if(v*t[i]-a[i]>=0&&a[i]+v*t[i]>=0)M.push_back(make_pair(a[i]+v*t[i],v*t[i]-a[i]));
	sort(M.begin(),M.end());
	for(int i=1;i<=n+1;i++)f[i]=INF;
	for(int i=0;i<M.size();i++)
	{
		int p=upper_bound(f,f+n+2,M[i].second)-f;f[p]=M[i].second;
	}
	for(int i=n;i>=0;i--){if(f[i]!=INF){printf("%d",i);return 0;}}
}