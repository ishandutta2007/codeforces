#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int t,n,s,a[100005],sum[100005],ans,mx,mxid;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>s;
		for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
		for (int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
		ans=0,mx=0;
		for (int i=1;i<=n;i++){
			if (a[i]>mx)mx=a[i],mxid=i;
			if (sum[i]-mx<=s)ans=mxid;
		}
		if (sum[n]<=s)ans=0;
		cout<<ans<<endl;
	}
	return 0;
}