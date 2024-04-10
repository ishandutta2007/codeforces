#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair
 
using ll = long long;
using namespace std;	

void solve() {
	int a, b, c = 0; 
	scanf("%d%d", &a, &b);
	bool ans = (a <= b);
	rep(i, 0, 30) {
		if (a >> i & 1) c++;
		if (b >> i & 1) c--;
		ans &= c >= 0;
	}
	puts(ans ? "Yes" : "No");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}