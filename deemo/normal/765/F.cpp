#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;
const int INF = 1e9;

int n, q, a[MAXN], tl[MAXN], tr[MAXN], ans[MAXN], sec[MAXN], sz, weed[MAXN<<2], cand[MAXN<<2], gec[MAXN];

bool cmp(int q1, int q2){return tr[q1] < tr[q2];}

void water(int v, int b, int e, int pos, int val, bool t=0){
	if (e - b == 1){
		if (!t)
			weed[v] = val;
		else
			cand[v] = min(cand[v], val);
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		water(v<<1, b, mid, pos, val, t);
	else
		water(v<<1^1, mid, e, pos, val, t);
	if (!t)
		weed[v] = max(weed[v<<1], weed[v<<1^1]);
	else
		cand[v] = min(cand[v<<1], cand[v<<1^1]);
}

int smoke(int v, int b, int e, int l, int r, bool t=0){
	if (l <= b && e <= r) return (t?cand[v]:weed[v]);
	if (r <= b || e <= l) return (t?INF:-1);

	int mid = b + e >> 1;
	if (!t)
		return max(smoke(v<<1, b, mid, l, r, t), smoke(v<<1^1, mid, e, l, r, t));
	return min(smoke(v<<1, b, mid, l, r, t), smoke(v<<1^1, mid, e, l, r, t));
}

int getPos(int x){return lower_bound(sec, sec + sz, x) - sec;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i], sec[sz++] = a[i];
	sort(sec, sec + sz);
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(sec, sec + sz, a[i]) - sec;
	memset(weed, -1, sizeof(weed));
	memset(cand, 63, sizeof(cand));

	cin >> q;
	for (int i = 0; i < q; i++)
		cin >> tl[i] >> tr[i], tl[i]--;
	iota(gec, gec + q, 0);
	sort(gec, gec + q, cmp);

	int cur = 0;
	for (int i = 0; i < n; i++){
		{
			int ind = smoke(1, 0, sz, a[i], sz);
			do{
				if (~ind){
					water(1, 0, n, ind, sec[a[ind]] - sec[a[i]], 1);
					int temp = a[ind];
					ind = smoke(1, 0, sz, a[i], getPos(sec[a[i]] + (sec[a[ind]]-sec[a[i]]+1>>1)));
					if (temp == a[ind]) break;
				}
			}while (~ind);
		}

		{
			int ind = smoke(1, 0, sz, 0, a[i]+1);
			do{
				if (~ind){
					water(1, 0, n, ind, sec[a[i]] - sec[a[ind]], 1);
					int temp = a[ind];
					ind = smoke(1, 0, sz, getPos(sec[a[ind]] + (sec[a[i]]-sec[a[ind]]+1>>1)), a[i]);
					if (temp == a[ind]) break;
				}
			}while (~ind);
		}

		water(1, 0, sz, a[i], i);
		
		while (cur < q && tr[gec[cur]] == i+1){
			int v = gec[cur++];
			ans[v] = smoke(1, 0, n, tl[v], tr[v], 1);
		}
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}