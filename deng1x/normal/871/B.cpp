#include <bits/stdc++.h>

#define MAXN (100100)

int ans;
int n;
int pb[MAXN], bb[MAXN];
int a[MAXN], b[MAXN], p[MAXN];
bool vis[MAXN];

int ask(int i, int j){
	printf("? %d %d\n", i, j);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

bool check(int x){
	memset(vis, 0, sizeof(vis));
	b[0] = x;
	vis[x] = 1;
	for(int i = 1; i < n; ++ i){
		int y = bb[i - 1] ^ b[i - 1];
		if(vis[y]) return false;
		vis[y] = 1;
		b[i] = y;
	}
	int y = bb[n - 1] ^ b[n - 1];
	if(y != x) return false;
	
	for(int i = 0; i < n; ++ i) p[b[i]] = i;
	for(int i = 0; i < n; ++ i){
		if((p[i] ^ b[i]) != pb[i]){
			return false;
		}
	}
	
	if(!ans){
		for(int i = 0; i < n; ++ i) a[i] = p[i];
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i){
		pb[i] = ask(i, i);
	}
	for(int i = 0; i < n; ++ i){
		int x = ask(i, (i + 1) % n);
		bb[i] = pb[i] ^ x;
	}
	
	for(int i = 0; i < n; ++ i){
		ans += check(i);
	}
	printf("!\n%d\n", ans);
	for(int i = 0; i < n; ++ i){
		printf("%d%c", a[i], " \n"[i == n - 1]);
	}
	return 0;
}