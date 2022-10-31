#include<bits/stdc++.h>
#define int long long
const int N=5000050;
using namespace std;

priority_queue<int> q;
int a[N],n,k,nw,ans;

main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=k+1;i++)q.push(0);
	for(int i=n;i;i--){
		nw=q.top(),ans+=nw,q.pop(),q.push(nw+a[i]);
	}
	printf("%lld",ans);
}