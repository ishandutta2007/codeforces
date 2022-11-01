#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

ll n, l, r, k, len;
int main() {
	scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
	len=l<=r?r-l+1:n-l+r+1;
	k-=len;
	if(k<0) return puts("-1"), 0;
	if(n<=k/n){
		for(int x=n; ~x; --x){
			int y=k%(n+x);
			if(y<=x && y<=len && x-y<=n-len) return printf("%d", x), 0;
			y=(k+1)%(n+x);
			if(y && y<=x && y<=len && x-y<=n-len) return printf("%d", x), 0;
		}
		puts("-1");
	}
	else{
		ll ans=-1;
		if(k<=len) ans=n-len+k;
		for(int t=1; t*n<=k; ++t){
			ll y=k-t*n, x=y/t;
			y-=x*t;
			if(x-y>n-len){
				ll tmp=(x-y-n+len+t)/(t+1);
				x-=tmp, y+=tmp*t;
			}
			if(y<=x && y<=len) ans=max(ans, x);
		}
		++k;
		if(k && k<=len) ans=n-len+k;
		for(int t=1; t*n<=k; ++t){
			ll y=k-t*n, x=y/t;
			y-=x*t;
			if(x-y>n-len){
				ll tmp=(x-y-n+len+t)/(t+1);
				x-=tmp, y+=tmp*t;
			}
			if(y && y<=x && y<=len) ans=max(ans, x);
		}
		if(~ans) printf("%lld", ans); else puts("-1");
	}
	return 0;
}