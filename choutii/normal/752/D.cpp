#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;
const int p1 = 1000000007, p2 = 1000000009;

int K, n; string s[MaxN];
map<LL, vector<LL> > m;
map<LL, LL> rev;

int main() {
	int i, j;
	K = inp(); n = inp();
	for(i = 1; i <= K; i++) {
		LL x;
		cin >> s[i] >> x;
		LL h1 = 0, h2 = 0;
		for(j = 0; j < s[i].size(); j++) {
			h1 = (h1 * 233  + s[i][j]) % p1;
			h2 = (h2 * 233  + s[i][j]) % p2;
		}
		LL g1 = 0, g2 = 0;
		for(j = s[i].size() - 1; ~j; j--) {
			g1 = (g1 * 233  + s[i][j]) % p1;
			g2 = (g2 * 233  + s[i][j]) % p2;
		}
		
		LL A = h1 * p2 + h2;
		LL B = g1 * p2 + g2;
		m[A].push_back(x); rev[A] = B;
	}
	for(auto & p : m) sort(p.sec.begin(), p.sec.end());
	
	LL ans = 0, cent = 0;
	for(auto & p : m) {
		LL x = p.fir;
		vector<LL> & v = p.sec;
		if(x == rev[x]) {
			LL X = -1e16, Y = -1e16;
			while(v.size() >= 2 && v[v.size() - 2] + v[v.size() - 1] >= 0)
				X = v[v.size() - 1], Y = v[v.size() - 2], ans += v[v.size() - 2] + v[v.size() - 1], v.pop_back(), v.pop_back();
			if(X > -1e16) cmax(cent, -Y);
			if(v.size()) cmax(cent, v.back()); 	
		}
		else if(x < rev[x]) {
			vector<LL> y = m[rev[x]];
			while(y.size() && v.size() && v.back() + y.back() >= 0)
				ans += y.back() + v.back(), y.pop_back(), v.pop_back();
		}
	}
	cout << ans + cent;
	return 0;
}