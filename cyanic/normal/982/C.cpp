#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 100005;
vector<int> e[maxn];
int n, u, v, ans;

int dfs(int u, int fa) {
	int size = 1;
	for (auto v : e[u])
		if (v != fa) 
			size += dfs(v, u);
	if (size&1) return 1;
	ans++; return 0;
}

int main() {
	scanf("%d", &n);
	if (n&1) return puts("-1"), 0;
	rep (i, 1, n-1) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", ans-1);
	
	return 0;
}