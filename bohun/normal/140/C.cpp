#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	 		
			
const int N = 1e5 + 101;

int n;
map <int, int> cnt;
vector <int> out[N];

bool solve(int k) {
	rep(i, 0, k - 1) out[i].clear();
	int j = 0;
	for (auto a : cnt) {
		int ile = min(k, a.se);
		while (ile--) {
			out[j++].pb(a.fi);
			j %= k;
		}
	}
	rep(i, 0, k - 1) if (ss(out[i]) < 3) return false;
	return true;
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		int a;scanf ("%d", &a);
		cnt[a]++;
	}
	
	int l = 0, r = n;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (solve(m)) l = m;
		else r = m - 1;
	}
	
	solve(l);
		
	printf ("%d\n", l);
	rep(i, 0, l - 1) {
		sort(all(out[i]));
		reverse(all(out[i]));
		printf ("%d %d %d\n", out[i][0], out[i][1], out[i][2]);
	}
		
	return 0;
}