#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9+1);
const ll INF=(ll)(5e18);
const int N=300010;

int t,n,a[N];
ll k;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		int mx=-inf;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		for(int i=1;i<=n;i++) a[i]=mx-a[i];
		k--;
		if(k%2==1)
		{
			mx=-inf;
			for(int i=1;i<=n;i++) mx=max(mx,a[i]);	
			for(int i=1;i<=n;i++) a[i]=mx-a[i];
		}
		for(int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
	}
	return 0;
}