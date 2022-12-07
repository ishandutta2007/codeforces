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

template <typename T> inline bool cmin(T & a, const T & b) { return b < a ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int MaxN = 301234;

int n, m, chk; VI e[MaxN], ans;

int d[MaxN], p[MaxN], cho[MaxN];

bool operator < (VI a, VI b) {
	return SZ(a) < SZ(b);
}

bool bfs() {
	queue<int> q; q.push(1);
	for (int i = 1; i <= n; i++)
		d[i] = n + 1;
	d[1] = 1;
	while(!q.empty()) {
		int c = q.front(); q.pop(); 
		for (auto b : e[c]) {
			if(d[b] > n)
				d[b] = d[c] + 1, p[b] = c, q.push(b);
		}
	}
	if(d[n] <= n) {
		chk = d[n] <= 5; 
		for (int i = n; i; i = p[i])
				ans.pb(i); 
		reverse(ALL(ans));
	} 
	if(d[n] <= 5 && d[n] <= n) 
		return true;
	else 
		return false;
}

void solve5() {
	for(auto u : e[1]) {
			queue<int> q; q.push(u); VI cur;
			d[u] = 0;
			while(!q.empty()) {
				int c = q.front(); q.pop(); cur.pb(c);
				for (auto b : e[c]) 
					if(d[b] == 2)
						d[b] = 0, q.push(b);
			}
			for (int i = 0; i < SZ(cur); i++) {
				for (auto u : e[cur[i]])
					cho[u] = 1;
				for (int j = 0; j < SZ(cur); j++) {
					if(i == j) continue;
					if(!cho[cur[j]]) {
						for (auto k : e[cur[j]])
							if(k != 1 && cho[k]) {
								chk = 1;
								ans = {1, cur[j], k, cur[i], cur[j], n};
								return; 
							} 
					}
				}
				for (auto u : e[cur[i]])
					cho[u] = 0;
			}
		} 
}
int main() {
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		int u, v; read(u); read(v);
		e[u].pb(v); e[v].pb(u);
	}
	
	if(!bfs()) {
		// 
		for (auto u : e[1]) 
			cho[u] = 1;
		for (auto u : e[1]) 
			for (auto v : e[u]) {
				if(!cho[v] && v != 1)	{
					if(!chk)
						ans = {1, u, v, 1, n}, chk = 1;
				}
			}
		for (auto u : e[1])
			cho[u] = 0;
		if(!chk)
			solve5();
	}
	if(!chk) puts("-1");
	else {
		printf("%d\n", SZ(ans) - 1);
		for (auto i : ans)	
			printf("%d ", i);
	}
	
	return 0;
}

/*
1 -> u -> v ..> 1 -> n 


*/