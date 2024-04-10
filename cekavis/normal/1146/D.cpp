#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200005;
int m, a, b, g, n, ans2, vis[N];
ll ans;
int main() {
	scanf("%d%d%d", &m, &a, &b), g=__gcd(a, b), n=m/g, a/=g, b/=g;
	int x=0, mx=0;
	do{
		x+=a, vis[x]=mx=max(mx, x);
		while(x>=b) vis[x-=b]=mx;
	} while(x);
	if(a+b<=n) ans=(ll)(n-a-b+1)*(n-a-b+2)/2, ans2+=n-a-b+1;
	for(int i=1; i<a+b; ++i) if(vis[i]<=n) ans+=n-vis[i]+1, ++ans2;
	return printf("%lld", ans*g+m+1-(g-m%g-1)*ans2), 0;
}