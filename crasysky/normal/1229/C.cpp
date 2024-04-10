#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 100005;
vector <int> G[maxn];
int in[maxn], out[maxn];
long long calc(int u){
	return 1LL * in[u] * out[u];
}
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
	int n = read(), m = read();
	for (int i = 1; i <= m; ++ i){
		int u = read(), v = read();
		if (u > v)
			swap(u, v);
		++ out[u], ++ in[v];
		G[u].push_back(v);	
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++ i)
		ans += calc(i);
	cout << ans << endl;
	int q = read();
	while (q --){
		int u = read();
		ans -= calc(u);
		for (int i = 0; i < G[u].size(); ++ i){
			++ in[u];
			int v = G[u][i];
			ans -= calc(v);
			G[v].push_back(u);
			-- in[v], ++ out[v];
			ans += calc(v);
		}
		out[u] = 0;
		G[u].clear();
		printf("%lld\n", ans);
	}
}