#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 5e5 + 10;
const int MOD = 1e9 + 7;

int h, w, n, row[MAXN], tl[MAXN], tr[MAXN], tt[MAXN], sz, ord[MAXN], d[MAXN];
pair<int, int> sec[MAXN];
vector<int> vec[MAXN];

void fix(int &x){while (x >= MOD) x -= MOD;}

void water(int v, int b, int e, int l, int r, int x){
	if (l <= b && e <= r){
		vec[v].push_back(x);
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	water(v<<1, b, mid, l, r, x);
	water(v<<1^1, mid, e, l, r, x);
}

int smoke(int v, int b, int e, int pos, int mn){
	while (vec[v].size() && row[vec[v].back()]+tt[vec[v].back()] < mn) vec[v].pop_back();

	if (e - b == 1){
		if (vec[v].size())
			return vec[v].back();
		return -1;
	}

	int mid = b + e >> 1;
	int x = (vec[v].size()?vec[v].back():-1);
	int y = (pos < mid?smoke(v<<1, b, mid, pos, mn):smoke(v<<1^1, mid, e, pos, mn));
	int ret;
	if (x == -1)
		ret = y;
	else if (y == -1)
		ret = x;
	else{
		if (row[x] > row[y])
			ret = x;
		else
			ret = y;
	}

	return ret;
}

bool cmp(int u, int v){return row[u] < row[v];}
int gPos(pair<int, int> x){return lower_bound(sec, sec + sz, x) - sec;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++){
		cin >> row[i] >> tl[i] >> tr[i] >> tt[i], tl[i]--;
		if (tl[i])
			sec[sz++] = {row[i], tl[i]-1};
		if (tr[i] < w)
			sec[sz++] = {row[i], tr[i]};
	}
	sort(sec, sec + sz);
	int temp = sz;
	for (int i = 0; i < w; i++) sec[sz++] = {h+1, i};
	
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	int cur = 0;
	for (int i = 0; i < sz; i++){
		while (cur < n && row[ord[cur]] <= sec[i].F){
			water(1, 0, w, tl[ord[cur]], tr[ord[cur]], ord[cur]);
			cur++;
		}

		int v = smoke(1, 0, w, sec[i].S, sec[i].F);
		if (v == -1)
			d[i] = 1;
		else{
			if (tl[v])
				d[i] += d[gPos({row[v], tl[v]-1})];
			else
				d[i] += d[gPos({row[v], tr[v]})];

			if (tr[v] < w)
				d[i] += d[gPos({row[v], tr[v]})];
			else
				d[i] += d[gPos({row[v], tl[v] - 1})];

			fix(d[i]);
		}
	}

	int ans = 0;
	for (int i = temp; i < sz; i++){
		ans += d[i];
		fix(ans);
	}
	cout << ans << "\n";
	return 0;
}