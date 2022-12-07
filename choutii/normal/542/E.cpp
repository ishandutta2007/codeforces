#include<bits/stdc++.h>

using namespace std;

typedef double db;

const int MaxN = 1234, MaxM = 201234;

int n, m;

struct edge {
	int to, nxt;
}e[MaxM]; int cnt, lst[MaxN];

void ins(int a, int b) {
	e[++cnt] = (edge){b, lst[a]}; lst[a] = cnt;
}

void insert(int a, int b) {
	ins(a, b); ins(b, a);
}

int col[MaxN], vis[MaxN], T;

bool dfs(int x) {
	for(int i = lst[x], b; b = e[i].to, i; i = e[i].nxt) {
		if(!vis[b]) {
			vis[b] = T; 
			col[b] = col[x] ^ 1;
			if(!dfs(b)) return 0;
		} else {
			if(col[b] == col[x]) return 0;
		}
	}
	return 1;
}

int dmt = 0, T_, dis[MaxN], inq[MaxN]; queue<int>q;
int bfs(int x) {
	q.push(x); dis[x] = 0; inq[x] = ++T_;
	while(!q.empty()) {
		int c = q.front(); q.pop(); dmt = max(dmt, dis[c]);
		for(int i = lst[c], b; b = e[i].to, i; i = e[i].nxt) {
			if(inq[b] != T_) {
				dis[b] = dis[c] + 1; inq[b] = T_;
				q.push(b);
			}
		}
	}
}

#define gg return puts("-1"), 0;
int main() {
 	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		insert(u, v);
	}	
	
	int ans = 0;
	for(i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = ++T;
			if(!dfs(i)) gg
			dmt = 0;
			for(j = 1; j <= n; j++) if(vis[j] == T) bfs(j); 
			ans += dmt;
		}
	}
	
	cout << ans << endl;
	return 0;
}