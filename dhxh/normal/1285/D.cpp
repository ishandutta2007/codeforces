#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;
int nxt[maxn * 32][2];
int root = 1;
int tc = 1;
int f[maxn * 32];

int getn(int x, int y){
	return (x >> y) & 1;
}

int insert(int x){
	int pos = root;
	
	for(int i=30;i>=0;i--){
		int p = getn(x, i);
		if(!nxt[pos][p]){
			nxt[pos][p] = ++tc;
		}
		pos = nxt[pos][p];
	}
	
	return 0;
}

int dfs(int pos, int x){
	if(x == -1)return 0;
	
	if(!nxt[pos][0]){
		f[pos] = min(f[pos], dfs(nxt[pos][1], x - 1));
	}else if(!nxt[pos][1]){
		f[pos] = min(f[pos], dfs(nxt[pos][0], x - 1));
	}else{
		f[pos] = min(dfs(nxt[pos][1], x - 1), dfs(nxt[pos][0], x - 1)) + (1 << x);
	}
	
	return f[pos];
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &x);
		insert(x);
	}
	
	memset(f, 0x7f, sizeof(f));
	
	dfs(root, 30);
	
	printf("%d\n", f[root]);
	
	return 0;
}