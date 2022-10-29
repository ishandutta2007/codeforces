#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=300050;
const ll inf=(ll)5e18;

ll a[N],n,ans=inf,ans1=0,b[N],sum=0;

ll _abs(ll x)
{
	if(x<0) return -x;
	else return x;
}

int main() 
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]==1) b[++sum]=i;
	}
	if(sum==1)
	{
		puts("-1");
		return 0;
	}
	for(ll d=2;d<=sum;d++) if(sum%d==0)
	{
		ans1=0;
		for(int i=1;i<=sum;i+=d)
		{
			int mid=(i+i+d-1)/2;
			for(int j=i;j<=i+d-1;j++) ans1+=_abs(b[j]-b[mid]);
		}		
		ans=min(ans,ans1);
	}
	cout<<ans<<endl;
	return 0;
}