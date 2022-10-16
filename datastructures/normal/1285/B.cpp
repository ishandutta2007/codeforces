#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int t,n,a[1000005],f[1000005],sum;
inline int work(int l,int r){
	f[l]=a[l];
	int ans=a[l];
	for (int i=l+1;i<=r;i++)
		f[i]=max(a[i],f[i-1]+a[i]),ans=max(ans,f[i]);
	return ans;
}
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int i=1;i<=n;i++)sum+=a[i];
		if (work(2,n)>=sum||work(1,n-1)>=sum)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}