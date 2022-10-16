#include <iostream>
#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,m,s,a[10005],b[10005],suma[10005],sumb[10005],mna[10005],mnb[10005],ans;
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		suma[i]=suma[i-1]+a[i];
	}
	for (int i=1;i<=m;i++){
		cin>>b[i];
		sumb[i]=sumb[i-1]+b[i];
	}
	cin>>s;
	for (int i=1;i<=n;i++){
		mna[i]=1e18;
		for (int j=i;j<=n;j++)mna[i]=min(mna[i],suma[j]-suma[j-i]);
	}
	for (int i=1;i<=m;i++){
		mnb[i]=1e18;
		for (int j=i;j<=m;j++)mnb[i]=min(mnb[i],sumb[j]-sumb[j-i]);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
	//		cout<<i<<' '<<j<<' '<<mna[i]<<' '<<mnb[j]<<endl;
			if (mna[i]*mnb[j]<=s)ans=max(ans,i*j);
		}
	cout<<ans<<endl;
	return 0;
}