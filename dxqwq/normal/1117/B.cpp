#include<bits/stdc++.h>
using namespace std;
long long a[200003];
int main()
{
	int n;
	long long k,m,ans;
	scanf("%d%I64d%I64d",&n,&m,&k);
	for(int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	ans=(a[n-1]*(m/(k+1)))+(a[n]*(m-(m/(k+1))));
	printf("%I64d",ans);
	return 0;
}