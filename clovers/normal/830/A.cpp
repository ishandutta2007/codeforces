#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2001;
const int inf=(int)5e9;

int n,p,k;
int a[N],b[N],bl[N];

int _abs(int x)
{
	return x<0 ? -x : x;
}

bool check(int x)
{
	memset(bl,0,sizeof(bl));
	int now=n+1;
	for(int i=1;i<=n;i++)
	{
		int judge=1;
		if(a[i]<=p)
		{
			for(int j=1;j<=k;j++)
			{
				if(_abs(a[i]-b[j])+_abs(b[j]-p)<=x&&!bl[j]) 
				{
					judge=0;
					bl[j]=1;
					break;
				}
			}
		}
		else 
		{
			now=i; break;
		}
		if(judge) return 0;
	}
	for(int i=n;i>=now;i--)
	{
		int judge=1;
		for(int j=k;j>=1;j--)
		{
			if(_abs(a[i]-b[j])+_abs(b[j]-p)<=x&&!bl[j]) 
			{
				judge=0;
				bl[j]=1;
				break;
			}
		}
		if(judge) return 0;
	}
	return 1;
}

signed main()
{
	scanf("%lld%lld%lld",&n,&k,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=k;i++) scanf("%lld",&b[i]);
	sort(a+1,a+n+1); sort(b+1,b+k+1);
	int l=0,r=inf,best;
	while(l<=r)
	{
		int mid=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(check(mid)) best=mid,r=mid-1;
		else l=mid+1; 
	}
	cout<<best<<endl;
}