#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
#define debug(x) cerr << #x" = " << x << endl

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T, typename TT> ostream & operator << (ostream &out, pair<T, TT> t) { return out << "(" << t.X << "," << t.Y << ")";}
template <typename T> ostream & operator << (ostream &out,vector<T> t) { out << "["; for (auto x:t) out << x << " "; out << "]"; return out;}
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int NX = 200005, MX = NX << 1, ZX = 26;;

int n, pos[MX]; char s[NX]; VI edge[MX];

namespace sam{
	int ch[MX][ZX], par[MX], mx[MX], mark[MX], lst = 1, cnt = 1;
	void add(int x) {
		int p = lst, np = lst = ++cnt;
		pos[np] = mx[np] = mx[p] + 1; mark[np] = 1; 
		while(!ch[p][x] && p) ch[p][x] = np, p = par[p];
		if (!p) par[np] = 1;
		else {
			int q = ch[p][x];
			if(mx[q] == mx[p] + 1) {
				par[np] = q; 
			} else {
				int nq = ++cnt; mx[nq] = mx[p] + 1;
				memcpy(ch[nq], ch[q], sizeof(ch[q]));
				pos[nq] = pos[np]; par[nq] = par[q]; par[q] = par[np] = nq;
				while(ch[p][x] == q)
					ch[p][x] = nq, p = par[p];
			}
		}
	}  
}

namespace seg{
	int lc[MX * 40], rc[MX * 40], rot[MX], segn;
	int add(int u, int v) {
		if(!u || !v) return u + v;
		int p = ++segn;
		lc[p] = add(lc[u], lc[v]);
		rc[p] = add(rc[u], rc[v]);
		return p;
	}
	void add(int &p, int q, int l, int r, int x) {
		p = ++segn; lc[p] = lc[q]; rc[p] = rc[q];
		if(l == r) return;
		int o = l + r >> 1;
		if(x <= o) 	add(lc[p], lc[q], l, o, x);
		else add(rc[p], rc[q], o + 1, r, x);	
	}
	bool check(int p, int l, int r, int ql, int qr) {
		if(!p || ql > r || qr < l) return false;
		if(ql <= l && r <= qr) return true;
		int o = l + r >> 1;
		return check(lc[p], l, o, ql, qr) | 
				check(rc[p], o + 1, r, ql, qr);
	} 
	
	void dfs(int x) {
		for (int y : edge[x]) 
			dfs(y), rot[x] = add(rot[x], rot[y]);
		if(sam::mark[x]) 
			add(rot[x], rot[x], 1, n, pos[x]);
	}
}

int dp[MX];

void dfs(int x, int p) {
	for (int y : edge[x]) {
		int u = pos[y] - sam::mx[y] + sam::mx[p];
		int v = pos[y] - 1;
		if (!seg::check(seg::rot[p], 1, n, u, v)) {
			dfs(y, p);
		} else 
			dp[y] = dp[p] + 1, dfs(y, y); 
	}
}

int main() {
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++) 
		sam::add(s[i] - 'a');
	for (int i = sam::cnt; i > 1; i--)
		edge[sam::par[i]].pb(i);
	
	seg::dfs(1);
	
	for (int u : edge[1])
		dp[u] = 1, dfs(u, u);
	
	int ans = *max_element(dp + 1, dp + sam::cnt + 1);
	cout << ans << "\n";
	return 0;
}