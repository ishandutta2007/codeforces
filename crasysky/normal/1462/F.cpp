#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6; int a[N],b[N],l[N],r[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) 
			scanf("%d%d",&l[i],&r[i]),a[i]=l[i],b[i]=r[i];
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		int ans=n;
		rep(i,1,n){
			int p=lower_bound(b+1,b+1+n,l[i])-b-1;
			int q=upper_bound(a+1,a+1+n,r[i])-a;
			ans=min(ans,p+(n-q+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}