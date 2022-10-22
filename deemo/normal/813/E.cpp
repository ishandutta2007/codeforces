#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int LOG = 70;

int n, k, root[MAXN], le[LOG*MAXN], ri[LOG*MAXN], weed[LOG*MAXN], sz;
deque<int> que[MAXN];

int plant(int b, int e){
	int id = ++sz;
	if (e - b == 1) return id;

	int mid = b + e >> 1;
	le[id] = plant(b, mid);
	ri[id] = plant(mid, e);
	return id;
}

int water(int id, int b, int e, int pos, int val){
	int nID = ++sz;
	le[nID] = le[id];
	ri[nID] = ri[id];
	weed[nID] = weed[id];
	if (e - b == 1){
		weed[nID] += val;
		return nID;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		le[nID] = water(le[nID], b, mid, pos, val);
	else
		ri[nID] = water(ri[nID], mid, e, pos, val);
	weed[nID] = weed[le[nID]] + weed[ri[nID]];
	return nID;
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b&& e <= r) return weed[v];
	if (r <= b || e <= l) return 0;

	int mid = b + e >> 1;
	return smoke(le[v], b, mid, l, r) + smoke(ri[v], mid, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	root[0] = plant(0, n);
	for (int i = 0; i < n; i++){
		int x;	cin >> x, x--;
		root[i+1] = water(root[i], 0, n, i, 1);
		que[x].push_back(i);
		if (que[x].size() > k){
			int z = que[x].front();
			que[x].pop_front();
			root[i+1] = water(root[i+1], 0, n, z, -1);
		}
	}

	int q;	cin >> q;
	int lst = 0;
	while (q--){
		int l, r; cin >> l >> r;
		l = (l+lst)%n+1;
		r = (r+lst)%n+1;
		if (l > r) swap(l, r);
		l--;

		cout << (lst=smoke(root[r], 0, n, l, r)) << "\n";
	}
	return 0;
}