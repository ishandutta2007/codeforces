#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#define maxn 1000009
using namespace std;
const int MOD = 1e9 + 7;
int n, m;
int ans[maxn];
vector<int>V[maxn],G[maxn];
set<int>st;
int tot;
vector<int>a;
void dfs(int u, int fa){
	for(auto v: G[u]){
		if(v == fa)
			continue;
		st.clear();
		a.clear();
		int num = V[v].size();
		for(auto x: V[v]){
			if(ans[x] != 0){
				st.insert(ans[x]);
				num--;
			}
		}
		for(int i = 1;;i++){
			if(a.size() >= num)
				break;
			if(st.count(i))
				continue;
			a.push_back(i);
		}
		int p = 0;
		for(auto x: V[v]){
			if(ans[x] == 0){
				ans[x] = a[p];
				p++;
			}
		}
		dfs(v, u);
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		for(int j = 0; j < x; j++){
			int y;
			scanf("%d", &y);
			V[i].push_back(y);
		}
	}
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(auto x: V[1]){
		tot++;
		ans[x] = tot;
	}
	dfs(1, -1);
	for(int i = 1; i <= m; i++)
		tot = max(tot, ans[i]);
	if(tot == 0) tot = 1;
	printf("%d\n", tot);
	for(int i = 1; i <= m; i++){
		if(ans[i])
			printf("%d ", ans[i]);
		else
			printf("1 ");
	}
	return 0;
}