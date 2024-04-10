#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;
const int SS = 30;
const int INF = 1e9 + 2;

int lc[SS] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777};
int n, q, vec[MAXN];
int weed[4 * MAXN], cnt[4 * MAXN], nut[4 * MAXN], ps[4 * MAXN];

void sprout(int v){
	if (weed[v<<1] <= weed[v<<1^1])
		weed[v] = weed[v<<1], ps[v] = ps[v<<1], cnt[v] = cnt[v<<1];
	else
		weed[v] = weed[v<<1^1], ps[v] = ps[v<<1^1], cnt[v] = cnt[v<<1^1];

	if (weed[v<<1] == weed[v<<1^1])
		cnt[v] = cnt[v<<1] + cnt[v<<1^1];
}

void plant(int v, int b, int e){
	if (e - b == 1){
		int pos = lower_bound(lc, lc + SS, vec[b]) - lc;
		if (pos == SS)
			weed[v] = INF;
		else
			weed[v] = lc[pos] - vec[b];

		cnt[v] = 1;
		ps[v] = b;
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	sprout(v);
}

void absorb(int v){
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	weed[v<<1] += nut[v];
	weed[v<<1^1] += nut[v];
	nut[v] = 0;
}

void put(int v, int b, int e, int x, int val){
	if (e - b == 1){
		vec[b] -= nut[v];	nut[v] = 0;

		int pos = lower_bound(lc, lc + SS, vec[b] + val) - lc;
		if (pos == SS)
			weed[v] = INF;
		else
			weed[v] = lc[pos] - (vec[b] + val);

		cnt[v] = 1;
		weed[v] += val;
		ps[v] = b;
		return;
	}

	int mid = (b + e)/ 2;
	absorb(v);
	if (x < mid)
		put(v<<1, b, mid, x, val);
	else
		put(v<<1^1, mid, e, x, val);
	sprout(v);
}

void water(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		weed[v] -= val;
		nut[v] -= val;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	absorb(v);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
	sprout(v);
}

pair<int, int>	get_weed(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	{weed[v], ps[v]};
	if (r <= b || e <= l)	return	{INF, INF};

	int mid = (b + e)/ 2;
	absorb(v);
	return	min(get_weed(v<<1, b, mid, l, r), get_weed(v<<1^1, mid, e, l, r));
}

pair<int, int> smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	{weed[v], weed[v] == 0?cnt[v]:0};
	if (r <= b || e <= l)	return	{INF, 0};

	int mid = (b + e)/ 2;
	absorb(v);
	
	pair<int, int>	aa = smoke(v<<1, b, mid, l, r), bb = smoke(v<<1^1, mid, e, l, r);
	if (aa.first && bb.first)	return	{INF, 0};
	if (aa.first == bb.first)	return	{aa.first, aa.second + bb.second};
	if (aa.first < bb.first)
		return	aa;
	return	bb;
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	plant(1, 0, n);

	while (q--){
		string type;	cin >> type;
		if (type[0] == 'c'){
			int l, r;	cin >> l >> r;	l--;
			cout << smoke(1, 0, n, l, r).second << "\n";
		}
		else{
			int l, r, d;	cin >> l >> r >> d;	l--;
			pair<int, int>	temp;

			while (1){
				temp = get_weed(1, 0, n, l, r);
				if (temp.first - d >= 0)	break;
				put(1, 0, n, temp.second, d);
			}
			water(1, 0, n, l, r, d);
		}
	}
	return	0;
}