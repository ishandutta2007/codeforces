#include<iostream>
using namespace std;
#define ll long long
const int N = 500005, M = 10000005, P = 1000000007;
ll ans;
int n, m, p[N], a[M], f[M];
int main() {
	scanf("%d", &n);
	p[0]=1;
	for(int i=1; i<=n; ++i) p[i]=p[i-1]*2%P;
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), m=max(m, x), ++a[x];
	for(int i=m; i>1; --i){
		int x=a[i];
		ll y=0;
		for(int j=i+i; j<=m; j+=i) y+=f[j], x+=a[j];
		f[i]=((p[x]-1ll)*(n-x)-y)%P, ans+=f[i]+=f[i]>>31&P;
	}
	printf("%lld\n", ans%P);
	return 0;
}