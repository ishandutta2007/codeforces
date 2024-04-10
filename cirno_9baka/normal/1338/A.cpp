#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=524288;
int n,i,s,j,mx,ans,t,a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		mx=-1000000001;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
			ans=max(ans,mx-a[i]);
		}
		for(i=0;;++i)
			if((1ll<<1ll*i)-1>=ans)
				break;
		printf("%d\n",i);
	}
}