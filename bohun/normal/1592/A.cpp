#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int t, n, a[1024], h;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> t;
    while (t--) {
	cin >> n >> h;
	rep(i, 1, n)
	    cin >> a[i];
	sort(a + 1, a + n + 1);
	int s = (a[n - 1] + a[n]);
	cout << h / s * 2 + (h % s == 0 ? 0 : (h % s <= a[n] ? 1 : 2)) << endl;
    }

    return 0;
}