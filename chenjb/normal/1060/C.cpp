
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
int n,m;
int a[2100],b[2100];
int x[2100],y[2100];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){ scanf("%d",&a[i]); a[i]+=a[i-1]; x[i]=2147483647; }
	for(int i=1;i<=m;i++){ scanf("%d",&b[i]); b[i]+=b[i-1]; y[i]=2147483647; }
	long long s; cin>>s;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			x[j-i+1]=min(x[j-i+1],a[j]-a[i-1]);

	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
			y[j-i+1]=min(y[j-i+1],b[j]-b[i-1]);

	//rep(i,n)cout<<x[i]<<" "; puts("");
	//rep(i,m)cout<<y[i]<<" "; puts("");
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if (1ll*x[i]*y[1]>s)continue;
		int l=1; int r=m;
		while (l<r)
		{
			int mid=(l+r)/2 + 1;
			if (1ll*x[i]*y[mid]<=s)l=mid; else r=mid-1;
		}
		ans=max(ans,i*l);
	}
	cout<<ans<<endl;
}