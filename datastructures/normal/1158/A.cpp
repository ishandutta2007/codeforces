#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <random>
#define int long long
using namespace std;
int n,m,a[100005],b[100005],id[100005];
int ans;
int lower(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=m;i++)scanf("%lld",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int fg=1,qwq=0;
	for (int i=1;i<=n;i++)ans+=a[i]*m;
	for (int i=1;i<=m;i++){
		if (b[i]<a[n])fg=0;
		if (b[i]==a[n])qwq=1;
		if (b[i]>a[n])ans+=b[i]-a[n];
	}
	if (qwq==0)ans+=a[n]-a[n-1];
	if (fg==0)puts("-1");
	else cout<<ans<<endl;
	// for (int i=1;i<=m;i++)id[i]=lower(b[i]);
	// if (id[1]==id[m])id[1]--;
	// if (id[1]==0)puts("-1");
	// else{
	// 	for (int i=1;i<=n;i++)ans+=a[i]*m;
	// 	for (int i=1;i<=m;i++)ans+=b[i]-a[id[i]];
	// 	cout<<ans<<endl;
	// }
	return 0;
}