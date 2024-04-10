//Rainy Memory

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, pos[MAXN], jmp[MAXN], x[MAXN], y[MAXN], sec[MAXN], ans[MAXN];
ordered_set st, tt;
pair<int, int>	weed[4 * MAXN];

bool cmp(int u, int v){return x[u] > x[v];}

void water(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		weed[v] = {val, b};
		return;
	}

	int mid = b+e>>1;
	if (pos < mid)
		water(v<<1, b, mid, pos, val);
	else
		water(v<<1^1, mid, e, pos, val);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

pair<int, int> smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return {-1, -1};

	int mid = b+e>>1;
	return max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]), y[i] = min(y[i], i), tt.insert(i), st.insert(i);
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);

	fill(weed, weed + 4 * MAXN, make_pair(-1, -1));
	for (int i = 0; i < n; i++){
		int v = sec[i];
		auto x = smoke(1, 0, n, 0, v);

		if (x.F == -1)
			jmp[v] = y[v];
		else
			jmp[v] = min(y[v], (int)tt.order_of_key(v) - (int)tt.order_of_key(x.S) + jmp[x.S]);
		pos[v] = *st.find_by_order(max(0, (int)tt.order_of_key(v) - jmp[v]));

		water(1, 0, n, v, pos[v]);
		st.erase(pos[v]);
		ans[pos[v]] = v + 1;
		tt.erase(v);
	}
	
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}