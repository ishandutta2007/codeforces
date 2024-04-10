#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, b[N];
ll ans, f[N*3];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", b+i), f[b[i]-i+n]+=b[i];
	for(int i=0; i<=600000; ++i) ans=max(ans, f[i]);
	printf("%lld\n", ans);
	return 0;
}