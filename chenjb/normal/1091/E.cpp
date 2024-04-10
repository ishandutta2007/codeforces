#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <cassert>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
#define inf 998244353
int n;
long long a[510000];
long long s[510000];
long long getd(int l,int r)
{
	return s[r]-s[l-1];
}
int main()
{
	cin>>n;
	long long tsum=0;
	rep(i,n){ scanf("%lld",&a[i]); tsum+=a[i]; }
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	s[0]=0; rep(i,n)s[i]=s[i-1]+a[i];

	long long L=0;
	long long R=n;
	rep(i,n)
	{
		int j=lower_bound(a+i+1,a+n+1,i,greater<long long>())-a;
		long long t=1ll*i*(i-1)+getd(j,n)+1ll*(j-i-1)*i;
		if (s[i]>t)
		{
			if (s[i]-t-i>0)
			{
				puts("-1");
				return 0;
			}
			if (s[i]-t>L)L=s[i]-t;
		}
		if (j-s[i]+t+i<R)R=j-s[i]+t+i;
	}
	if (L>R){ puts("-1"); return 0; }
	for(int i=L;i<=R;i++)
		if (tsum%2==1 && i%2==1)printf("%d ",i);
		else if (tsum%2==0 && i%2==0)printf("%d ",i);
	puts("");
}