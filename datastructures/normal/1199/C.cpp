#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,s,a[1000005];
int x[1000005],sum[1000005],tot,ans;
inline int asklog(int num){
	if (num==1ll)return 0ll;
	for (int i=0ll;;i++)	
		if ((1ll<<i)>=num)return i;
}
inline int erfen(){
	int l=0ll,r=tot,ans=0ll;
	while(l<=r){
		int mid=(l+r)/2;
		if (n*asklog(mid)<=s*8ll)ans=mid,l=mid+1ll;
		else r=mid-1ll;
	}
	return ans;
}
signed main(){
	cin>>n>>s;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	a[0]=-1;
	for (int i=1;i<=n;i++){
		if (a[i]!=a[i-1])x[++tot]=1ll;
		else x[tot]++;
	}
	for (int i=1;i<=tot;i++)
		sum[i]=sum[i-1]+x[i];
	int num=erfen();
	for (int i=1;i<=tot;i++)
		ans=max(ans,sum[i]-sum[max(0ll,i-num)]);
	cout<<n-ans<<endl;
	return 0;
}