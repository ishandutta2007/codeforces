#include<bits/stdc++.h>
using namespace std;
const int N=200001;
typedef long long ll;

ll n,A,R,M;
ll a[N];

ll calc(ll h)
{
	ll up=0,down=0;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]>h) up+=a[i]-h;
		else down+=h-a[i];
	}
	if(M<A+R) 
	{
		if(up<down) return M*up+A*(down-up);
		else return M*down+R*(up-down);
	}
	else return A*down+R*up;
}
 
int main()
{
	scanf("%lld%lld%lld%lld",&n,&A,&R,&M);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll l=0,r=(ll)1e9+100,best=-1;
	while(l+2<r)
	{
		ll mid1=(l+l+r)/3;
		ll mid2=(l+r+r)/3;
		if(calc(mid1)<calc(mid2)) r=mid2,best=mid1;
		else l=mid1,best=mid2;
	}
	printf("%lld\n",calc(best));
	return 0;
}