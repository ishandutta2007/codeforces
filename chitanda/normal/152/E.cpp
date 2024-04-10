#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()
#define A(p) id(p.x, p.y)][p.mask

int tag[100][100];
struct node{
	int x, y, mask;
	node() {}
	node(int x, int y, int mask) : x(x), y(y), mask(mask) {}
	node L(){	return node(x, y - 1, mask | tag[x][y - 1]); }
	node R(){ return node(x, y + 1, mask | tag[x][y + 1]); }
	node U(){ return node(x - 1, y, mask | tag[x - 1][y]); }
	node D(){ return node(x + 1, y, mask | tag[x + 1][y]); }
	node operator | (int tmask){
		return node(x, y, mask | tmask);
	}
}last[200][1 << 7];
int f[200][1 << 7];
int a[100][100];
bool inq[200][1 << 7];

int n, m, k;
queue<node> q;

inline bool ckmin(int &a, int b){
	return (a > b) && (a = b);
}

inline int id(int x, int y) { return x * m + y; }

void update(node now, int val, node pre){
	if(ckmin(f[A(now)], val)){
		last[A(now)] = pre;
		if(!inq[A(now)]){
			inq[A(now)] = 1;
			q.push(now);
		}
	}
}

void dfs(int x, int y, int mask){
	node pre = last[id(x, y)][mask];
	tag[x][y] = 1;
	if(!pre.mask) return;
	if(pre.x == x && pre.y == y){
		dfs(x, y, pre.mask);
		dfs(x, y, mask ^ pre.mask);
	}else{
		dfs(pre.x, pre.y, pre.mask);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", a[i] + j);
	
	memset(f, 127, sizeof(f));
	for(int i = 0, x, y; i < k; ++i){
		scanf("%d%d", &x, &y); --x, --y;
		tag[x][y] = 1 << i;
		f[id(x, y)][1 << i] = a[x][y];
		q.push(node(x, y, 1 << i));
		inq[id(x, y)][1 << i] = 1;
	}
	
	while(!q.empty()){
		node t = q.front(); q.pop();
		if(t.x > 0) update(t.U(), f[A(t)] + a[t.x - 1][t.y], t);
		if(t.x < n - 1) update(t.D(), f[A(t)] + a[t.x + 1][t.y], t);
		if(t.y > 0) update(t.L(), f[A(t)] + a[t.x][t.y - 1], t);
		if(t.y < m - 1) update(t.R(), f[A(t)] + a[t.x][t.y + 1], t);
		
		int s = ((1 << k) - 1) ^ t.mask;
		for(int mask = s; mask; mask = (mask - 1) & s)
			if(f[id(t.x, t.y)][mask] < 1e9)
				update(t | mask, f[A(t)] + f[id(t.x, t.y)][mask] - a[t.x][t.y], t);
		
		inq[A(t)] = 0;
	}
	
	int res = 1e9, mx, my;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)	
			if(ckmin(res, f[id(i, j)][(1 << k) - 1]))
				mx = i, my = j;
	
	dfs(mx, my, (1 << k) - 1);
	printf("%d\n", res);
	for(int i = 0; i < n; puts(""), ++i)
		for(int j = 0; j < m; ++j)
			putchar(tag[i][j] ? 'X' : '.');
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}