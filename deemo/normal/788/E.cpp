#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, a[MAXN], sec[MAXN];
int weed[5][MAXN<<2], lz[4][MAXN<<2];
int lessL[MAXN], lessR[MAXN], ps[MAXN];
int tl[MAXN], tr[MAXN], cur;

int fix(int x){
	while (x >= MOD) x -= MOD; 
	while (x < 0) x += MOD;
	return x;
}

void absorb(int v, int b, int e, int mid, int t){
	if (!lz[t][v]) return;
	weed[t][v<<1] = (weed[t][v<<1] + 1ll*lz[t][v]*(mid-b-weed[4][v<<1])) % MOD;
	lz[t][v<<1] = fix(lz[t][v<<1] + lz[t][v]);
	weed[t][v<<1^1] = (weed[t][v<<1^1] + 1ll*lz[t][v]*(e-mid-weed[4][v<<1^1])) % MOD;
	lz[t][v<<1^1] = fix(lz[t][v<<1^1] + lz[t][v]);
	lz[t][v] = 0;
}

int fl = 0;
void modify(int v, int b, int e, int pos, int val, int t){
	if (e - b == 1){
		weed[t][v] = val;
		if (fl == 1)
			weed[4][v]++;
		if (fl == 2)
			weed[4][v]--;
		return;
	}

	int mid = b + e >> 1;
	absorb(v, b, e, mid, t);
	if (pos < mid)
		modify(v<<1, b, mid, pos, val, t);
	else
		modify(v<<1^1, mid, e, pos, val, t);
	weed[t][v] = fix(weed[t][v<<1] + weed[t][v<<1^1]);
	weed[4][v] = weed[4][v<<1] + weed[4][v<<1^1];
}

void add(int v, int b, int e, int l, int r, int val, int t){
	if (l <= b && e <= r){
		weed[t][v] = (weed[t][v] + 1ll*val*(e-b-weed[4][v])) % MOD;
		lz[t][v] = fix(lz[t][v] + val);
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid, t);
	add(v<<1, b, mid, l, r, val, t);
	add(v<<1^1, mid, e, l, r, val, t);
	weed[t][v] = fix(weed[t][v<<1] + weed[t][v<<1^1]);
	weed[4][v] = weed[4][v<<1] + weed[4][v<<1^1];
}

int get(int v, int b, int e, int l, int r, int t){
	if (l <= b && e <= r) return weed[t][v];
	if (r <= b || e <= l) return 0;

	int mid = b + e >> 1;
	absorb(v, b, e, mid, t);
	return fix(get(v<<1, b, mid, l, r, t) + get(v<<1^1, mid, e, l, r, t));
}

int get2(int v, int b, int e, int pos, int t){
	if (e - b == 1) return weed[t][v];
	
	int mid = b + e >> 1;
	absorb(v, b, e, mid, t);
	if (pos < mid)
		return get2(v<<1, b, mid, pos, t);
	return get2(v<<1^1, mid, e, pos, t);
}

bool cmp(int u, int v){
	if (a[u] ^ a[v])
		return a[u] < a[v];
	return u < v;
}

int main(){
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		memcpy(sec, a, sizeof(a));
		sort(sec, sec + n);
		for (int i = 0; i < n; i++)
			a[i] = lower_bound(sec, sec + n, a[i]) - sec;
	}

	{
		iota(sec, sec + n, 0);
		sort(sec, sec + n, cmp);
		for (int l = 0; l < n;){
			int r = l;
			while (r < n && a[sec[l]] == a[sec[r]]) r++;
			tl[a[sec[l]]] = l, tr[a[sec[l]]] = r;
	
			int temp = l;
			while (l < r)
				modify(1, 0, n, sec[l++], 1, 0);
			l = temp;

			for (int i = l; i < r; i++)
				lessL[sec[i]] = get(1, 0, n, 0, sec[i], 0)
					, lessR[sec[i]] = r-1 - lessL[sec[i]], ps[sec[i]] = i;

			l = r;
		}
		memset(weed, 0, sizeof(weed));
		memset(lz, 0, sizeof(lz));
	}

	{
		for (int i = 0; i < n; i++)
			modify(1, 0, n, ps[i], lessL[i], 0)
				, modify(1, 0, n, ps[i], lessR[i], 1);

		for (int i = 0; i < n; i++)
			modify(1, 0, n, ps[i], get(1, 0, n, tl[a[i]], ps[i], 0), 2)
				, modify(1, 0, n, ps[i], get(1, 0, n, ps[i]+1, tr[a[i]], 1), 3);

		for (int i = 0; i < n; i++)
			cur = (cur + 1ll*get2(1, 0, n, ps[i], 2) * get2(1, 0, n, ps[i], 3)) % MOD;
	}

	int q; scanf("%d", &q);
	while (q--){
		int x, y; scanf("%d %d", &x, &y), y--;
		if (x == 1){
			cur = (cur - 1ll*lessL[y]*get(1, 0, n, ps[y] + 1, tr[a[y]], 3)%MOD + MOD) % MOD;
			cur = (cur - 1ll*get2(1, 0, n, ps[y], 2)*get2(1, 0, n, ps[y], 3)%MOD + MOD) % MOD;
			cur = (cur - 1ll*lessR[y]*get(1, 0, n, tl[a[y]], ps[y], 2)%MOD + MOD) % MOD;

			fl = 1;
			modify(1, 0, n, ps[y], 0, 0);
			fl = 0;
			modify(1, 0, n, ps[y], 0, 1);
			modify(1, 0, n, ps[y], 0, 2);
			modify(1, 0, n, ps[y], 0, 3);
			add(1, 0, n, ps[y]+1, tr[a[y]], MOD-lessL[y], 2);
			add(1, 0, n, tl[a[y]], ps[y], MOD-lessR[y], 3);
		}
		else{
			fl = 2;
			modify(1, 0, n, ps[y], lessL[y], 0);
			fl = 0;
			modify(1, 0, n, ps[y], lessR[y], 1);
			modify(1, 0, n, ps[y], get(1, 0, n, tl[a[y]], ps[y], 0), 2);
			modify(1, 0, n, ps[y], get(1, 0, n, ps[y]+1, tr[a[y]], 1), 3);
			add(1, 0, n, ps[y]+1, tr[a[y]], lessL[y], 2);
			add(1, 0, n, tl[a[y]], ps[y], lessR[y], 3);

			cur = (cur + 1ll*lessL[y]*get(1, 0, n, ps[y] + 1, tr[a[y]], 3)) % MOD;
			cur = (cur + 1ll*get2(1, 0, n, ps[y], 2)*get2(1, 0, n, ps[y], 3)) % MOD;
			cur = (cur + 1ll*lessR[y]*get(1, 0, n, tl[a[y]], ps[y], 2)) % MOD;
		}
		printf("%d\n", cur);
	}
	return 0;
}