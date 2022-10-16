#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[300005],s[300005],cnt0[300005],cnt1[300005],ans;
inline int lowbit(int x){
	return x&(-x);
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		int x=a[i];
		a[i]=0;
		while(x)a[i]++,x-=lowbit(x);
	}
	cnt0[0]=1;
	for (int i=1;i<=n;i++){
		cnt0[i]=cnt0[i-1];
		cnt1[i]=cnt1[i-1];
		s[i]=s[i-1]+a[i];
		if (s[i]%2==0)cnt0[i]++;
		if (s[i]%2==1)cnt1[i]++;	
	}
	for (int i=1;i<=n;i++){
		int sum=0,mx=0;
		for (int j=i;j>=1&&j>i-64;j--){
			sum+=a[j],mx=max(mx,a[j]);
			if (mx<=sum-mx&&sum%2==0)ans++;
		}
		if (i>64){
			if (s[i]%2==0)ans+=cnt0[i-64-1];
			else ans+=cnt1[i-64-1];
		}
	}
	cout<<ans<<endl;
	return 0;
}