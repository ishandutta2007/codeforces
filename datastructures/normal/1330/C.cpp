#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,m,a[100005],f[100005],g[100005],sum[100005],ans[100005];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)scanf("%lld",&a[i]);
	f[m]=n-a[m]+1;
	for (int i=m-1;i>=1;i--){
		f[i]=min(n-a[i]+1,f[i+1]-1);
		if (f[i]==0){
			cout<<-1<<endl;
			return 0;
		}
	}
	for (int i=m;i>=1;i--)
		sum[i]=sum[i+1]+a[i];
	if (sum[1]<n){
		cout<<-1<<endl;
		return 0;
	}
	ans[1]=1;
	for (int i=1;i<=m;i++){
		ans[i]=min(ans[i-1]+1,f[i]);
		ans[i]=max(ans[i],n-sum[i]+1);
	}
	for (int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	cout<<endl;
	return 0;
}