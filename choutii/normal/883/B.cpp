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

int n, m, K, on, l[MaxN], r[MaxN], deg[MaxN], ord[MaxN], ans[MaxN];
vector<int> e[MaxN], val[MaxN]; queue<int> q;

int main() {
	int i;
	n = read(); m = read(); K = read();
	for(i = 1; i <= n; i++){
		r[i] = read(); 
		if(!r[i]) l[i] = 1, r[i] = K;
		else l[i] = r[i]; 
	}
	
	for(i = 1; i <= m; i++) {
		int u = read(), v = read();
		e[u].emplace_back(v); ++deg[v];
	}
	
	for(i = 1; i <= n; i++) 
		if(!deg[i])
			q.push(i);
		
	while(!q.empty()) {
		int c = q.front(); q.pop(); ord[++on] = c;
		for(auto y : e[c]) 
			if(!--deg[y]) q.push(y);
	}
	
	if(on != n) return puts("-1"), 0;
	
	for(i = 1; i <= n; i++) {
		int x = ord[i];
		for(auto y : e[x]) 
			cmin(r[y], r[x] - 1);
	}
	
	for(i = n; i; i--) {
		int x = ord[i];
		for(auto y : e[x])
			cmax(l[x], l[y] + 1);
	}
	
	for(i = 1; i <= n; i++) if(l[i] > r[i]) return puts("-1"), 0; 
	for(i = 1; i <= n; i++) val[l[i]].push_back(i);
	
	set <pair<int, int> > s;
	for(i = 1; i <= K; i++) {
		for(auto x : val[i]) s.insert(make_pair(r[x], x));
		if(s.empty()) return puts("-1"), 0;
		pair<int, int> v = *s.begin();
		for(ans[v.sec] = i, s.erase(s.begin()); !s.empty() && (v = *s.begin()).fir == i; ans[v.sec] = i, s.erase(s.begin()));
	}
	for(i = 1; i <= n; i++)
		for(auto y : e[i])
			if(ans[y] >= ans[i]) return puts("-1"), 0;
			
	for(i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}