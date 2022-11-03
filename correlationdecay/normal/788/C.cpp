#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
#define maxn 1009
using namespace std;
const int INF = 1e9;
int n, m;
bool vis[maxn];
int a[maxn], b[maxn], n1, n2;
int tot = 0;
int f[2000009], g[2000009];
bool check(){
	bool ok = 0;
	for(int i = 0; i < n; i++)
		if(vis[i])
			ok = 1;
	if(ok == 0)
		return 0;
	ok = 0;
	for(int i = n + 1; i <= 1000; i++)
		if(vis[i])
			ok = 1;
	return ok;	
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x;
		scanf("%d", &x);
		vis[x] = 1;
	}
	if(vis[n]){
		puts("1");
		return 0;
	}
	if(!check()){
		puts("-1");
		return 0;
	}
	for(int i = n - 1; i >= 0; i--){
		if(vis[i])
			a[++n1] = n - i;
	}
	
	for(int i = n + 1; i <= 1000; i++){
		if(vis[i])
			b[++n2] = i - n;
	}
	
	tot = 1e9;
	
	for(int i = 1; i <= n1; i++)
		for(int j = 1; j <= n2; j++)
			tot = min(tot, (a[i] + b[j]) / __gcd(a[i], b[j]));
			
	f[0] = 0;
	for(int i = 1; i <= tot * a[n1]; i++)
		f[i] = INF;
	for(int i = 1; i <= n1; i++){
		for(int j = a[i]; j <= tot * a[n1]; j++)
			f[j] = min(f[j], f[j - a[i]] + 1);
	}
	
	g[0] = 0;
	for(int i = 1; i <= tot * b[n2]; i++)
		g[i] = INF;
	
	for(int i = 1; i <= n2; i++){
		for(int j = b[i]; j <= tot * b[n2]; j++)
			g[j] = min(g[j], g[j - b[i]] + 1);
	}
	
	int ans = tot;
	
	for(int i = 1; i <= tot * min(a[n1], b[n2]); i++)
		ans = min(ans, f[i] + g[i]);
		
	printf("%d\n", ans);
	return 0;
}