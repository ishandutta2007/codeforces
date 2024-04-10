#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#define int long long
#define inf 1000000000000000
using namespace std;
int n,m,ta,tb,k,a[200005],b[200005];
int ans;
int larger(int x){
	int l=1,r=m,ans=m+1;
	while(l<=r){
		int mid=(l+r)/2;
		if (b[mid]>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	cin>>n>>m>>ta>>tb>>k;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=m;i++)scanf("%lld",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	for (int i=1;i<=n&&i<=k+1;i++){
		int qwq=larger(a[i]+ta);
		qwq+=k-(i-1);
		if (qwq>m)ans=inf;
		else ans=max(ans,b[qwq]+tb);
	}
	if (n<=k||m<=k)ans=inf;
	if (ans==inf)puts("-1");
	else cout<<ans<<endl;
	return 0;
}