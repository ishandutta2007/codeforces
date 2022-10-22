#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)	
	
		
using namespace std;

vector <pair<int, int>> v[2];

int n, m;
int a[101][101];

int main() {	
	scanf("%d %d", &n, &m);
	if(n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	FOR(i, 1, n)
		FOR(j, 1, m)
			v[(i + j) % 2].pb(mp(i, j));
	pair<int, int> para = mp(-1, -1);
	FOR(i, 0, ss(v[0]) - 1)
		FOR(j, 0, ss(v[1]) - 1) {
			int sum = abs(v[1][j].fi - v[0][i].fi) + abs(v[1][j].se - v[0][i].se);
			if(sum != 1) {
				para = mp(i, j);
			}
		}
	if(para == mp(-1, -1)) {
		printf("-1\n");
		return 0;
	}
	swap(v[0][para.fi], v[0].back());
	swap(v[1][para.se], v[1][0]);
	int nr = 1;
	for(auto it : v[0]) {
		a[it.fi][it.se] = nr++;
	}
	for(auto it : v[1]) {
		a[it.fi][it.se] = nr++;
	}
	FOR(i, 1, n) {
		FOR(j, 1, m)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	
			
	return 0;
}