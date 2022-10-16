#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[200005],b[200005],ans;
signed main(){
//	freopen("1139B.in","r",stdin);
//	freopen("1139B.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	b[n]=a[n],ans+=b[n];
	for (int i=n-1;i>=1;i--){
		b[i]=min(b[i+1]-1,a[i]),ans+=b[i];
		if (!b[i])break;
	}
	cout<<ans<<endl;
}