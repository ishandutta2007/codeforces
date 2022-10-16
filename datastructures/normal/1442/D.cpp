#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;
int n,k,t[3005],sum[3005],f[3005],_f[25][3005],ans;
vector <int>a[1000005];
inline void ins(register int x,register int val){
	for (register int i=k;i>=x;i--)f[i]=max(f[i],f[i-x]+val);
	return;
}
inline void work(register int l,register int r,register int d){
	for (register int i=1;i<=k;i++)_f[d][i]=f[i];
	if (l==r){
		for (register int i=0;i<=k&&i<=t[l];i++)
			ans=max(ans,a[l][i]+f[k-i]);
		return;
	}
	register int mid=(l+r)/2;
	for (register int i=mid+1;i<=r;i++)ins(t[i],sum[i]);
	work(l,mid,d+1);
	for (register int i=1;i<=k;i++)f[i]=_f[d][i];
	for (register int i=l;i<=mid;i++)ins(t[i],sum[i]);
	work(mid+1,r,d+1);
	for (register int i=1;i<=k;i++)f[i]=_f[d][i];
	return;
}
signed main(){
	cin>>n>>k;
	for (register int i=1;i<=n;i++){
		scanf("%lld",&t[i]);
		a[i].push_back(0);
		for (register int j=1;j<=t[i];j++){
			register int x;
			scanf("%lld",&x);
			a[i].push_back(x);
			a[i][j]+=a[i][j-1];
			sum[i]+=x;
		}
	}
	work(1,n,1);
	cout<<ans<<endl;
	return 0;
}