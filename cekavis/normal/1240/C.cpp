#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005;
int T, n, k, num, h[N], e[N*2], pre[N*2], w[N*2];
ll a[N], f[N][2];
void add(int x, int y, int z){ e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
void dfs(int u, int fa=0){
	f[u][0]=f[u][1]=0;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa) dfs(e[i], u), f[u][0]+=f[e[i]][0];
	int cnt=0;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa)
		a[++cnt]=max(0ll, f[e[i]][1]+w[i]-f[e[i]][0]);
	nth_element(a+1, a+min(cnt, k), a+cnt+1, greater<int>());
	for(int i=1; i<k && i<=cnt; ++i) f[u][0]+=a[i];
	f[u][1]=f[u][0];
	if(k<=cnt) f[u][0]+=a[k];
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		for(int i=1, x, y, z; i<n; ++i)
			scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
		dfs(1);
		printf("%lld\n", f[1][0]);
		num=0, memset(h+1, 0, n<<2);
	}
	return 0;
}