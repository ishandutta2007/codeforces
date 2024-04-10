#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const int N = 5000;
int a[N], b[N], c[N], d[N];
set<int> x, y;
map<int,int> xmap, ymap;

//2d fenwick tree, 1-indexed
template <class T>
struct bit_2d {
	int N,M;
	vector<vector<T>> b;

	void init(int n, int m){N=n+1,M=m+1,b=vector<vector<T>>(N,vector<T>(M));}
	bit_2d(){}
	bit_2d(int n, int m){init(n,m);}

	inline void update(int i, int j, T v) {
		for(;i < N; i += i&-i) {
			for(int k = j; k < M; k += k&-k) {
				b[i][k] += v;
			}
		}
	}

	//sum of the 'prefix' i x j rectangle
	inline T prefix(int i, int j) {
		T a = 0;
		for(;i;i ^= i&-i)
			for(int k = j;k;k ^= k&-k)
				a += b[i][k];
		return a;
	}

	inline T query(int a, int b, int c, int d) {
		return prefix(c,d)+prefix(a-1,b-1)-prefix(a-1,d)-prefix(c,b-1);
	}
};

struct event {
	// 0 = start hor at a --> at height b
	// 1 = query vert --> query [b, c]
	// 2 = end hor at a --> at height b
	int type, a, b, c;
	event(){}
	event(int x, int y, int z, int w) {
		type = x;
		a = y;
		b = z;
		c = w;
	}

	inline int when() {
		if(type == 2) return b;
	}

	bool operator<(const event& e) const {
		if(a == e.a)
			return type < e.type;
		return a < e.a;
	}
};

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int hor = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		if(a[i] > c[i] || b[i] > d[i]) {
			swap(a[i], c[i]);
			swap(b[i], d[i]);
		}
		x.insert(a[i]);
		x.insert(c[i]);
		y.insert(b[i]);
		y.insert(d[i]);
		hor += b[i] == d[i];
	}
	int ver = n-hor;
	if(ver > hor) {
		swap(x, y);
		for(int i = 0; i < n; ++i) {
			swap(a[i], b[i]);
			swap(c[i], d[i]);
		}
	}
	int mxx = 0;
	for(int xv : x)
		xmap[xv] = ++mxx;
	int mxy = 0;
	for(int yv : y)
		ymap[yv] = ++mxy;
	bit_2d<int> B(mxx+1, mxy+1);
	vector<event> E;
	for(int i = 0; i < n; ++i) {
		a[i] = xmap[a[i]];
		b[i] = ymap[b[i]];
		c[i] = xmap[c[i]];
		d[i] = ymap[d[i]];
		if(b[i] == d[i]) {
			// hor
			E.emplace_back(0, a[i], b[i], 0);
			E.emplace_back(2, c[i], a[i], b[i]);
		} else {
			E.emplace_back(1, a[i], b[i], d[i]);
		}
	}
	sort(E.begin(), E.end());
	vector<event> P;
	ll ans = 0;
	for(const auto& e : E) {
		if(e.type == 0) {
			B.update(e.a, e.b, 1);
		} else if(e.type == 1) {
			const int s1 = e.b;
			const int e1 = e.c;
			for(const auto& f : P) {
				if(f.a == e.a) break;
				const int s2 = f.b;
				const int e2 = f.c;
				const int s = max(s1, s2);
				const int e = min(e1, e2);
				if(s >= e) continue;
				const ll amt = B.prefix(f.a, e) - B.prefix(f.a, s-1);
				ans += amt * (amt-1) / 2;
			}
			P.push_back(e);
		} else if(e.type == 2) {
			B.update(e.b, e.c, -1);
		}
	}
	cout << ans << '\n';
}