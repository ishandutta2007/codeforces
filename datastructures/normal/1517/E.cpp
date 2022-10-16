#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std; 
int t,n,a[200005],ans;
int sum[200005][2],S[200005],num;
inline void calc1(){//P...CCCC
	for (register int i=2;i<=n;i++)
		if (S[n]-S[i-1]<=num)ans++;
	ans%=mod;
	return;
}
inline void calc2(){//CCPCPCPCPC...CPPC
	for (register int i=1;i<=n-2;i++){
		if (S[i]+a[n]>num)break;
		register int l=i+1,r=n-2,x=i;
		while(l<=r){
			register int mid=(l+r)/2;
			if (S[i]+a[n]+(sum[mid][i%2]-sum[i][i%2])<=num)x=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=1+(x-i)/2;
		ans%=mod;
	}
	return;
}
inline void calc3(){//CCPCPCPCPC...CPPP
	for (register int i=1;i<=n-1;i++){
		if (S[i]>num)break;
		register int l=i+1,r=n-1,x=i;
		while(l<=r){
			register int mid=(l+r)/2;
			if (S[i]+(sum[mid][i%2]-sum[i][i%2])<=num)x=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=1+(x-i)/2;
		ans%=mod;
	}
	return;
}
inline void calc4(){//PCCPCPCPCPC...CPPC
	for (register int i=2;i<=n-2;i++){
		if (S[i]+a[n]-a[1]>num)break;
		register int l=i+1,r=n-2,x=i;
		while(l<=r){
			register int mid=(l+r)/2;
			if (S[i]+a[n]-a[1]+(sum[mid][i%2]-sum[i][i%2])<=num)x=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=1+(x-i)/2;
		ans%=mod;
	}
	return;
}
inline void calc5(){//PCCPCPCPCPC...CPPP
	for (register int i=2;i<=n-1;i++){
		if (S[i]-a[1]>num)break;
		register int l=i+1,r=n-1,x=i;
		while(l<=r){
			register int mid=(l+r)/2;
			if (S[i]-a[1]+(sum[mid][i%2]-sum[i][i%2])<=num)x=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=1+(x-i)/2;
		ans%=mod;
	}
	return;
}
signed main(){
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for (int i=1;i<=n;i++){
			sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1],S[i]=S[i-1];
			sum[i][i%2]+=a[i],S[i]+=a[i];
		}
		num=(S[n]-1)/2;
		ans=0;
		calc1();
		calc2();
		calc3();
		calc4();
		calc5();
		ans++,ans%=mod;
		cout<<ans<<endl;
	}
	return 0;
}