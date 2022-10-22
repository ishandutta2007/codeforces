#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;
const int MOD = 998244353;

int n, m, a[MAXN][MAXN], sz, d[MAXN][MAXN];
pii sec[MAXN*MAXN];

bool cmp(pii x, pii y){return a[x.F][x.S] < a[y.F][y.S];}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j], sec[sz++] = {i, j};
	sort(sec, sec + sz, cmp);

	int smD = 0, p1 = 0, p2 = 0, pp1 = 0, pp2 = 0;
	for (int l = 0; l < sz;){
		int r = l;
		while (r < sz && a[sec[l].F][sec[l].S] == a[sec[r].F][sec[r].S]) r++;

		for (int i = l; i < r; i++){
			auto v = sec[i];
			d[v.F][v.S] = smD;
			add(d[v.F][v.S], 1ll*v.F*v.F*l%MOD);
			add(d[v.F][v.S], 1ll*v.S*v.S*l%MOD);
			add(d[v.F][v.S], p1);
			add(d[v.F][v.S], p2);
			add(d[v.F][v.S], -2ll*v.F*pp1%MOD);
			add(d[v.F][v.S], -2ll*v.S*pp2%MOD);

			if (l)
				d[v.F][v.S] = 1ll*d[v.F][v.S]*pw(l, MOD-2)%MOD;
		}
		
		for (; l < r; l++)
			add(smD, d[sec[l].F][sec[l].S]), add(p1, sec[l].F*sec[l].F), add(p2, sec[l].S*sec[l].S)
				, add(pp1, sec[l].F), add(pp2, sec[l].S);
	}

	int x, y; cin >> x >> y, x--, y--;
	cout << d[x][y] << "\n";
	return 0;
}