#include <bits/stdc++.h>

#define MAXN (200010)

struct edge{
	int a, b, w;
	bool operator < (const edge &rhs) const {
		return w > rhs.w;
	}
}e[MAXN];
int n, m;
int fa[MAXN], hasCircle[MAXN];

int getfather(int x){
	return x == fa[x] ? x : (fa[x] = getfather(fa[x]));
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	for(int i = 1; i <= m; ++ i){
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
	}
	std::sort(e + 1, m + e + 1);
	
	int ans = 0;
	for(int i = 1; i <= m; ++ i){
		int u = getfather(e[i].a);
		int v = getfather(e[i].b);
		if(u == v){
			if(hasCircle[u] == 0){
				hasCircle[u] = 1;
				ans += e[i].w;
			}
		}
		else if(hasCircle[u] + hasCircle[v] <= 1){
			fa[u] = v;
			hasCircle[v] += hasCircle[u];
			ans += e[i].w;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}