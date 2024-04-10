#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <memory.h>
#include <time.h>
#include <list>
#include <deque>
#include <functional>


using namespace std;

#define MX 200005
#define pb push_back
typedef pair<int, int> pii;

int N;

struct SegT {
	#define Tree int t, int l, int r
	#define Left t*2, l, mid
	#define Right t*2+1, mid+1, r
	#define MID int mid = (l+r)>>1
	int walk[MX], pre[MX], last[MX], tot, par[MX];
	vector<int> qu, con[MX];
	bool removed[MX];
	vector<pii> edge[4*MX];
	int skip[4*MX];
	
	void dfs(int v) {
		walk[tot] = v, pre[v] = tot++;
		for (int i = 0; i < con[v].size(); i++) {
			if (con[v][i] == par[v]) continue; 
			dfs(con[v][i]);	
		}	
		last[v] = tot - 1;
	}	
	void prepare() {
		tot = 1;
		dfs(0);	
	}	
	void update(Tree, int ord1, int ord2) {
		edge[t].pb(make_pair(ord2, ord1)); 
		if (l == r) return; MID;
		if (ord1 <= mid) update(Left, ord1, ord2);
		else update(Right, ord1, ord2);	
	}
	void build(SegT &t) {
		int i, j;
		for (i = 0; i < N; i++) {
			for (j = 0; j < t.con[i].size(); j++) {
				update(1, 1, N, pre[i], pre[t.con[i][j]]); 		
			}
		}	
	}
	void prepare2() {
		for (int i = 1; i < 4 * MX; i++) 
			sort(edge[i].begin(), edge[i].end());	
	}
	void consider(pii o12, SegT &other) {
		int ord1 = o12.first, ord2 = o12.second;
		int pre1 = other.pre[walk[ord1]], pre2 = other.pre[walk[ord2]], son;
		
		if (pre1 < pre2) son = walk[ord2];	
		else son = walk[ord1];
	
		if (!other.removed[son]) {
			other.removed[son] = true;
			other.qu.pb(son);	
		}
	} 
	void work(int t, int a, int b, SegT &other) {
		while (skip[t] < edge[t].size() && edge[t][skip[t]].first < a) {
			consider(edge[t][skip[t]++], other);
		}	
		while (edge[t].size() && edge[t].back().first > b) {
			consider(edge[t].back(), other);
			edge[t].pop_back();
		}
	}
	void query(Tree, int a, int b, SegT &other) {
		if (a > r || b < l) return;
		if (a <= l && r <= b) { work(t, a, b, other); return; } MID;
		query(Left, a, b, other); query(Right, a, b, other);
	}
	void remove(SegT &other) {
		int st, en, i;
		for (i = 0; i < qu.size(); i++) {
			st = pre[qu[i]], en = last[qu[i]];		
			query(1, 1, N, st, en, other);
		}	
	}
}tree[2];

main() {
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int i, j, k, x;
	scanf("%d", &N);
	for (i = 0; i < 2; i++) {
		tree[i].par[0] = -1;
		for (j = 1; j < N; j++) {
			scanf("%d", &x); x--;	
			tree[i].par[j] = x;
			tree[i].con[j].pb(x);
			tree[i].con[x].pb(j);
		}	
		tree[i].prepare();
	}
	scanf("%d", &x);
	tree[0].qu.pb(x);
	tree[0].removed[x] = true;
	for (i = 0; i < 2; i++) {
		tree[i].build(tree[1-i]);
		tree[i].prepare2();	
	}
	k = 0;
	while (!tree[k].qu.empty()) {
		printf("%s\n", k==0?"Blue":"Red");	
		sort(tree[k].qu.begin(), tree[k].qu.end());
		for (i = 0; i < tree[k].qu.size(); i++) {
			if (i) printf(" ");
			printf("%d", tree[k].qu[i]);	
		} puts("");
		tree[k].remove(tree[1-k]);
		tree[k].qu.clear();
		k = 1 - k;
	}
}