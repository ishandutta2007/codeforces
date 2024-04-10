#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 5e3 + 10;

int n;
pair<int, int>	vec[max_n];
int de[max_n][max_n];
bool mark[max_n];
int depth[max_n];

int dis(int a, int b){
	return	abs((double)vec[a].first - vec[b].first) + abs((double)vec[a].second - vec[b].second);
}	

bool dfs(int v, int u, int d, int x){
	if (mark[v]){
		if (depth[v] % 2 == depth[u] % 2)	return	true;
		return	false;
	}
	mark[v] = 1;
	depth[v] = d;
	for (int t = 0; t < n; t++){
		if (de[v][t] <= x)	continue;
		if (dfs(t, v, d + 1, x))
			return	true;
	}
	return	false;
}

bool ok(int x){
	fill(mark, mark+max_n - 10, 0);
	for (int i = 0; i < n; i++){
		if (mark[i])	continue;
		if (dfs(i, -1, 0, x))	return	false;
	}
	return	true;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &vec[i].first, &vec[i].second);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			de[i][j] = dis(i, j);	

	int b = 0, e = 1e4, mid, ret = 1e4;
	while (b <= e){
		mid = (b + e)/ 2;
		if (ok(mid)){
			ret = mid;
			e = mid - 1;
		}
		else	b = mid + 1;
	}

	fill(mark, mark+max_n - 10, 0);
	ll ans = 1;
	for (int i = 0; i < n; i++){
		if (mark[i])	continue;
		dfs(i, -1, 0, ret);
		ans = (ans * 2) % MOD;
	}
	printf("%d\n", ret);
	printf("%d\n", (int)ans);
	return 0;
}