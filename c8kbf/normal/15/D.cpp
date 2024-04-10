#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, m, x, y, a[maxn][maxn], p[maxn][maxn];
deque<_> q[maxn], c;
struct sq {
	_ x, y, c;
	bool operator < (const sq &b) const {
		if(c != b.c) return c < b.c;
		if(x != b.x) return x < b.x;
		return y < b.y;
	}
};
vector<sq> g, o;
bool v[maxn][maxn];

_ sm(_ xa, _ ya, _ xb, _ yb);
int main() {
	
	scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) scanf("%lld", &a[i][j]);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) p[i][j] = p[i-1][j]+a[i][j];
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) p[i][j] += p[i][j-1];
	for(_ i = 1; i <= n; ++i) {
		for(_ j = 1; j <= m; ++j) {
			for(; !q[j].empty() && i-q[j].front() >= x; ) q[j].pop_front();
			for(; !q[j].empty() && a[q[j].back()][j] >= a[i][j]; ) q[j].pop_back();
			q[j].push_back(i);
		}
//		printf("q: ");
//		for(_ j = 1; j <= m; ++j) printf("%lld ", q[j].front());
//		putchar(10);
		if(i >= x) {
			c.clear();
			for(_ j = 1; j <= m; ++j) {
				for(; !c.empty() && j-c.front() >= y; ) c.pop_front();
				for(; !c.empty() && a[q[c.back()].front()][c.back()] >= a[q[j].front()][j]; ) c.pop_back();
				c.push_back(j);
				if(j >= y) {
					g.push_back((sq){i-x+1, j-y+1, sm(i-x+1, j-y+1, i, j)-x*y*a[q[c.front()].front()][c.front()]});
//					printf("add: %lld %lld %lld %lld\n", i-x+1, j-y+1, a[c.front()][q[c.front()].front()], c.front());
				}
			}
		}
	}
	sort(g.begin(), g.end());
	for(sq i : g) {
		if(v[i.x][i.y] || v[i.x+x-1][i.y] || v[i.x][i.y+y-1] || v[i.x+x-1][i.y+y-1]) continue;
		o.push_back(i);
		for(_ j = i.x; j <= i.x+x-1; ++j) for(_ k = i.y; k <= i.y+y-1; ++k) v[j][k] = true;
	}
	printf("%lld\n", (_)o.size());
	for(sq i : o) printf("%lld %lld %lld\n", i.x, i.y, i.c);
	
	return 0;
}

_ sm(_ xa, _ ya, _ xb, _ yb) {
	return p[xb][yb]-p[xa-1][yb]-p[xb][ya-1]+p[xa-1][ya-1];
}