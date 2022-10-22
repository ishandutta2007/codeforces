#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 500 + 2;
const int LOG = 60;

int n, m;
bitset<MAXN> st[LOG+1][MAXN], tt[LOG+1][MAXN], cur, temp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b, c; cin >> a >> b >> c, a--, b--;
		if (!c)
			st[0][a][b] = 1;
		else
			tt[0][a][b] = 1;
	}
	for (int w = 1; w < LOG; w++)
		for (int v = 0; v < n; v++){
			for (int u = st[w - 1][v]._Find_first(); u < MAXN; u = st[w - 1][v]._Find_next(u))
				st[w][v] |= tt[w - 1][u];
			for (int u = tt[w - 1][v]._Find_first(); u < MAXN; u = tt[w - 1][v]._Find_next(u))
				tt[w][v] |= st[w - 1][u];
		}

	ll ans = 0;
	cur[0] = 1;
	int c = 0;
	for (int w = LOG - 1; ~w; w--){
		temp.reset();
		if (!c){
			for (int v = cur._Find_first(); v < MAXN; v = cur._Find_next(v))
				temp |= st[w][v];
			if (temp.count() > 0){
				cur = temp;
				c = !c;
				ans += 1ll<<w;
			}
		}
		else{
			for (int v = cur._Find_first(); v < MAXN; v = cur._Find_next(v))
				temp |= tt[w][v];

			if (temp.count() > 0){
				cur = temp;
				c = !c;
				ans += 1ll<<w;
			}
		}
	}

	ll temp = 1e18;
	if (ans > temp)
		ans = -1;
	cout << ans << "\n";
	return 0;
}