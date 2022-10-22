#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
void solve () {
	int n,m;
	scanf ("%d %d",&n,&m);
	vector<vector<int>> a(n+1,vector<int>(m+1)); bool bad = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf ("%d",&a[i][j]);
			int cnt = (i>1)+(i<n)+(j>1)+(j<m);
			if (a[i][j] > cnt) bad = 1;
		}
	}
	if (bad) return (void) printf ("NO\n");
	printf ("YES\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf ("%d ",(i>1)+(i<n)+(j>1)+(j<m));
		}
		printf ("\n");
	}
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}

// - + - + - + - +
/*

*/