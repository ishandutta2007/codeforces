#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e3 + 10;
ll INF = 1e18;

int n, w[MAXN][MAXN], q[MAXN];
bool mark[MAXN];
ll d[MAXN];

void update(int v){
	for (int u = 0; u < n; u++)
		if (!mark[u])
			d[u] = min(d[u], d[v] + w[u][v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int tt = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			cin >> w[i][j], w[j][i] = w[i][j], tt = min(tt, w[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i^j)
				w[i][j] -= tt;

	memset(d, 63, sizeof(d));
	int h = 0, t = 0;
	for (int i = 0; i < n; i++){
		int mn = 1e9;
		for (int j = 0; j < n; j++)
			if (i^j)
				mn = min(mn, w[i][j]);

		d[i] = min(d[i], mn*2ll);
		if (mn == 0){
			q[t++] = i;
			d[i] = 0;
			mark[i] = 1;
		}
	}

	int rem = n;
	for (int v = 0; v < n; v++)
		if (mark[v]) update(v), rem--;

	while (rem--){
		pair<ll, int> mn(INF, -1);
		for (int v = 0; v < n; v++)
			if (!mark[v])
				mn = min(mn, {d[v], v});
		
		mark[mn.S] = 1;
		update(mn.S);
	}

	for (int v = 0; v < n; v++)
		cout << 1ll*tt*(n-1) + d[v] << "\n";
	return 0;
}