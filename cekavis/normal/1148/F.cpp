#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int n, a[N];
ll sum, ans, b[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%lld", a+i, b+i), sum+=a[i];
	if(sum<0) for(int i=1; i<=n; ++i) a[i]=-a[i];
	for(int i=62; i--;){
		ll x=0;
		for(int j=1; j<=n; ++j) if((b[j]&((2ll<<i)-1))==1ll<<i) x+=a[j];
		if(x>0){
			ans|=1ll<<i;
			for(int j=1; j<=n; ++j) if(b[j]>>i&1) a[j]=-a[j];
		}
	}
	return printf("%lld", ans), 0;
}