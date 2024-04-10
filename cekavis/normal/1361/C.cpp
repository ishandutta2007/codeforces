#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005, M = 1<<20;
int n, num, cnt, a[N], b[N], f[N*2], e[N*2], w[N*2], pre[N*2], h[M], d[M], now[M];
bool vis[N];
void add(int x, int y, int z){ ++d[x], e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
void dfs(int u){
	int &x=now[u];
	while(x){
		if(vis[x/2]) x=pre[x];
		else{
			int y=x;
			vis[x/2]=1, x=pre[x], dfs(e[y]);
			f[++cnt]=w[y], f[++cnt]=w[y]^1;
		}
	}
}
bool check(int x){
	int xx=(1<<x)-1;
	cnt=0, num=1, memset(h, 0, 4<<x), memset(d, 0, 4<<x), memset(vis+1, 0, n);
	for(int i=1; i<=n; ++i) add(a[i]&xx, b[i]&xx, i*2+1), add(b[i]&xx, a[i]&xx, i*2);
	for(int i=0; i<1<<x; ++i) if(d[i]&1) return 0;
	memcpy(now, h, 4<<x);
	int c=0;
	for(int i=0; i<1<<x; ++i) if(h[i] && now[i]) dfs(i), ++c;
	if(c>1) return 0;
	return 1;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", a+i, b+i);
	int l=1, r=20, ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid, l=mid+1; else r=mid-1;
	}
	check(ans);
	printf("%d\n", ans);
	for(int i=1; i<=cnt; ++i) printf("%d%c", f[i]-1, " \n"[i==cnt]);
	// f[cnt+1]=f[1];
	// for(int i=3; i<=cnt+1; i+=2){
	// 	printf(">> %d %d %d\n", i, (f[i]&1?b:a)[f[i]/2], (f[i-1]&1?b:a)[f[i-1]/2]);
	// 	assert((((f[i]&1?b:a)[f[i]/2]^(f[i-1]&1?b:a)[f[i-1]/2])&((1<<ans)-1))==0);
	// }
	return 0;
}