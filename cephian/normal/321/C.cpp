#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vvi T;

const int N = 1e5+5;
int sz[N]={};

char rnk[N];
int find_sz(int u, int v) {
	if(sz[v] == -1) return 0;
	sz[v] = 1;
	for(int w : T[v])
		if(w != u)
			sz[v] += find_sz(v,w);
	return sz[v];
}
int decomp(int v, int n, char r, bool rc = true) {
	if(rc) find_sz(-1,v);
	int p = -1;
	while(1) {
		int x = -1;
		for(int w : T[v])
			if(x == -1 || sz[w] > sz[x])
				x = w;
		if(sz[x]*2 <= n) break;
		sz[v] = n-sz[x];
		p = v, v = x;
	}
	rnk[v] = r;
	sz[v] = -1;
	for(int w : T[v]) {
		if(sz[w] == -1) continue;
		if(w == p) decomp(w,sz[w],r+1,true);
		else decomp(w,sz[w],r+1,false);
	}
	return v;
}

int main() {
	int n;
	scanf("%d",&n);
	T = vvi(n);
	for(int i = 1; i < n; ++i) {
		int u,v;
		scanf("%d%d",&u,&v),--u,--v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	decomp(0,n,'A');
	for(int i = 0; i < n; ++i)
		printf("%c ",rnk[i]);
	printf("\n");
}