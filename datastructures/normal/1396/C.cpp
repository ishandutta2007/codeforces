#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define inf 1000000000000000000
using namespace std;
int n,r1,r2,r3,d,a[1000005];
int f[1000005],t0[1000005],t1[1000005],c[1000005],s0[1000005],s1[1000005],mn[1000005];
int ans;
signed main(){
	cin>>n>>r1>>r2>>r3>>d;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++){
		t0[i]=r1*a[i]+r3;
		t1[i]=min(r2+r1,r1*(a[i]+2));
		t1[i]=min(t1[i],t0[i]);
		s0[i]=s0[i-1]+t0[i];
		s1[i]=s1[i-1]+t1[i];
	}
	mn[0]=-2*d;
	for (int i=1;i<=n;i++){
		if (i==1)f[1]=t0[1];
		else{
			f[i]=inf;
			f[i]=min(f[i],mn[i-2]+2*d*i+s1[i]);
			f[i]=min(f[i],t0[i]+f[i-1]);
			f[i]=min(f[i],2*d+t1[i]+f[i-1]);
		}
		mn[i]=min(mn[i-1],f[i]-2*d*(i+1)-s1[i]);
	}
	ans=inf;
	for (int i=1;i<=n-1;i++)ans=min(ans,f[i]+s1[n-1]-s1[i]+t0[n]+d*(n-i-1));
	ans=min(ans,f[n]);
	cout<<ans+(n-1)*d<<endl;
	return 0;
}