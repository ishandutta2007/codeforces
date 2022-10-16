#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int n,a[100005],ans,x,y;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==0)ans++,y++;
		if (a[i]>0)ans+=a[i]-1;
		if (a[i]<0)ans+=-1-a[i],x++;
	}
	if (y>0)cout<<ans<<endl;
	else cout<<ans+x%2*2<<endl;
	return 0;
}