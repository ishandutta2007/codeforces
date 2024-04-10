#include <iostream>
#include <cstdio>
#define int long long
using namespace std; 
int t,n,ans,a[1000005],m;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for (int i=1;i<n;i++)ans+=max(i-1,n-i)*max(i-1,n-i);
		cout<<ans<<endl;
		if (n==2){
			cout<<2<<' '<<1<<endl;
			cout<<1<<endl;
			cout<<1<<' '<<2<<endl;
		}
		else{ 
			int mid=n/2+1;
			a[1]=mid;
			for (int i=mid;i<n;i++)a[i]=i+1;
			a[n]=mid-1;
			for (int i=mid-1;i>1;i--)a[i]=i-1;
			for (int i=1;i<=n;i++)printf("%lld ",a[i]);
			cout<<endl;
			cout<<n-1<<endl;
			for (int i=mid;i<n;i++)printf("%lld %lld\n",i,1ll);
			for (int i=mid-1;i>1;i--)printf("%lld %lld\n",i,n);
			cout<<1<<' '<<n<<endl;
		}
	}
	return 0;
}