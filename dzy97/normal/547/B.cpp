#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
const int N = 2e5 + 10;
pair<int,int> a[N];
int n, f[N], g[N], vis[N],ans[N];
int gf(int x){
	return (f[x] == x) ? x : (f[x] = gf(f[x]));
}
int un(int x, int y){
	if(gf(x)==gf(y)) return 1;
	g[gf(x)]+=g[gf(y)];
	f[gf(y)]=gf(x);return 0;
}
int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i].first), a[i].second = i;
	for(int i = 1;i <= n;i ++) f[i] = i, g[i]=1;
	sort(a + 1, a + n + 1);
	for(int i=n;i;i--){
		int u=a[i].second;
		vis[u]=1;
		if(u>1 && vis[u-1]) un(u,u-1);
		if(u<n && vis[u+1]) un(u,u+1);
		int v=g[gf(u)];
		ans[v]=max(ans[v],a[i].first);
	}
	for(int i = n - 1;i;i --){
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(int i=1;i<=n;i++) printf("%d%c", ans[i],(i<n)?' ':'\n');
		
		
	return 0;
}