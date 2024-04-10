#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define int long long
using namespace std;
 
inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return op * x;
}
 
inline int readchar() {
	char ch = getchar();
	while (ch < 'A' || 'Z' < ch) ch = getchar();
	return ch;
}
 
const int maxn = 500009;
int t[maxn], a[maxn], b[maxn], ans[maxn], n, m;
vector<pair<int,pair<int,int> > > ask[maxn];
char op;
 
struct decrease {
	int p[maxn], pa[maxn], rk[maxn], last[maxn], meg[maxn];
	
	void init(int n) {
		rep (i, 1, n) {
			p[i] = pa[i] = i; 
			rk[i] = last[i] = meg[i] = 0;
		}
	}
	
	void merge(int t, int a, int b) {
		int x = p[a], y = p[b];
		if (rk[x] < rk[y]) {
			swap(x, y); p[a] = x;
		}
		rk[x] = max(rk[x], rk[y] + 1);
		pa[y] = x; meg[y] = t;
	}
	
	void update(int x, int t) {
		last[p[x]] = t;
	}
	
	int query(int x) {
		int res = 0, low = 0;
		while (pa[x] != x) {
			if (last[x] >= low) res = last[x];
			low = meg[x]; x = pa[x]; 
		}
		if (last[x] >= low) res = last[x];
		return res;
	}
} dec;
 
struct increase {
	int p[maxn], pa[maxn], rk[maxn], s[maxn], size[maxn];
	
	void init(int n) {
		rep (i, 1, n) {
			p[i] = pa[i] = i;
			rk[i] = s[i] = 0;
			size[i] = 1;
		}
	}
	
	void merge(int a, int b) {
		int x = p[a], y = p[b];
		if (rk[x] < rk[y]) {
			swap(x, y); p[a] = x;
		}
		rk[x] = max(rk[x], rk[y] + 1);
		pa[y] = x; s[y] -= s[x];
		size[x] += size[y];
	}
	
	void update(int x) {
		s[p[x]] += size[p[x]];
	}
	
	int query(int x) {
		int res = 0; 
		while (x != pa[x]) {
			res += s[x];
			x = pa[x];
		}
		return res + s[x];
	}
} inc;
 
signed main() {
	n = read(); m = read();
	rep (i, 1, m) {
		op = readchar();
		if (op == 'U') { t[i] = 1; a[i] = read(); b[i] = read(); }
		if (op == 'M') { t[i] = 2; a[i] = read(); b[i] = read(); }
		if (op == 'A') { t[i] = 3; a[i] = read(); }
		if (op == 'Z') { t[i] = 4; a[i] = read(); }
		if (op == 'Q') { t[i] = 5; a[i] = read(); }
	}
	dec.init(n);
	rep (i, 1, m) 
		if (t[i] == 2) dec.merge(i, a[i], b[i]);
		else if (t[i] == 4) dec.update(a[i], i);
		else if (t[i] == 5) {
			ask[dec.query(a[i])].push_back(make_pair(a[i], make_pair(i, -1)));
			ask[i].push_back(make_pair(a[i], make_pair(i, 1)));
		}
	inc.init(n);
	rep (i, 1, m) { 
		if (t[i] == 1) inc.merge(a[i], b[i]);
		else if (t[i] == 3) inc.update(a[i]); 
		if (ask[i].empty()) continue;
		rep (j, 0, ask[i].size()-1) { 
			ans[ask[i][j].second.first] += ask[i][j].second.second * inc.query(ask[i][j].first);
		}
	}
	rep (i, 1, m)
		if (t[i] == 5) printf("%I64d\n", ans[i]);
	return 0;
}