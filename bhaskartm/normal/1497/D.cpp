#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int n,tag[N],a[N];
ll ans,f[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&tag[i]);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),f[i]=0;
		ans=0;
		for(int i=2;i<=n;i++)
		for(int j=i-1;j;j--)
		if(tag[i]!=tag[j])
		{
			ll tmp=f[j];
			f[j]=max(f[j],f[i]+abs(a[i]-a[j]));
			f[i]=max(f[i],tmp+abs(a[i]-a[j]));
		}
		for(int i=1;i<=n;i++)ans=max(ans,f[i]);
		printf("%lld\n",ans);
	}
}