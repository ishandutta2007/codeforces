#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,d,a[N];
ll ans=0;

ll calc(ll x)
{
	if(x<2) return 0;
	return x*(x-1)/2;
}

int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n-1;i++)
	{
		int pos=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		//cout<<i<<" "<<pos<<endl;
		ans+=calc(1LL*(pos-i));
	}
	cout<<ans<<endl;
}