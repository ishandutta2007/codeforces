#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int nax = 2e5 + 111;

int n, m;
int a[nax];
int b[nax];

LL pt(LL a, LL b) {
	if (!b) return 1;
	if (b & 1) return a * pt(a, b - 1) % m;
	return pt(a * a % m, b / 2);
}

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s[1100];

map <int, int> byl;

int g[1100][1100];

int Pt(int a, int b) {
	if (a <= 1000 && b <= 1000) return g[a][b];
	return pt(a, b);
}

int main() {	
	scanf ("%d", &n);
	scanf ("%d", &m);
	
	LL ans = 1;
	
	rep(i, 0, 1000)
		rep(j, 0, 1000)
			g[i][j] = pt(i, j);
			
	if (n >= 1001) {
		printf ("0\n");
		return 0;
	}
	
	rep(i, 1, n) {
		scanf ("%d", a + i);
		if (byl.find(a[i]) != byl.end()) {
			printf ("0\n");
			return 0;
		}
		byl[a[i]] = 1;
		
		int z = a[i] % m;
		
		rep(j, 0, m - 1) {
			int x = s[j].order_of_key(a[i]);
			int y = ss(s[j]) - x;
			
			int z1 = (z - j + m) % m;
			int z2 = (j - z + m) % m;
			
			ans = ans * Pt(z1, x) % m;
			ans = ans * Pt(z2, y) % m;
		}
		
		s[a[i] % m].insert(a[i]);
	}
				
	printf ("%lld", ans);		
	
		
	
	return 0;
}