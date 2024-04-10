#include <bits/stdc++.h>

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef long double db;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
struct Point {
	LL x, y;
	Point() { x = y = 0; }
	Point(LL a, LL b) { x = a, y = b; }
	LL operator ^ (Point b) const { return x * b.y - y * b.x; }
	LL operator * (Point b) const { return x * b.x + y * b.y; }
	LL length() const { return x * x + y * y; }
	db slen() const { return sqrt(x * x + y * y); }
	Point operator - (Point b) const { return Point(x - b.x, y - b.y); }
	Point operator + (Point b) const { return Point(x + b.x, y + b.y); }
	Point operator * (db k) const { return Point(x * k, y * k); }
	friend std::istream & operator >> (std::istream & in, Point & x) {
		in >> x.x >> x.y;
		return in;
	}
	bool operator < (Point b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	Point slope() const {
		if (!x && !y) return *this;
		LL g = gcd(x, y);
		Point res = *this;
		if (g < 0) g = -g;
		res.x /= g, res.y /= g;
		return res;
	}
	bool isinf() { return x == INF; }
} ps[MAXN], ks[10];
const Point del(INF, INF);
int K, n;
typedef std::vector<int> vp;
vp to[8][MAXN];

bool vis[10], killed[MAXN], inn[10][MAXN];
bool dfs(int S, vp li) {
	if (!li.size()) return true;
	if (S == 0) return false;
	int tar = li.back();
	bool * ins = inn[S];
	for (auto t : li) ins[t] = true;
	bool Res = false;
	for (int i = 1; i <= K; ++i) if (!vis[i]) {
		bool can = true;
		int tsz = li.size();
		vp tl;
		for (auto t : to[i][tar]) if (!killed[t]) {
			tsz += !ins[t];
			if (tsz > S + 1) { can = false; break; }
			if (!ins[t]) tl.push_back(t);
		}
		if (!can) continue;
		killed[tar] = true; vis[i] = true;
		vp tv;
		for (auto t : li) if (!killed[t]) tv.push_back(t);
		for (auto t : tl) if (!killed[t]) tv.push_back(t);
		bool rt = dfs(S - 1, tv);
		killed[tar] = false; vis[i] = false;
		if (rt) { Res = true; break; }
	}
	for (auto t : li) ins[t] = false;
	return Res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> K >> n;
	for (int i = 1; i <= K; ++i) std::cin >> ks[i];
	for (int i = 1; i <= n; ++i) std::cin >> ps[i];
	for (int i = 1; i <= K; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				if (j != k && !((ps[k] - ps[j]) ^ (ks[i] - ps[k])))
					if (fabsl((ks[i] - ps[j]).slen() + (ps[j] - ps[k]).slen() - (ks[i] - ps[k]).slen()) < 1e-6)
						to[i][k].push_back(j);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += dfs(K, vp(1, i));
	std::cout << ans << std::endl;
	return 0;
}