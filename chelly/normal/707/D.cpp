#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<vector>
using namespace std;
const int Q(111111);
const int M(1111);
vector<pair<int, int> > q;
vector<int> adj[Q];
int n, m;
bitset<M> bt[M];
bitset<M> bak[Q];
int fa[Q], ans[Q];
struct Oper {
	int tp, i, j;
	Oper(int tp, int i, int j) : tp(tp), i(i), j(j) {
	}
	Oper() {
	}
} oper[Q];

bitset<M> msk;
void push(int v) {
	q.push_back(make_pair(v, 0));
	if(oper[v].tp >= 1) {
		bak[v] = bt[oper[v].i];
		if(oper[v].tp == 1) {
			bt[oper[v].i].set(oper[v].j, 1);
		}else if(oper[v].tp == 2) {
			bt[oper[v].i].set(oper[v].j, 0);
		}else {
			bt[oper[v].i].flip();
		}
	}
	ans[v] = v ? oper[v].tp == 0 ? ans[fa[v]] : ans[fa[v]] + (msk & bt[oper[v].i]).count() - (msk & bak[v]).count() : 0;

}
void calc() {
	push(0);
	for(int i(1); i <= m; i++) {
		msk.set(i, 1);
	}
	while(!q.empty()) {
		int v(q.back().first), p(q.back().second++);
		if(adj[v].size() > p) {
			int y(adj[v][p]);
			push(y);
		}else {
			if(v == 0) {
				ans[0] = 0;
			}else {
				bt[oper[v].i] = bak[v];
			}
			q.pop_back();
		}
	}
}
int main() {
	int q;
	scanf("%d%d%d", &n, &m, &q);
	oper[0] = Oper(0, 0, 0);
	for(int i(0); i < q; i++) {
		int tp;
		scanf("%d", &tp);
		if(tp <= 3) {
			adj[i].push_back(i + 1);
			fa[i + 1] = i;
			if(tp <= 2) {
				int x, y;
				scanf("%d%d", &x, &y);
				oper[i + 1] = Oper(tp, x, y);
			}else {
				int x;
				scanf("%d", &x);
				oper[i + 1] = Oper(tp, x, 0);
			}
		}else {
			int x;
			scanf("%d", &x);
			adj[x].push_back(i + 1);
			fa[i + 1] = x;
			oper[i + 1] = Oper(0, 0, 0);
		}
	}
	calc();
	for(int i(1); i <= q; i++) {
		printf("%d\n", ans[i]);
	}
}