// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
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

const int nax = 1e6 + 11;
const int mod = 1e9 + 7;

int n, k;
map <int, int> mapa, del;
int a, b;
vector <pair<int, int>> res;

int main() {
	scanf("%d %d", &n, &k);
	FOR(i, n) {
		scanf("%d %d", &a, &b);
		mapa[a] += 1;
		mapa[b] += 0;
		del[b] -= 1;
	}
	int mam = 0;
	int pocz = mod;
	for(auto it : mapa) {
		mam += it.se;
		if(pocz == mod && mam >= k) {
			pocz = it.fi;
		}
		mam += del[it.fi];
		if(pocz != mod && mam < k) {
			res.pb(mp(pocz, it.fi));
			pocz = mod;
		}
	}
	printf("%d\n", ss(res));
	for(auto it : res)
		printf("%d %d\n", it.fi, it.se);
	
	
	
	return 0;
}