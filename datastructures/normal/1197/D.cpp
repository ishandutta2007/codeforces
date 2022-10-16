#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int n,m,k,a[300005],sum[300005],t[15],ans;
signed main(){
//	freopen("1197D.in","r",stdin);
//	freopen("1197D.out","w",stdout);
	cin>>n>>m>>k;
	memset(t,0x7f,sizeof(t));
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++){
		t[i%m]=min(t[i%m],sum[i-1]+k-i/m*k);
		sum[i]=sum[i-1]+a[i];
		int res=9e18;
		for (int j=0;j<m;j++){
			if (i%m>=j)res=min(res,t[j]+i/m*k);
			else res=min(res,t[j]+i/m*k-k);
		}
		ans=max(ans,sum[i]-res);
		ans=max(ans,sum[i]-((n-1)/m+1)*k);
	}
	cout<<ans<<endl;
}