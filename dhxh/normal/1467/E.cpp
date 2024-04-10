#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int n, m, t;

int a[maxn];

vector <int> e[maxn];

bool f[maxn];
bool g[maxn];
int h[maxn];

unordered_map <int, int> cnt;

int ans = 0;

map <int, int> dfs(int x, int fa){
	map <int, int> ret;
	ret[a[x]] = 1;
	f[x] = 1;
	
	for(auto y : e[x]){
		if(y == fa) continue;
		auto s = dfs(y, x);
		if(!f[y]){
			f[x] = 0;
		}
		if(s.count(a[x])){
			f[x] = 0;
			g[y] = s[a[x]];
		}
		if(s.size() > ret.size()) swap(s, ret);
		for(auto z : s){
			ret[z.first] += z.second;
		}
	}
	
	h[x] = ret[a[x]];
	
	return ret;
}

void find(int x, int fa){
	if(f[x] and cnt[a[x]] == 1){
		ans++;
	}
	int c = 0, d = 0;
	for(auto y : e[x]){
		if(y == fa) continue;
		c += !f[y];
		d += g[y];
	}
	
	for(auto y : e[x]){
		if(y == fa) continue;
		c -= !f[y];
		d -= g[y];
		if(!c and !d and h[y] == cnt[a[y]]) find(y, x);
		c += !f[y];
		d += g[y];
	}
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	
	for(i=1;i<n;i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	dfs(1, -1);
	find(1, -1);
	printf("%d\n", ans);
	
	return 0;
}