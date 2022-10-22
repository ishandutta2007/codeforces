#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int MAXVAL = 200;
const int MOD = 998244353;

int n, a[MAXN], d[2][2][MAXVAL], t[2][MAXVAL], ex[2][MAXVAL];

void add(int &x, int y){
	x += y;
	if (x >= MOD) x -= MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

	int cur = 0;
	if (a[0] >= 0)
		d[cur][0][a[0]] = 1;
	else
		for (int i = 0; i < MAXVAL; i++)
			d[cur][0][i] = 1;

	for (int i = 0; i + 1 < n; i++, cur = !cur){
		memset(d[!cur], 0, sizeof(d[!cur]));

		memset(t, 0, sizeof(t));
		memset(ex, 0, sizeof(ex));
		for (int j = 0; j < MAXVAL; j++) {
			//0
			add(ex[1][j], d[cur][0][j]);
			if (j+1 < MAXVAL)
				add(t[0][j+1], d[cur][0][j]);

			//1
			add(ex[1][j], d[cur][1][j]);
			if (j+1 < MAXVAL)
				add(t[0][j+1], d[cur][1][j]);
			if (j)
				add(t[1][j-1], d[cur][1][j]);
		}

		int sm = 0;
		for (int j = 0; j < MAXVAL; j++){
			add(sm, t[0][j]);
			add(ex[0][j], sm);
		}
		sm = 0;
		for (int j = MAXVAL-1; ~j; j--){
			add(sm, t[1][j]);
			add(ex[1][j], sm);
		}

		for (int w = 0; w < 2; w++)
			for (int j = 0; j < MAXVAL; j++)
				if (a[i+1] < 0 || a[i+1] == j)
					d[!cur][w][j] = ex[w][j];
	}

	int ans = 0;
	for (int i = 0; i < MAXVAL; i++)
		add(ans, d[cur][1][i]);
	cout << ans << "\n";
	return 0;
}