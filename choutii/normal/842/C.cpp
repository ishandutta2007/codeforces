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

const int MaxN = 201234;
set <int> s[MaxN];
vector <int> e[MaxN];
int n, a[MaxN];

int gcd(int x, int y) {
	return (x && y) ? __gcd(x, y) : x + y;
}

int rot[MaxN], ans[MaxN];
void dfs(int x, int fa = -1) {
	for(auto c : s[x]) cmax(ans[x], c);
	cmax(ans[x], rot[x]);
	for(auto y : e[x]) {
		if(y == fa) continue;
		rot[y] = gcd(rot[x], a[y]);
		for(auto c : s[x]) 
			s[y].insert(gcd(c, a[y]));
		s[y].insert(rot[x]);
		dfs(y, x);
	}
} 

int main() { 
	int i;
	n = inp();
	for(i = 1; i <= n; i++) a[i] = inp();
	for(i = 1; i < n; i++) {
		int u = inp(), v = inp();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	s[1].insert(0);
	rot[1] = ans[1] = a[1];
	for(auto y : e[1]) {
		rot[y] = gcd(rot[1], a[y]);
		for(auto c : s[1]) 
			s[y].insert(gcd(c, a[y]));
		s[y].insert(rot[1]);
		dfs(y, 1);
	}
	
	for(i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}