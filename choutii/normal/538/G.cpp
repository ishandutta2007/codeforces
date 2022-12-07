#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

LL read() {
	LL x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234;
int n, L;

LL floor(LL a, LL b) {
	return (a - (a % b + b) % b) / b;
}

LL ceil(LL a, LL b) {
	return (a + (b - a % b) % b) / b;
} 

struct info {
	LL t, k, x;
	info() {
	}
	info(LL t, LL k, LL x) : t(t), k(k), x(x) {
	}
};

vector <info> xr, yr;

VI solve(vector <info> v) {
	sort(ALL(v), [&] (info x, info y) {return x.t < y.t; });
	v.pb(info(L, -1, 0));
	LL L = 0, R = ::L;
	info prv(0, 0, 0);
	for (auto cur : v) {
		LL dk = cur.k - prv.k;
		LL dx = cur.x - prv.x;
		LL dt = cur.t - prv.t;
		if(!dk) 
			if(dx < 0 || dx > dt) 
				puts("NO"), exit(0);
		 if(dk > 0) 
			cmax(L, ceil(dx - dt, dk)), cmin(R, floor(dx, dk));
		if(dk < 0) 
			cmax(L, ceil(dx, dk)),	cmin(R, floor(dx - dt, dk));
		prv = cur;
	}
	
	if(L > R) 
		puts("NO"), exit(0);
	
	VI ans(::L);
	LL ct = 0, cs = 0;
	for (auto cur : v) {
		LL p = cur.x - L * cur.k;
		if(cur.t == ct && p != cs) 
			puts("NO"), exit(0);
		for (int i = ct; i < ct + p - cs; i++)
			ans[i] = 1;
		ct = cur.t; cs = p;
	}
	return ans;
}

int main() {
	n = read(); L = read();
	for (int i = 1; i <= n; i++) {
		LL t, x, y;
		t = read(); x = read(); y = read();
		LL rx = x + y;
		LL ry = x - y;
		if(rx + t & 1)
			return puts("NO"), 0;
		xr.pb(info(t % L, t / L, rx + t >> 1));
		yr.pb(info(t % L, t / L, ry + t >> 1));
	}
	
	VI x = solve(xr);
	VI y = solve(yr);
	
	for (int i = 0; i < L; i++) {
		if(x[i] && y[i])
			putchar('R');
		if(x[i] && !y[i])
			putchar('U');
		if(!x[i] && y[i])
			putchar('D');
		if(!x[i] && !y[i])
			putchar('L');
	} 
	return 0;
}