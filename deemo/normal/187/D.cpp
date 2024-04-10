//I am ready for the road less traveled
//Suiting up for my crowning Battle
//This test is my own cross to bear
//But I will get there..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 4e5 + 10;
const int XX = MAXN;
const int INF = 1e9 + 10;

int n, gr, red, sm;
ll tot, x[MAXN], len[MAXN], rem[MAXN];
int sec[XX], sz, mp[XX], weed[4 * XX];
vector<pair<int, int>>	vec[MAXN];

void plant(int v, int b, int e){
	weed[v] = INF;
	if (e - b == 1)	return;

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
}

void water(int v, int b, int e, int l, int r, int z){
	if (l <= b && e <= r){
		weed[v] = z;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e) >> 1;
	water(v<<1, b, mid, l, r, z);
	water(v<<1^1, mid, e, l, r, z);
}

int smoke(int v, int b, int e, int pos, int ret = INF){
	ret = min(ret, weed[v]);
	if (e - b == 1)	
		return ret;

	int mid = (b + e)/ 2;
	if (pos < mid)
		return smoke(v<<1, b, mid, pos, ret);
	return smoke(v<<1^1, mid, e, pos, ret);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> gr >> red;	sm = gr + red;	n++;
	for (int i = 0; i < n; i++){
		cin >> len[i];
		if (i)
			x[i] = x[i - 1] + len[i - 1];
	}
	tot = x[n - 1] + len[n - 1];

	sec[sz++] = 0;
	sec[sz++] = sm;
	for (int i = 1; i < n; i++){
		int temp = x[i] % sm;
		if (temp <= gr)
			vec[i].push_back({gr - temp, gr - temp + red});
		else{
			vec[i].push_back({0, sm - temp});
			vec[i].push_back({sm - (red - (sm - temp)), sm});
		}

		for (auto y:vec[i])
			sec[sz++] = y.F, sec[sz++] = y.S;
	}
	
	{
		sort(sec, sec + sz);
		sz = unique(sec, sec + sz) - sec;
		for (int i = 0; i < sz; i++)
			mp[i] = sec[i];

		for (int i = 0; i < n; i++)
			for (auto &y:vec[i])
				y.F = lower_bound(sec, sec + sz, y.F) - sec
					, y.S = lower_bound(sec, sec + sz, y.S) - sec;

	}

	plant(1, 0, sz);
	rem[n - 1] = len[n - 1];
	for (auto y:vec[n - 1])
		water(1, 0, sz, y.F, y.S, n - 1);
	
	for (int i = n - 2; i; i--){
		int temp = x[i] % sm;
		temp = (sm - temp) % sm;
		int y = upper_bound(sec, sec + sz, temp) - sec;	y--;
		y = smoke(1, 0, sz, y);
		if (y < INF)
			rem[i] = (x[y] - x[i]) + rem[y] + (sm - (x[y] - x[i]) % sm) % sm;
		else
			rem[i] = tot - x[i];
		for (auto z:vec[i])
			water(1, 0, sz, z.F, z.S, i);
	}

	int q;	cin >> q;
	while (q--){
		int y;	cin >> y;	
		ll z = y;	y %= sm;
		y = upper_bound(sec, sec + sz, y) - sec;	y--;
		y = smoke(1, 0, sz, y);
		if (y < INF)
			cout << z + x[y] + rem[y] + (sm - (z + x[y]) % sm) % sm << "\n";
		else
			cout << z + tot << "\n";
	}
	return 0;
}