#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <stack>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
long long tp[110000],a[110000];
int n,k,l,m;
int ans[110000];
int main()
{
	cin>>n>>k>>l;
	m=n*k;
	for(int i=1;i<=m;i++)scanf("%lld",&tp[i]);
	sort(tp+1,tp+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++)
		if (tp[i]<=tp[1]+l)a[++cnt]=tp[i];

	if (cnt<n){ puts("0"); return 0; }

	int now=1;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=ans+a[now++];
		for(int j=1;j<k;j++)
		{
			if (cnt-now>=n-i)now++;
		}
	}
	cout<<ans<<endl;
	return 0;
}