#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vvi T;
const int N = 2e5+5;
int a[N],b[N];

void dfs(int* a, int u, int v, int d) {
	a[v] = d;
	for(int w : T[v]) {
		if(w == u) continue;
		dfs(a,v,w,d+1);
	}
}

int main() {
	int n,x;
	scanf("%d%d",&n,&x);
	--x;
	T = vvi(n,vi());
	for(int i = 1; i < n; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		--u;--v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(a,-1,0,0);
	dfs(b,-1,x,0);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(b[i] >= a[i]) continue;
		ans = max(ans,a[i]);
	}
	cout << ans*2 << "\n";

	return 0;
}