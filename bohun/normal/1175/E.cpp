#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 5e5 + 5, pod = (1 << 16), inf = 1e9 + 5;

int n, q, m;
int l[nax], r[nax];
int ql[nax], qr[nax];
int prawo[nax];
int lca[nax][21];
		

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 0; nax > i; ++i)
		prawo[i] = i;
	for(int i = 1; n >= i; ++i) {
		cin >> l[i] >> r[i];
		prawo[l[i]] = max(prawo[l[i]], r[i]);
	}
	int maks = 0;
	for(int i = 0; i < nax; ++i) {
		maks = max(maks, prawo[i]);
		lca[i][0] = maks;
	}
	
	for(int j = 1; j <= 20; ++j) {
		for(int i = 0; i < nax; ++i) {
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
		}
	}
	
	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		int ile = 0;
		for(int j = 20; 0 <= j; --j) {
			if(lca[a][j] < b) {
				a = lca[a][j];
				ile += (1 << j);
			}
		}
		if(lca[a][0] < b) {
			cout << -1 << endl;
		}
		else {
			cout << ile + 1 << endl;
		}
	}
	
	
	
		
	
    return 0;
}