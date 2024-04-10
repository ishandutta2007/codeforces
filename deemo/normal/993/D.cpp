#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 50 + 2;
const int MAXP = 100 + 2;
const ll INF = 1e10;

ll d[2][MAXN*MAXP][MAXN][MAXN];
int n, p[MAXN], c[MAXN], sec[MAXN];

bool cmp(int u, int v){return p[u] > p[v];}

void smin(ll &x, ll y){x = min(x, y);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(d, 63, sizeof(d));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);

	int t = 0, cur = 0;
	d[cur][0][0][0] = 0;
	for (int i = 0; i < n; i++, cur = !cur){
		int id = sec[i];
		bool same = (i && p[id] == p[sec[i-1]]);

		memset(d[!cur], 63, sizeof(d)/ 2);
		if (same)
			t++;
		else {
			for (int tot = 0; tot <= i*MAXP; tot++)
				for (int x = 0; x <= i-t; x++)
					for (int y = 1; y <= t; y++) {
						smin(d[cur][tot][x+y][0], d[cur][tot][x][y]);
						d[cur][tot][x][y] = INF;
					}
			t = 1;
		}

		for (int tot = 0; tot <= i * MAXP; tot++)
			for (int x = 0; x <= i+1-t; x++)
				for (int y = 0; y < t; y++)
					if (d[cur][tot][x][y] < INF) {
						smin(d[!cur][tot + c[id]][x][y+1], d[cur][tot][x][y] + p[id]);
						if (x)
							smin(d[!cur][tot][x-1][y], d[cur][tot][x][y]);
					}
	}
	for (int tot = 0; tot <= n*MAXP; tot++)
		for (int x = 0; x <= n-t; x++)
			for (int y = 1; y <= t; y++) {
				smin(d[cur][tot][x+y][0], d[cur][tot][x][y]);
				d[cur][tot][x][y] = INF;
			}

	ll ans = 1e17;
	for (int sm = 1; sm <= n*MAXP; sm++)
		for (int x = 0; x <= n; x++)
			if (d[cur][sm][x][0] < INF)
				ans = min(ans, (1000ll * d[cur][sm][x][0] + sm - 1)/ sm);
	cout << ans << endl;
	return 0;
}