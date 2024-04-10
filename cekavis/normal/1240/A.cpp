#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int T, n, a[N], x, xx, y, yy;
ll k;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), a[i]/=100;
		sort(a+1, a+n+1, greater<int>());
		scanf("%d%d%d%d%lld", &x, &xx, &y, &yy, &k);
		if(x<y) swap(x, y), swap(xx, yy);
		int l=1, r=n, ans=0;
		while(l<=r){
			int mid=(l+r)>>1, s1=mid/((ll)xx*yy/__gcd(xx, yy)), s2=mid/xx-s1, s3=mid/yy-s1;
			ll tot=0;
			for(int i=1; i<=s1; ++i) tot+=a[i]*(x+y); 
			for(int i=s1+1; i<=s1+s2; ++i) tot+=a[i]*x;
			for(int i=s1+s2+1; i<=s1+s2+s3; ++i) tot+=a[i]*y;
			if(tot>=k) ans=mid, r=mid-1; else l=mid+1;
		}
		printf("%d\n", ans?ans:-1);
	}
	return 0;
}