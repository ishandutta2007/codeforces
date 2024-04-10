#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,l[200005],r[200005],ans;
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&l[i]);
		scanf("%I64d",&r[i]);
	}
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for (i=1;i<=n;i++) ans+=max(l[i],r[i]);
	cout<<ans+n;
}