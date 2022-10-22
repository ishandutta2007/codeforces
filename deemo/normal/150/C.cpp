#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<utility>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const int MAXN = 2e5 + 10;

ll n, m, c, x[MAXN], p[MAXN];
ld d[MAXN], weed[4][4 * MAXN];

void plant(int v, int b, int e){
	if (e - b == 1){
		weed[1][v] = weed[2][v] = weed[3][v] = d[b];
		weed[0][v] = max(d[b], ld(0));
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[0][v] = max({weed[0][v<<1], weed[0][v<<1^1], weed[2][v<<1] + weed[1][v<<1^1]});
	weed[1][v] = max(weed[1][v<<1], weed[3][v<<1] + weed[1][v<<1^1]);
	weed[2][v] = max(weed[2][v<<1^1], weed[3][v<<1^1] + weed[2][v<<1]);
	weed[3][v] = weed[3][v<<1] + weed[3][v<<1^1];
}

pair<pair<ld, ld>, pair<ld, ld>>	smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return {{weed[1][v], weed[2][v]}, {weed[0][v], weed[3][v]}};
	if (r <= b || e <= l)	return {{0, 0}, {0, 0}};

	int mid = (b + e)/ 2;
	auto f = smoke(v<<1, b, mid, l, r);
	auto g = smoke(v<<1^1, mid, e, l, r);
	pair<pair<ld, ld>, pair<ld, ld>>	ret;
	ret.F.F = max(f.F.F, f.S.S + g.F.F);
	ret.F.S = max(g.F.S, g.S.S + f.F.S);
	ret.S.F = max({f.S.F, g.S.F, f.F.S + g.F.F});
	ret.S.S = f.S.S + g.S.S;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(9);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)	cin >> x[i];
	for (int i = 0; i < n - 1; i++)	cin >> p[i];
	for (int i = 0; i < n - 1; i++)
		d[i] = (ld(x[i + 1] - x[i])/2. - ld(p[i])/ 100. * c);
	plant(1, 0, n);

	ld sm = 0;
	for (int i = 0; i < m; i++){
		int l, r;	cin >> l >> r, l--, r--;
		ld temp = sm;
		sm += smoke(1, 0, n, l, r).S.F;
	}
	cout << sm << "\n";
	return 0;
}