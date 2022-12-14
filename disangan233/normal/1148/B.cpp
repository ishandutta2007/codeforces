#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
int n,m,ta,tb,k,a[200005],b[200005],ans;
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for(re i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=ta;
	for(re j=1;j<=m;j++) scanf("%d",&b[j]);
	if(k>=m||k>=n) return puts("-1"),0;
	for(re i=0;i<=k;i++)
	{
		re x=lower_bound(b+1,b+m+1,a[i+1])-b;
		if(x+(k-i)>m) return puts("-1"),0;
		ans=max(ans,b[x+(k-i)]+tb);
	}
	cout<<ans;
	return 0;
}