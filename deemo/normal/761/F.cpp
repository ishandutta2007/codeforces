#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e3 + 5;
const int C = 26;
const int XX = 3e5 + 10;

int n, m, q;
string s[MAXN];
int ta[XX], tb[XX], tc[XX], td[XX], te[XX];
ll pt[C][MAXN][MAXN], tot[C], cost[MAXN][MAXN];
int rem[MAXN][MAXN];

ll get2(int a, int b, int c, int d){
	return cost[c][d] - cost[a][d] - cost[c][b] + cost[a][b];
}

ll get(int w, int a, int b, int c, int d){
	return pt[w][c][d] - pt[w][a][d] - pt[w][c][b] + pt[w][a][b];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)	cin >> s[i];

	for (int i = 0; i < q; i++){
		char c;	cin >> ta[i] >> tb[i] >> tc[i] >> td[i] >> c, tc[i]++, td[i]++;
		te[i] = c - 'a';
		
		pt[te[i]][ta[i]][tb[i]]++;
		pt[te[i]][ta[i]][td[i]]--;
		pt[te[i]][tc[i]][tb[i]]--;
		pt[te[i]][tc[i]][td[i]]++;
		tot[te[i]] += (tc[i] - ta[i]) * (td[i] - tb[i]);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	rem[i][j] = q;

	for (int w = 0; w < C; w++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				pt[w][i + 1][j + 1] += pt[w][i + 1][j] + pt[w][i][j + 1] - pt[w][i][j];
				cost[i + 1][j + 1] += pt[w][i + 1][j + 1] * abs(w - int(s[i][j] - 'a'));
				rem[i][j] -= pt[w][i + 1][j + 1];
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			pt[s[i][j] - 'a'][i + 1][j + 1] += rem[i][j];
	for (int w = 0; w < C; w++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				pt[w][i + 1][j + 1] += pt[w][i + 1][j] + pt[w][i][j + 1] - pt[w][i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cost[i + 1][j + 1] += cost[i + 1][j] + cost[i][j + 1] - cost[i][j];

	ll ans = 1e18;
	for (int i = 0; i < q; i++){
		ll ret = 0;
		ta[i]--, tb[i]--, tc[i]--, td[i]--;
		for (int w = 0; w < C; w++)
			ret += get(w, ta[i], tb[i], tc[i], td[i]) * abs(te[i] - w);

		ret += get2(0, 0, ta[i], m);
		ret += get2(tc[i], 0, n, m);
		ret += get2(ta[i], 0, tc[i], tb[i]);
		ret += get2(ta[i], td[i], tc[i], m);
		ans = min(ans, ret);
	}
	cout << ans << "\n";
	return 0;
}