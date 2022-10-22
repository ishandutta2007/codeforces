#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, q, from[MAXN], tl[MAXN], tr[MAXN], ans[MAXN], sec[MAXN];
pair<int, int> weed[MAXN<<2];

bool cmp(int q1, int q2){return tr[q1] < tr[q2];}

void plant(int v, int b, int e){
	if (e - b == 1){
		weed[v] = {b, b};
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

void water(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		weed[v].F = val;
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		water(v<<1, b, mid, pos, val);
	else
		water(v<<1^1, mid, e, pos, val);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

int getVal(int v, int b, int e, int pos){
	if (e - b == 1) return weed[v].F;

	int mid = b + e >> 1;
	if (pos < mid)
		return getVal(v<<1, b, mid, pos);
	return getVal(v<<1^1, mid, e, pos);
}

pair<int, int> smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return weed[v];
	if (r <= b || e <= l) return {-1, -1};

	int mid = b + e >> 1;
	return max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int getPar(int v){
	int r = getVal(1, 0, n, v);
	if (r == v) return r;

	auto x = smoke(1, 0, n, v+1, r+1);
	if (x.F <= r) return r;

	int ret = getPar(x.S);
	water(1, 0, n, v, ret);
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int m; cin >> m;
	memset(from, -1, sizeof(from));
	while (m--){
		int l, r; cin >> l >> r, l--, r--;
		if (l ^ r)
			from[r] = l;
	}
	plant(1, 0, n);

	cin >> q;
	for (int i = 0; i < q; i++) cin >> tl[i] >> tr[i], tl[i]--;
	iota(sec, sec + q, 0);
	sort(sec, sec + q, cmp);

	int cur = 0;
	for (int i = 0; i < n; i++){
		if (~from[i])
			water(1, 0, n, from[i], i);

		while (cur < q && tr[sec[cur]] == i+1){
			int v = tl[sec[cur]];
			ans[sec[cur++]] = getPar(v)+1;
		}
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}