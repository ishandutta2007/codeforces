#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,l;
double a[100010],sum1[100010],sum2[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>l;
		a[0]=0.0;a[n+1]=l*1.0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sum1[0]=0.0;
		for(int i=1;i<=n+1;i++) sum1[i]=sum1[i-1]+(a[i]-a[i-1])/i;
		sum2[n+1]=0.0;
		for(int i=n;i>=0;i--) sum2[i]=sum2[i+1]+(a[i+1]-a[i])/(n-i+1);
		double L=0.0,R=l*1.0,ans=l*1.0;
		for(int i=1;i<=100;i++){
			double mid=(L+R)*1.0/2;
			int pos=upper_bound(a,a+n+2,mid)-a-1;
			double val1=sum1[pos]+(mid-a[pos])/(pos+1);
			double val2=sum2[pos+1]+(a[pos+1]-mid)/(n-pos+1);
			if(val1<val2){
				ans=min(ans,val2);
				L=mid;
			}
			else{
				ans=min(ans,val1);
				R=mid;
			}
		}
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
	return 0;
}