#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#define maxn 2000009
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const long long INF = 1e17;
int tree1[maxn << 2], tree2[maxn << 2];
int tot, n, s, m;
vector<pair<int,int> >G[maxn];
bool done[maxn];
long long d[maxn];
void build(int l, int r, int rt){
	tree1[rt] = ++tot;
	tree2[rt] = ++tot;
	if(l == r){
		G[tree1[rt]].push_back(make_pair(l, 0));
		G[l].push_back(make_pair(tree2[rt], 0));
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	G[tree1[rt]].push_back(make_pair(tree1[rt << 1], 0));
	G[tree1[rt]].push_back(make_pair(tree1[rt << 1 | 1], 0));
	G[tree2[rt << 1]].push_back(make_pair(tree2[rt], 0));
	G[tree2[rt << 1 | 1]].push_back(make_pair(tree2[rt], 0));
}
void update(int L, int R, int x, int v, int w, int l, int r, int rt){
	if(L <= l && r <= R){
		if(x == 2){
			G[v].push_back(make_pair(tree1[rt], w));
		}
		else{
			G[tree2[rt]].push_back(make_pair(v, w));
		}
		return;
	}
	int m = (l + r) >> 1;
	if(L <= m)
		update(L, R, x, v, w, lson);
	if(R > m)
		update(L, R, x, v, w, rson);
}
priority_queue<pair<long long, int> >Q;
void Dijikstra(){
	memset(done, 0, sizeof(done));
	for(int i = 1; i <= tot; i++)
		d[i] = INF;
	d[s] = 0;
	Q.push(make_pair(0, s));
	while(!Q.empty()){
		int u = Q.top().second;
		Q.pop();
		if(done[u])
			continue;
		done[u] = 1;
		for(auto it: G[u]){
			int v = it.first;
			int w = it.second;
			if(d[u] + w < d[v]){
				d[v] = d[u] + w;
				Q.push(make_pair(-d[v], v));
			}
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &s);
	tot = n;
	build(1, n, 1);
	for(int i = 0; i < m; i++){
		int t, u, v, w, l, r;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(make_pair(v, w));
		}
		else{
			scanf("%d%d%d%d", &v, &l, &r, &w);
			update(l, r, t, v, w, 1, n, 1);
		}
	}
	Dijikstra();
	for(int i = 1; i <= n; i++){
		if(d[i] == INF)
			printf("-1 ");
		else
			printf("%I64d ", d[i]);
	}
	return 0;
}