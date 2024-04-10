#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

ll n,a[N],t;

int main()
{	
	cin>>t;
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ll ans=0,mx=a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[i-1]) ans+=a[i-1]-a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}