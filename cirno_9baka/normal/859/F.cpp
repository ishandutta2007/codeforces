#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int64_t c,s[N],ns[N],ts[N],ans;
int n,a[N],i,ll,q[N],l,r;
int main()
{
	scanf("%d %lld",&n,&c);
	for(i=1;i<=2*n-1;++i)
	{
		scanf("%d",&a[i]);
		a[i]=min(1ll*a[i],c);
		s[i]=s[i-1]+a[i];
	}
	ll=1;
	l=r=1;
	for(i=1;i<=2*n-1;i+=2)
	{
		if(s[i]<=c)
		{
			int64_t su=a[i]+ns[i-1]-ns[q[l]];
			ans+=su;
			ts[i]=ts[max(i-2,1)]+su;
		}
		else
		{
			while(s[i]-s[ll-1]>c)
				ll+=2;
			while(q[l]<ll-1)
				++l;
			int64_t su=max(a[i]+ns[i-1]-ns[q[l]],c-(ts[i-2]-ts[max(ll-4,0)]));
			ans+=su;
			ts[i]=ts[max(i-2,1)]+su;
		}
		ns[i]=s[i]-ans;
		ns[i+1]=s[i+1]-ans;
		while(l<=r&&ns[i+1]<ns[q[r]])
			--r;
		q[++r]=i+1;
	}
	cout<<ans;
}