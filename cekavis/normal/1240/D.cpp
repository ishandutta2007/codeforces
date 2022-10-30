#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005, M = N*20;
int T, n, cnt, d[N], r[N], f[N], a[N], s[M], ls[M], rs[M];
void modify(int l, int r, int &t, int pre, int x, int y){
	t=++cnt, ls[t]=ls[pre], rs[t]=rs[pre];
	if(l==r) return (void)(s[t]=y);
	int mid=(l+r)>>1;
	if(x<=mid) modify(l, mid, ls[t], ls[pre], x, y);
	else modify(mid+1, r, rs[t], rs[pre], x, y);
}
int query(int l, int r, int t, int x){
	if(l==r) return s[t];
	int mid=(l+r)>>1;
	if(x<=mid) return query(l, mid, ls[t], x); else return query(mid+1, r, rs[t], x);
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		ll ans=0;
		for(int i=n; i; --i){
			int j=query(1, n, r[i+1], a[i]);
			if(j) f[i]=j+1, ans+=d[i]=d[f[i]]+1; else f[i]=0;
			modify(1, n, r[i], r[f[i]], a[i], i);
		}
		printf("%lld\n", ans);
		memset(r+1, 0, (n+1)<<2), memset(d+1, 0, n<<2);
	}
	return 0;
}