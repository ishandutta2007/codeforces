
// Problem : D. Grid-00100
// Contest : Codeforces - Codeforces Round #654 (Div. 2)
// URL : https://codeforces.com/contest/1371/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

bool ans[305][305];
int construct(int n, int k) {
	rep(i, n) rep(j, n) ans[i][j] = 0;
	rep(i, k) {
		int r = i / n;
		int d = i % n;
		int x = d, y = r + d;
		ans[x%n][y%n] = 1;
	}
	int maxr = 0, minr = 1000, maxc = 0, minc = 1000;
	rep(i, n) {
		int cr = 0;
		rep(j, n) cr += ans[i][j];
		maxr = max(maxr, cr);
		minr = min(minr, cr);
	}
	rep(i, n) {
		int cr = 0;
		rep(j, n) cr += ans[j][i];
		maxc = max(maxc, cr);
		minc = min(minc, cr);
	}
	return (maxr-minr)*(maxr-minr) + (maxc-minc)*(maxc-minc);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
    	int n, k; cin >> n >> k;
    	cout << construct(n, k) << '\n';
    	rep(i, n) {
    		rep(j, n) cout << ans[i][j];
    		cout << '\n';
    	}
    }
}