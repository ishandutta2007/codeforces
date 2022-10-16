#include <iostream>
#include <cstdio>
using namespace std;
int n,a[200005],f[200005],first,ans;
int main(){
//    freopen("1141B.in","r",stdin);
//	freopen("1141B.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1)f[i]=f[i-1]+1;
		else f[i]=0;
		if (f[i]==i)first=i;
		ans=max(ans,f[i]);
	}
	ans=max(ans,first+f[n]);
	cout<<ans<<endl;
	return 0;
}