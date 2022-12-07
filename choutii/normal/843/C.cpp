#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234;

int n, siz[MaxN]; 
vector<int> e[MaxN];
vector<pair<int, int>> v;
vector<pair<int, pair<int, int>>> ans;

void Siz(int x, int fa = 0) {
	siz[x] = 1;
	for(auto y : e[x]) 	
		if(y != fa) 
			Siz(y, x), siz[x] += siz[y];
}

int par;
int Cent(int x, int fa = 0) {
	for(auto y : e[x]) 
		if(y != fa) 
			if(siz[y] > n / 2)
				return Cent(y, x);
	par = fa; return x;
}

void dfs(int x, int fa = 0) {
	for(auto y : e[x]) 
		if(y != fa) 
			dfs(y, x);
	v.push_back(make_pair(x, fa));			
}

void Ans(int x, int fa = 0) {
	v.clear();
	dfs(x, fa);
	v.pop_back();
	int t = x;
	for(auto y : v) {
		ans.push_back(make_pair(fa, make_pair(t, y.fir)));
		ans.push_back(make_pair(y.fir, make_pair(y.sec, x)));
		t = y.fir;
	} 
	ans.push_back(make_pair(fa, make_pair(t, x)));
}

int main() {
	int i;
	n = read();
	for(i = 1; i < n; i++) {
		int u = read(), v = read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	Siz(1);
	
	int cent1 = Cent(1), cent2 = 0;
	
    for(auto y : e[cent1]) 
		if(par != y && 2 * siz[y] == n) 
			cent2 = y;
    for(auto y : e[cent1]) 
		if(y != cent2) 
			Ans(y, cent1);
    for(auto y : e[cent2]) 
		if(y != cent1) 
			Ans(y, cent2);
	
	printf("%d\n", ans.size());
	for(auto x : ans) 
		printf("%d %d %d\n", x.fir, x.sec.fir, x.sec.sec);
		
	return 0;
}