#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=500010;

ll n,a[N],sum=INF,b[N],ans[N];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	for(int pos=1;pos<=n;pos++)
	{
		for(int i=1;i<=n;i++) b[i]=a[i];
		ll tmp=0;
		for(int i=pos-1;i>=1;i--)
		{
			if(b[i]>b[i+1]) 
			{
				tmp+=(b[i]-b[i+1]);
				b[i]=b[i+1];
			}
		}
		for(int i=pos+1;i<=n;i++)
		{
			if(b[i]>b[i-1]) 
			{
				tmp+=(b[i]-b[i-1]);
				b[i]=b[i-1];
			}
		}
		if(sum>tmp) 
		{
			sum=tmp;
			for(int i=1;i<=n;i++) ans[i]=b[i];
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}