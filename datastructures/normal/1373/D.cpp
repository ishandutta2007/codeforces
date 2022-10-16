#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int t,n,a[200005],b[200005],f[200005],g[200005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,mx=0;
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if (i%2==1)ans+=a[i];
		}
		int tot=0;
		for (int i=2;i<=n;i+=2)
			b[++tot]=a[i]-a[i-1];
		for (int i=1;i<=tot;i++)
			f[i]=max(b[i],f[i-1]+b[i]),mx=max(mx,f[i]);
		tot=0;
		for (int i=3;i<=n;i+=2)
			b[++tot]=a[i-1]-a[i];
		for (int i=1;i<=tot;i++)
			f[i]=max(b[i],f[i-1]+b[i]),mx=max(mx,f[i]);
		cout<<ans+mx<<endl;
	}
	return 0;
}