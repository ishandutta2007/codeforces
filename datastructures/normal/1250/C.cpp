#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[1000005],x,y,z;
inline int check(int xx){
	int larger=0,lowwer=0;
	for (int i=1;i<=n;i++)
		if (a[i]>xx)larger+=a[i]-xx;
		else lowwer+=xx-a[i];
	if (larger>lowwer)return lowwer*z+(larger-lowwer)*y;
	return larger*z+(lowwer-larger)*x;
}
signed main(){
    cin>>n>>x>>y>>z;
	z=min(z,x+y);
    for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int l=0,r=1e9,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid)<=check(mid+1))r=mid-1,ans=check(mid);
		else l=mid+1;
	}
	cout<<ans<<endl;
    return 0;
}