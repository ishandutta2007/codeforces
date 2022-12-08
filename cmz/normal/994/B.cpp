#include<bits/stdc++.h>
#define int long long
using namespace std;
struct rec {
	int c,p,id;
} a[500005];
int maxx[5005],ans[500005];
signed main() {
	int n,k;
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i].p);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i].c),a[i].id=i;
	sort(a+1,a+1+n,[](const rec &x,const rec &y){
		return x.p<y.p;
	});
	for(int i=1; i<=n; i++) {
		ans[a[i].id]=a[i].c;
		for(int j=1; j<=k; j++) {
			ans[a[i].id]+=maxx[j];
		}
		if(a[i].c>maxx[k]) {
			maxx[k]=a[i].c;
			for(int i=k-1; i>=1; i--)
				if(maxx[i]<maxx[i+1]) swap(maxx[i],maxx[i+1]);
		}
	}
	for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
	return 0;
}