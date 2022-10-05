/*
nm
Ai,BiAi
Bi
,
*/
#include<bits/stdc++.h>
#define pos first
#define val second.first
#define rk second.second
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef pair<int,pair<int,int> > P;

const int maxn = 800009;
int c[maxn], h[maxn], x[maxn], ans[maxn], pre[maxn], suf[maxn];
int n, Q, m, p, LIS, vis[maxn], res[maxn]; P q[maxn];

int del(){
	int n = 1;
	for (int i=2; i<=m; i++)
		if (x[i-1] != x[i]) x[++n] = x[i];
	return n;
}

int search(int k){
	int l = 1, r = m, mid;
	while (l < r){
		mid = (l + r) >> 1;
		if (k <= x[mid]) r = mid;
		else l = mid+1;
	}
	return l;
}

void update(int x, int y){
	for (; x<=m; x+=lowbit(x)) c[x] = max(c[x], y);
}

int query(int x){
	int res = 0; for (; x; x-=lowbit(x)) res = max(res, c[x]); return res;
}

int main(){
	scanf("%d%d", &n, &Q);
	for (int i=1; i<=n; i++){
		scanf("%d", &h[i]); x[++m] = h[i];
	}
	for (int i=1; i<=Q; i++){
		scanf("%d%d", &q[i].pos, &q[i].val);
		x[++m] = q[i].val; q[i].rk = i;
	}
	
	sort(x+1, x+m+1); m = del();
	for (int i=1; i<=n; i++) h[i] = search(h[i]);
	for (int i=1; i<=Q; i++) q[i].val = search(q[i].val);
	
	sort(q+1, q+Q+1); p = 1;
	for (int i=1; i<=n; i++){
		while (p <= Q && q[p].pos == i){
			ans[q[p].rk] += query(q[p].val-1)+1;
			p++;
		}
		update(h[i], pre[i] = query(h[i]-1)+1);
		LIS = max(LIS, pre[i]);
	}
	memset(c, 0, sizeof c); p = Q;
	for (int i=n; i>=1; i--){
		while (1 <= p && q[p].pos == i){
			ans[q[p].rk] += query(m-q[p].val);
			p--;
		}
		update(m-h[i]+1, suf[i] = query(m-h[i])+1);
	}
	
	for (int i=1; i<=n; i++)
		if (pre[i] + suf[i] == LIS+1) vis[pre[i]]++;	
	for (int i=1; i<=Q; i++)
		ans[q[i].rk] = max(ans[q[i].rk], LIS - 
			(pre[q[i].pos] + suf[q[i].pos] == LIS+1 && vis[pre[q[i].pos]] == 1));
	for (int i=1; i<=Q; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}