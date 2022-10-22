#include <bits/stdc++.h>

#define MAXN (300010)

int n;
int fa[MAXN], sz[MAXN];

int getfather(int x){
	if(!fa[x]) return 0;
	return x == fa[x] ? x : (fa[x] = getfather(fa[x]));
}

int main(){
	scanf("%d", &n);
	printf("1");
	for(int i = 1; i <= n; ++ i){
		int x;
		scanf("%d", &x);
		fa[x] = x;
		sz[x] = 1;
		int l = getfather(x - 1), r = getfather(x + 1);
		if(l){
			fa[x] = l;
			sz[l] += sz[x];
			x = getfather(x);
		}
		if(r){
			fa[x] = r;
			sz[r] += sz[x];
			x = getfather(x);
		}
		printf(" %d", i - sz[getfather(n)] + 1);
	}
	puts("");
	return 0;
}