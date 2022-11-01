#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;

int n, m;

int fa[maxn];
int f[maxn];

struct ex {
	int x, y;
};

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int join(int x, int y){
	int ra = find(x);
	int rb = find(y);
	if(ra != rb){
		fa[rb] = ra;
		f[ra] = max(f[ra], f[rb]);
	}
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		fa[i] = i;
		f[i] = i;
	}
	
	for(i=1;i<=m;i++){
		scanf("%d%d", &x, &y);
		join(x, y);
	}
	
	x = 1;
	int ans = 0;
	
	for(i=2;i<=n;i++){
		if(f[find(x)] < i)x = i;
		if(find(x) != find(i)){
			ans++;
			join(x, i);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}