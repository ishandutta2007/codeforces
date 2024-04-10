#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int LOG = 30;

int n, a[MAXN], root[MAXN], lst[MAXN];
int sz, weed[LOG*MAXN], le[LOG*MAXN], ri[LOG*MAXN];

int plant(int b, int e){
	int id = sz++;
	weed[id] = 0;
	if (e - b == 1) return id;

	int mid = b + e >> 1;
	le[id] = plant(b, mid);
	ri[id] = plant(mid, e);
	return id;
}

int water(int id, int b, int e, int pos, int val){
	int newid = sz++;
	le[newid] = le[id];
	ri[newid] = ri[id];
	if (e - b == 1){
		weed[newid] = val;
		return newid;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		le[newid] = water(le[id], b, mid, pos, val);
	else
		ri[newid] = water(ri[id], mid, e, pos, val);

	weed[newid] = weed[le[newid]] + weed[ri[newid]];
	return newid;
}

int getNext(int id, int b, int e, int rem){
	if (e - b == 1){
		if (weed[id]){
			if (rem)
				return e;
			return b;
		}
		return e;
	}

	int mid = b + e >> 1;
	if (weed[le[id]] <= rem)
		return getNext(ri[id], mid, e, rem-weed[le[id]]);
	return getNext(le[id], b, mid, rem);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	root[n] = plant(0, n);
	memset(lst, -1, sizeof(lst));
	for (int i = n-1; ~i; i--){
		if (~lst[a[i]]){
			root[i] = water(root[i+1], 0, n, lst[a[i]], 0);
			root[i] = water(root[i], 0, n, i, 1);
		}
		else
			root[i] = water(root[i+1], 0, n, i, 1);
		lst[a[i]] = i;
	}

	for (int i = 1; i <= n; i++){
		int l = 0, ans = 0;
		while (l < n){
			ans++;
			l = getNext(root[l], 0, n, i);
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}