#include<bits/stdc++.h>
using namespace std;
#define re register int
int n,ans,a[100005],maxn,now;
int main()
{
	cin>>n;
	for(re i=1;i<=n;i++) scanf("%d",&a[i]),maxn=max(maxn,a[i]);
	for(re i=1;i<=n;i++)
	if(a[i]==maxn)
	{
		while(a[i]==maxn&&i<=n) now++,i++;
		ans=max(ans,now);now=0;
	}
	cout<<ans;
	return 0;
}