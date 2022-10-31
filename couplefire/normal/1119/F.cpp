#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair < int , int > pii;
#define mp make_pair

const int MN = 3e5 + 5;

int N , X;
vector < pii > E[MN];
int deg[MN] , vis[MN];
LL dp[MN][2];
vector < LL > del , tmp;
pii D[MN];

inline void AddEdge(int u , int v , int w) {
	E[u].emplace_back(mp(v , w));
	++deg[u];
}
inline bool cmp(pair < int , int > x , pair < int , int > y) {
	return deg[x.first] > deg[y.first];
}
struct Heap {
	int sz; LL sum;
	priority_queue < LL > a , b;
	inline void push(LL x) { a.push(x); ++sz; sum += (LL) x; }
	inline void erase(LL x) { b.push(x); --sz; sum -= (LL) x; }
	inline void check() { while (!a.empty() && !b.empty() && a.top() == b.top()) { a.pop(); b.pop(); } }
	inline LL top() { check(); return a.top(); }
	inline void pop() { check(); --sz; sum -= (LL) a.top(); a.pop(); }
	inline int size() { return sz; }
} H[MN];

inline void die(int u) {
	for (auto to : E[u]) {
		int v = to.first , w = to.second;
		if (deg[v] <= X) break;
		H[v].push(w);
	}
}
inline void dfs(int u , int fa = 0) {
	vis[u] = X;
	int need = deg[u] - X;
	LL res = 0;
	for (; H[u].size() > need; H[u].pop());
	for (auto to : E[u]) {
		int v = to.first , w = to.second; 
		if (deg[v] <= X) break; if (v == fa) continue; 
		dfs(v , u);
	}
	tmp.clear() , del.clear();
	for (auto to : E[u]) {
		int v = to.first , w = to.second; if (v == fa) continue; 
		if (deg[v] <= X) break;
		LL x = dp[v][1] + w - dp[v][0];
		if (x <= 0) { --need; res += dp[v][1] + w; continue; }
		res += dp[v][0]; H[u].push(x); del.emplace_back(x);
	}
	for (; H[u].size() && H[u].size() > need; H[u].pop()) tmp.emplace_back(H[u].top());
	dp[u][0] = res + H[u].sum;
	for (; H[u].size() && H[u].size() > need - 1; H[u].pop()) tmp.emplace_back(H[u].top());
	dp[u][1] = res + H[u].sum;
	for (int i : tmp) H[u].push(i);
	for (int i : del) H[u].erase(i);
}

int main() {
	
	scanf("%d" , &N); LL sum = 0;
	for (int i = 1; i < N; ++i) {
		int u , v , w;
		scanf("%d%d%d" , &u , &v , &w);
		AddEdge(u , v , w); AddEdge(v , u , w);
		sum += 1LL * w;
	}
	printf("%lld" , sum);
	for (int i = 1; i <= N; ++i)
		D[i] = mp(deg[i] , i) , sort(E[i].begin() , E[i].end() , cmp);
	sort(D + 1 , D + N + 1);
	int cur = 1;
	for (X = 1; X < N; ++X) {
		while (cur <= N && D[cur].first == X) die(D[cur].second) , ++cur;
		LL ans = 0;
		for (int j = cur; j <= N; ++j) {
			int v = D[j].second;
			if (vis[v] == X) continue;
			dfs(v) , ans += 1LL * dp[v][0];
		}
		printf(" %lld" , ans);
	}
	printf("\n");
	return 0; 
}