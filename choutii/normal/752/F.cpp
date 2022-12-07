#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;

typedef long long LL;

template <typename T> inline bool cmin(T & a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline bool cmax(T & a, const T &b) { return a < b ? a = b, 1 : 0; }

int getint() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234;

vector<int> e[MaxN]; 
int n, K, c[MaxN], siz[MaxN];

void dfs1(int x, int fa = 0) {
	siz[x] = c[x];
	for(auto y : e[x]) 
		if(y != fa) {
			dfs1(y, x);
			siz[x] += siz[y];
		}
}

int rot;
void dfs2(int x, int fa = 0) {
	int chk = 0;
	for(auto y : e[x]) 
		if(y != fa) {
			if(siz[y] > K) 
				chk = y;
		}
	if(!chk) rot = x;
	else dfs2(chk, x);
}

vector<int> ans;
void dfs3(int x, int fa = 0) {
	if(c[x]) ans.push_back(x);
	for(auto y : e[x]) 
		if(y != fa) 
			dfs3(y, x); 
} 

int main(){
	int i;
	n = getint(); K = getint();
	for(i = 1; i < n; i++) {
		int u = getint(), v = getint();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	for(i = 1; i <= 2 * K; i++) 
		c[getint()] = 1;
	dfs1(1); 
	dfs2(1); 
	dfs3(rot);
	
	puts("1");
	printf("%d\n", rot);
	for(i = 0; i < K; i++)
		printf("%d %d %d\n", ans[i], ans[i + K], rot);
	return 0;
}