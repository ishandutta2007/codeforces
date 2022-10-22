#include <bits/stdc++.h>

#define MAXN (100010)
#define ll long long
#define mod (1000000009)

int sig(ll p) {
	return (p > 0) - (p < 0);
}

class P {
public:
	ll x, y;
	P (ll x = 0, ll y = 0) : x(x), y(y) {}
	P operator - (const P &p) const { return P (x - p.x, y - p.y); }
	ll operator ^ (const P &p) const { return x * p.y - y * p.x; }
	ll operator % (const P &p) const { return (x % mod * p.x % mod + y % mod * p.y % mod) % mod; }
	bool operator < (const P &p) const {
		if (sig(x - p.x)) return x < p.x;
		return y < p.y;
	}
	void read() {
		scanf("%lld%lld", &x, &y);
	}
	ll len() {
		return x * x + y * y;
	}
};

class L {
public:
	P p, v;
	L (P a, P b):p(a), v(b - a) {}
};

ll onLeft(L l, P p) {
	return l.v ^ (p - l.p);
}

std::vector <P> convexHull(std::vector <P> &ps){ //
	static P stack[MAXN];
	std::sort(ps.begin(), ps.end());
	int n = ps.size(), top = 0;
	for (int i = 0; i < n; ++ i){
		while (top > 1 && sig(onLeft(L (stack[top - 2], stack[top - 1]), ps[i])) <= 0){
			-- top;
		}
		stack[top ++] = ps[i];
	}
	int tmp = top;
	for (int i = n - 2; i >= 0; -- i){
		while (top > tmp && sig(onLeft(L (stack[top - 2], stack[top - 1]), ps[i])) <= 0){
			-- top;
		}
		stack[top ++] = ps[i];
	}
	if (n > 1) -- top;
	std::vector <P> ret;
	for (int i = 0; i < top; ++ i){
		ret.push_back(stack[i]);
	}
	return ret;
}

struct KMP{
    int fail[MAXN];

    bool searchForm(std::vector<std::pair<ll, int> > &s, std::vector<std::pair<ll, int> > &t){
    	int n = t.size(), m = s.size();
    	
    	fail[0] = -1;
    	for (int i = 1, j = -1; i <= m; ++i) {
    		while (j >= 0 && s[j] != s[i - 1]) j = fail[j];
    		fail[i] = ++ j;
    	}
    	
        for(int i = 0, j = 0; i < n + n; ++ i){
        	auto ti = i < n ? t[i] : t[i - n];
            while(j >= 0 && s[j] != ti) j = fail[j];
            if(++ j == m) return true;
        }
        return false;
    }
}kmp;

int powmod(int a, int b) {
	int ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = 1ll * ret * a % mod;
		a = 1ll * a * a % mod;
	}
	return ret;
}

int angle(P a, P b) {
	return (a % b) % powmod(a.len(), mod - 2) % mod * powmod(b.len(), mod - 2) % mod;
}

int n, m;
std::vector<P> blue, red;

int main() {
	scanf("%d%d", &n, &m);
	blue.resize(n);
	red.resize(m);
	for (int i = 0; i < n; ++i) blue[i].read();
	for (int i = 0; i < m; ++i) red[i].read();
	blue = convexHull(blue);
	red = convexHull(red);
	std::vector<std::pair<ll, int> > s, t;
	n = blue.size();
	m = red.size();
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n, k = (j + 1) % n;
		s.push_back({(blue[j] - blue[i]).len(), angle(blue[j] - blue[i], blue[k] - blue[j])});
	}
	for (int i = 0; i < m; ++i) {
		int j = (i + 1) % m, k = (j + 1) % m;
		t.push_back({(red[j] - red[i]).len(), angle(red[j] - red[i], red[k] - red[j])});
	}
	printf(kmp.searchForm(s, t) ? "YES\n" : "NO\n");
	return 0;
}