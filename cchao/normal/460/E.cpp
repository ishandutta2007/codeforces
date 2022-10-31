#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
	P (int x = 0, int y = 0): x(x), y(y) {}
	P operator+(const P &r) const { return P(x+r.x, y+r.y); }
	P operator-(const P &r) const { return P(x-r.x, y-r.y); }
	int operator*(const P &r) const { return x*r.x + y*r.y; }
	int operator^(const P &r) const { return x*r.y - y*r.x; }
	bool operator<(const P &r) const { return tie(x, y) < tie(r.x, r.y); }
	bool operator==(const P &r) const { return tie(x, y) == tie(r.x, r.y); }
};
int crx(P a, P b) { return a^b; }
vector<P> ConvexHull(vector<P> p) {
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	int n = p.size(), m = 0;
	vector<P> ch(n + 1);
	for(int i = 0; i < n; ++i) {
		while(m > 1 && crx(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n - 2; i >= 0; --i) {
		while(m > k && crx(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
	ch.resize(m);
	return ch;
}
int n, r;
vector<P> v;
int mx, tmp;
vector<P> ans, cur;
inline int sq(int x) { return x * x; }
void dfs(int iter, int lst, int sx, int sy, int ssx, int ssy) {
	if(iter == n) {
		if(tmp > mx) {
			mx = tmp;
			ans = cur;
		}
		return ;
	}
	for(; lst < v.size(); ++lst) {
		int x = v[lst].x;
		int y = v[lst].y;
		int tx = iter*x*x - 2*x*sx + ssx;
		int ty = iter*y*y - 2*y*sy + ssy;
		tmp += tx+ty;
		cur.push_back(v[lst]);
		dfs(iter+1, lst, sx+x, sy+y, ssx+sq(x), ssy+sq(y));
		cur.pop_back();
		tmp -= tx+ty;
	}
}
int main() {
	scanf("%d%d", &n, &r);
	for(int i = -r; i <= r; ++i) for(int j = -r; j <= r; ++j)
		if(i * i + j * j <= r * r)
			v.emplace_back(i, j);
	v = ConvexHull(v);
	mx = tmp = 0;
	dfs(0, 0, 0, 0, 0, 0);
	printf("%d\n", mx);
	for(P p: ans) printf("%d %d\n", p.x, p.y);
	return 0;
}