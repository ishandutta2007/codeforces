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

const int MaxN = 101234, P = 1000000007;

int n; pair<int, int> p[MaxN];
map<int, vector<int> > ex, ey;

int p2[MaxN], f[MaxN];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool c[MaxN];
void merge(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) c[x] = 1; else f[x] = y;
}

set <int> X[MaxN], Y[MaxN];

int main() {
	int i;
	n = inp();
	for(i = 0; i < MaxN; i++) p2[i] = i ? (p2[i - 1] * 2) % P : 1; 
	for(i = 1; i <= n; i++) {
		f[i] = i;
		int x = inp(), y = inp();
		p[i] = make_pair(x, y);
		ex[x].push_back(i); ey[y].push_back(i);
	}
	
	for(auto z : ex) for(i = 0; i < z.sec.size() - 1; i++) 
		merge(z.sec[i], z.sec[i + 1]);
	
	for(auto z : ey) for(i = 0; i < z.sec.size() - 1; i++) 
		merge(z.sec[i], z.sec[i + 1]);
		
	for(i = 1; i <= n; i++) {
		int p = find(i);
		c[p] |= c[i];
		X[p].insert(::p[i].fir); 
		Y[p].insert(::p[i].sec);
	}
	
	int ans = 1;
	for(i = 1; 	i <= n; i++) if(f[i] == i) {
		int t = X[i].size() + Y[i].size();
		ans = (LL) ans * (p2[t] - (bool)!c[i]) % P;
	}
	
	cout << ans;
	return 0;
}