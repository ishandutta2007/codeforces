//asdf
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int INF = 2e9;

int n, x[MAXN], y[MAXN];
vector<int>	vec[MAXN];
pair<pair<int, int>, pair<int, int>> weed[4 * MAXN];
int sec[MAXN], sz;

void plant(int v, int b, int e){
	if (e - b == 1){
		if (vec[b].size())
			weed[v] = {{vec[b].back(), b}, {-INF, b}};
		else
			weed[v] = {{-INF, b}, {-INF, b}};
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = weed[v<<1];
	if (weed[v<<1^1].F > weed[v].S)	weed[v].S = weed[v<<1^1].F;
	if (weed[v].F < weed[v].S)	swap(weed[v].F, weed[v].S);

	if (weed[v<<1^1].S > weed[v].S)	weed[v].S = weed[v<<1^1].S;
	if (weed[v].F < weed[v].S)	swap(weed[v].F, weed[v].S);
}

pair<pair<int, int>, pair<int, int>>	smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return {{-INF, -INF}, {-INF, -INF}};

	int mid = b + e >> 1;
	auto x = smoke(v<<1, b, mid, l, r);
	auto y = smoke(v<<1^1, mid, e, l, r);
	if (y.F > x.S)	x.S = y.F;
	if (x.S > x.F)	swap(x.F, x.S);
	if (y.S > x.S)	x.S = y.S;
	if (x.S > x.F)	swap(x.F, x.S);
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i], x[i]--, vec[x[i]].push_back(y[i]);
	plant(1, 0, n);
	int q;	cin >> q;
	while (q--){
		int sz;	cin >> sz;
		for (int i = 0; i < sz; i++)	cin >> sec[i], sec[i]--;
		sec[sz++] = -1;
		sec[sz++] = n;
		sort(sec, sec + sz);
		pair<pair<int, int>, pair<int, int>> x = {{-1, -1}, {-1, -1}};
		for (int i = 0; i + 1 < sz; i++)
			if (sec[i + 1] - sec[i] - 1 > 0){
				auto y = smoke(1, 0, n, sec[i] + 1, sec[i + 1]);
				if (y.F > x.S)	x.S = y.F;
				if (x.S > x.F)	swap(x.F, x.S);
				if (y.S > x.S)	x.S = y.S;
				if (x.S > x.F)	swap(x.F, x.S);
			}
		if (x.F.F < 1)
			cout << "0 0\n";
		else{
			x.F.F = vec[x.F.S][upper_bound(vec[x.F.S].begin(), vec[x.F.S].end(), x.S.F) - vec[x.F.S].begin()];
			cout << x.F.S+1 << " " << x.F.F << "\n";
		}
	}
	return 0;
}