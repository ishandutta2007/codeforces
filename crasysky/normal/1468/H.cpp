#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=1e6+6; int a[N],s[N];
signed main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,k,m; scanf("%d%d%d",&n,&k,&m);
		rep(i,1,n) a[i]=1;
		rep(i,1,m){
			int x; scanf("%d",&x),a[x]=0;
		}
		if ((n-m)%(k-1)){ puts("NO"); continue; }
		rep(i,1,n) s[i]=s[i-1]+a[i];
		bool f=false;
		rep(i,1,n)
			if (!a[i]&&s[i-1]>=(k>>1)&&s[n]-s[i]>=(k>>1)){
				f=true; break;
			}
		puts(f?"YES":"NO");
	}
	return 0;
}