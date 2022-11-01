#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 5005;
int n, s, e, f[N], a[5][N];
ll ans;
ll d(int x, int y){
	return (ll)abs(a[0][x]-a[0][y])+a[3+(x<y)][x]+a[1+(y<x)][y];
}
int main() {
	scanf("%d%d%d", &n, &s, &e);
	for(int i=0; i<5; ++i) for(int j=1; j<=n; ++j) scanf("%d", a[i]+j);
	ans=d(s, e), f[s]=e;
	for(int i=1, y=0; i<=n; ++i) if(i!=s && i!=e){
		ll x=1e18, X;
		for(int u=s; u!=e; u=f[u])
			if((X=d(u, i)+d(i, f[u])-d(u, f[u]))<x) x=X, y=u;
		ans+=x, f[i]=f[y], f[y]=i;
	}
	printf("%lld\n", ans);
	return 0;
}