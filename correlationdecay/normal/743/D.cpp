#include <bits/stdc++.h>
#define maxn 200009
using namespace std;
int n;
vector<int> G[maxn];
int a[maxn];
long long sum[maxn];
set<pair<long long,int> >st;
long long ans;
const long long INF = 1e18;
void dfs1(int u, int fa){
	sum[u] = a[u];
	for(auto v: G[u]){
		if(v == fa)
			continue;
		dfs1(v, u);
		sum[u] += sum[v];
	}
}
void dfs2(int u, int fa){
	st.erase(make_pair(sum[u], u));
	for(auto v: G[u]){
		if(v == fa)
			continue;
		dfs2(v, u);
	}
	if((int)st.size() > 0){
		auto it = st.end();
		--it;
		ans = max(ans, (*it).first + sum[u]);
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1, -1);
	for(int i = 1; i <= n; i++){
		st.insert(make_pair(sum[i], i));
	}

	ans = -INF;
	dfs2(1, -1);
	if(ans == -INF){
		puts("Impossible");
	}
	else{
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}