#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 1e6 + 111;
const int mod = 1e9 + 7;

int n, m;
int ile[nax];
int sil[nax];

vector <int> elo;
vector <pair<int, int>> v[nax];

map <vector <pair<int, int>>, int> mapa;

int a, b;

int main() {
	sil[0] = 1;
	FOR(i, nax - 1)
		sil[i] = (ll) sil[i - 1] * i % mod;
	scanf("%d %d", &n, &m);
	FOR(i, n) {
		scanf("%d", &a);
		FOR(j, a) {
			scanf("%d", &b);
			elo.pb(b);
			ile[b] += 1;
		}
		sort(elo.begin(), elo.end());
		elo.erase(unique(elo.begin(), elo.end()), elo.end());
		for(auto it : elo) 
			v[it].pb(mp(i, ile[it]));
		for(auto it : elo)
			ile[it] = 0;
		elo.clear();
	}
	for(int i = 1; i <= m; ++i) {
			mapa[v[i]] += 1;
	}
	int res = 1;
	for(auto it : mapa)
		res = (ll) res * sil[it.se] % mod;
	printf("%d", res);
	
	
	return 0;
}