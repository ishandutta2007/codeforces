#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[300005],s[300005],cnt[2],ans;
long long cntbit(long long x)
{
	long long s=0;
	while (x)
	{
		s+=(x&1);
		x>>=1;
	}
	return s;
}
bool check(int l,int r)
{
	if ((s[r]-s[l])&1) return 0;
	long long mx=0,i;
	for (i=l+1;i<=r;i++)
	{
		mx=max(mx,a[i]);
	}
	if (mx>s[r]-s[l]-mx) return 0;
	return 1;
}
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]=cntbit(a[i]);
		s[i]=s[i-1]+a[i];
	}
	for (i=1;i<=n;i++)
	{
		if (i-70>=0)
		{
			cnt[s[i-70]&1]++;
		}
		ans+=cnt[s[i]&1];
		for (j=max(0ll,i-69);j<i;j++)
		{
			if (check(j,i)) ans++;
		}
	}
	cout<<ans;
	return 0;
}