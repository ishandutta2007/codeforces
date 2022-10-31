#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point {
	int x, y;
	point() {}
	point(int _x, int _y) {
		x = _x, y = _y;
	}
};
inline int dist(point a, point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
const int maxn = 14 + 1;
const int maxS = 1 << 14 | 5;
const int maxm = 105;
point a[maxn];
int n, m;
struct task {
	int t;
	point pos;
	task() {}
	task(int _t, point _p) {
		t = _t, pos = _p;
	}
}A[maxm];
int Log[maxS];
int f[maxm][maxS], g[maxm][maxS];
int dis_a[maxn][maxS], dis_b[maxm][maxS];
inline int lowbit(int x) {
	return x & (-x);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0, x, y; i < n; i++)
		scanf("%d%d", &x, &y), a[i] = point(x, y); 
	for(int i = 1, x, y, t; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &t);
		A[i] = task(t, point(x, y));
	}
	sort(A + 1, A + m + 1, [=](task a, task b) -> bool { return a.t < b.t; });
	
	int S = (1 << n) - 1;
	for(int i = 1; i < n; i++)
		Log[1 << i] = i;
	for(int i = 0; i < n; i++)
		dis_a[i][0] = 0x3f3f3f3f;
	for(int i = 1; i <= S; i++) 
		for(int j = 0; j < n; j++)
			if(!((i >> j) & 1)) 
				dis_a[j][i] = min(dis_a[j][i ^ lowbit(i)], dist(a[j], a[Log[lowbit(i)]]));
	for(int i = 1; i <= m; i++) {
		dis_b[i][0] = 0x3f3f3f3f;
		for(int j = 1; j <= S; j++) 
			dis_b[i][j] = min(dis_b[i][j ^ lowbit(j)], dist(A[i].pos, a[Log[lowbit(j)]]));
	}
	
	memset(f, -0x3f, sizeof(f));		
	memset(g, 0x3f, sizeof(g));	
	for(int i = 1; i <= m; i++)
		f[i][0] = 1;
	g[0][0] = 0;
	for(int j = 0; j < n; j++)
		g[0][1 << j] = 0;
	
	int ans = 0;
	for(int i = 0; i <= S; i++) {
		for(int j = 0; j < n; j++)
			if((i >> j) & 1) {
				for(int k = 0; k <= m; k++)	
					g[k][i] = min(g[k][i], g[k][i ^ (1 << j)] + dis_a[j][i ^ (1 << j)]);
			}
			
		for(int j = 1; j <= m; j++) {
			for(int k = 0; k < j; k++)
				if(g[k][i] + dis_b[j][i] <= A[j].t)
					f[j][i] = max(f[j][i], k + 1);
			for(int k = j - 1; k >= 1; k--)
				if(min(dist(A[j].pos, A[k].pos), dis_b[j][i]) <= A[j].t - A[k].t)
					f[j][i] = max(f[j][i], f[k][i] + 1);
			
			if(f[j][i] < 0) continue;
			
			for(int k = 0; k < n; k++)
				if(!((i >> k) & 1))
					g[f[j][i]][i ^ (1 << k)] = min(g[f[j][i]][i ^ (1 << k)], A[j].t + min(dist(A[j].pos, a[k]), dis_a[k][i]));
			
			ans = max(ans, f[j][i]);
		}
	}
	cout << ans << endl;
	return 0;
}