#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const ll INF = (ll)1e18 + 10;

int q, sz;
ll sec[MAXN], on[MAXN<<2], off[MAXN<<2];
int nut[MAXN<<2];
int tp[MAXN];
ll tl[MAXN], tr[MAXN];

void merge(int v, int l, int r){
	on[v] = min(on[l], on[r]);
	off[v] = min(off[l], off[r]);
}

void plant(int v, int b, int e){
	if (e - b == 1){
		on[v] = sec[b];
		off[v] = INF;
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	merge(v, v<<1, v<<1^1);
}

void absorb(int v, int b, int e, int mid){
	if (!nut[v]) return;
	if (nut[v] == 1){
		off[v<<1] = sec[b];
		off[v<<1^1] = sec[mid];
		on[v<<1] = on[v<<1^1] = INF;
		nut[v<<1] = nut[v<<1^1] = nut[v];
	}
	else if (nut[v] == 2){
		on[v<<1] = sec[b];
		on[v<<1^1] = sec[mid];
		off[v<<1] = off[v<<1^1] = INF;
		nut[v<<1] = nut[v<<1^1] = nut[v];
	}
	else{
		swap(on[v<<1], off[v<<1]);
		swap(on[v<<1^1], off[v<<1^1]);
		nut[v<<1] = 3-nut[v<<1];

		nut[v<<1^1] = 3-nut[v<<1^1];
	}
	nut[v] = 0;
}

void remove(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		off[v] = sec[b];
		on[v] = INF;
		nut[v] = 1;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	remove(v<<1, b, mid, l, r);
	remove(v<<1^1, mid, e, l, r);
	merge(v, v<<1, v<<1^1);
}

void add(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		off[v] = INF;
		on[v] = sec[b];
		nut[v] = 2;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	add(v<<1, b, mid, l, r);
	add(v<<1^1, mid, e, l, r);
	merge(v, v<<1, v<<1^1);
}

void rev(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		swap(on[v], off[v]);
		nut[v] = 3-nut[v];
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	rev(v<<1, b, mid, l, r);
	rev(v<<1^1, mid, e, l, r);
	merge(v, v<<1, v<<1^1);
}

int get(ll x){return lower_bound(sec, sec + sz, x) - sec;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	sec[sz++] = 0;
	sec[sz++] = (ll)1e18;
	for (int i = 0; i < q; i++){
		cin >> tp[i] >> tl[i] >> tr[i], tl[i]--;
		sec[sz++] = tl[i], sec[sz++] = tr[i];
	}
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;

	plant(1, 0, sz);
	for (int i = 0; i < q; i++){
		if (tp[i] == 1)//remove
			remove(1, 0, sz, get(tl[i]), get(tr[i]));
		else if (tp[i] == 2)//add
			add(1, 0, sz, get(tl[i]), get(tr[i]));
		else
			rev(1, 0, sz, get(tl[i]), get(tr[i]));
		cout << on[1]+1 << "\n";
	}
	return 0;
}