#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back

const int maxn = 300100;
int n, k, d;
vector<int> g[maxn];
int fa[maxn], u[maxn], v[maxn];
vector<int> ans;
queue<int> q;

int main(){
	scanf("%d%d%d", &n, &k, &d);
	for(int i = 1; i <= k; ++i){
		static int x;
		scanf("%d", &x);
		if(!fa[x]) q.push(x), fa[x] = x;
	}
	printf("%d\n", (int)q.size() - 1);
	for(int i = 1; i < n; ++i){
		scanf("%d%d", u + i, v + i);
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
	}
	while(!q.empty()){
		int t = q.front(); q.pop(); 
		for(auto v : g[t])
			if(!fa[v]){
				fa[v] = fa[t];
				q.push(v);
			}
	}
	for(int i = 1; i < n; ++i)
		if(fa[u[i]] != fa[v[i]])
			printf("%d ", i);
	//system("pause");
	return 0;
}