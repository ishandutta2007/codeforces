#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 105
int p[N * 2], n1[N * 2], w[N * 2], h[N], ee, Min[N], Max[N], ch[N][2], n, m;

void ae(int x, int y, int z){
	p[ee] = y; n1[ee] = h[x]; w[ee] = z; h[x] = ee ++;
}

void imp(){
	printf("IMPOSSIBLE\n");
	exit(0);
}

void solve(int l, int r){
	int mx = 0, mn = 1e9;
	for(int i = l;i <= r;i ++) mx = max(Max[i], mx), mn = min(Min[i], mn);
	if(mx > r || mn < l) imp();
	if(l == r) return;
	int le = l, md = l;
	for(int i = h[l];~i;i = n1[i]) if(!w[i]) le = max(le, p[i]);
	for(int i = l + 1;i <= le;i ++) md = max(md, Max[i]);
	while(le < md) ++ le, md = max(md, Max[le]);
	for(int i = h[l];~i;i = n1[i]) if(w[i] && p[i] <= le) imp();
	if(le != l) ch[l][0] = l + 1, solve(l + 1, le);
	if(le != r) ch[l][1] = le + 1, solve(le + 1, r);
}

void out(int u){
	if(!u) return;
	out(ch[u][0]);
	printf("%d ", u);
	out(ch[u][1]);
}

int main(){
	scanf("%d%d", &n, &m);
	memset(Min, 63, sizeof(Min));
	int x, y;
	memset(h, -1, sizeof(h));
	char op[7];
	for(int i = 1;i <= m;i ++){
		scanf("%d%d%s", &x, &y, op);
		if(x >= y) imp();
		ae(x, y, op[0] == 'R');
		Min[x] = min(Min[x], y);
		Max[x] = max(Max[x], y);
	}
	solve(1, n);
	out(1);
	return 0;
}