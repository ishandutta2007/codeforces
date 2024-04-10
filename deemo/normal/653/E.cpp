#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<utility>

using namespace std;

#define FAIL {printf("impossible\n"); return 0;}

const int MAXN = 3e5 + 10;

int n, m, k, sz, col[MAXN], q[MAXN];
int h, t;
bool seen[MAXN], vis[MAXN];
set<int>	st;
set<pair<int, int>>	nvd;

bool ok(int u, int v){
	if (u > v)	swap(u, v);
	if (nvd.count({u, v}))	return	false;
	return	true;
}

void dfs(int v){
	vis[v] = 1;
	int th = t;
	col[v] = sz;
	for (auto u:st)
		if (ok(u, v))	q[t++] = u;

	for (int i = th; i < t; i++)
		st.erase(q[i]);

	while (h < t)
		dfs(q[h++]);
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d %d", &a, &b);	a--, b--;
		if (a > b)	swap(a, b);
		nvd.insert({a, b});
	}
	
	for (int i = 1; i < n; i++)
		st.insert(i);
	for (int i = 1; i < n; i++)
		if (!vis[i]){
			st.erase(i);
			dfs(i);
			sz++;
		}
	
	if (sz > k)	FAIL
	int cc = 0;
	for (int i = 1; i < n; i++)
		if (ok(0, i)){
			seen[col[i]] = 1;
			cc++;
		}
	if (cc < k)	FAIL

	for (int i = 0; i < sz; i++)
		if (!seen[i])	FAIL
	printf("possible\n");
	return	0;
}