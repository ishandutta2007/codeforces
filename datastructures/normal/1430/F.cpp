#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int n,k,l[2005],r[2005],a[2005],sum[2005],f[2005],ans=1e18;
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>l[i]>>r[i]>>a[i],sum[i]=sum[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	for (int i=1;i<=n;i++){
		if (f[i]>=1e18)continue;
		int rest=k;
		for (int j=i;j<=n;j++){
			int cnt;
			if (rest>=a[j])cnt=0;
			else{
				cnt=(a[j]-rest-1)/k+1;
				if (cnt>r[j]-l[j])break;
			}
			if (j==n)ans=min(ans,f[i]+sum[j]-sum[i-1]);
			else{
				if (cnt<r[j]-l[j]||r[j]!=l[j+1])f[j+1]=min(f[j+1],f[i]+((sum[j]-sum[i-1]-1)/k+1)*k);
				rest=rest+cnt*k-a[j];
			}
		}
	} 
	if (ans<1e18)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}