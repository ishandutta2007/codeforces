#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, a[N];
ll ans, f[N];
int main() {
	scanf("%d", &n);
	for(int i=1, x; i<=n; ++i){
		scanf("%d", &x);
		int l=1, r=i-1, t=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(f[mid-1]+(ll)mid*x>f[mid]) t=mid, r=mid-1; else l=mid+1;
		}
		for(int j=i; j>=t; --j) f[j]=f[j-1]+(ll)j*x;
	}
	for(int i=1; i<=n; ++i) ans=max(ans, f[i]);
	printf("%lld\n", ans);
	return 0;
}