#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,x,a[300005];
int f[300005][3],ans;
signed main(){
	cin>>n>>x;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++){
		f[i][0]=max(a[i],f[i-1][0]+a[i]);
		f[i][1]=max(f[i-1][1]+a[i],f[i-1][2]+a[i]);
		f[i][2]=max(max(f[i-1][2]+a[i]*x,f[i-1][0]+a[i]*x),a[i]*x);
		ans=max(ans,max(f[i][0],max(f[i][1],f[i][2])));
	}
	cout<<ans<<endl;
	return 0;
}