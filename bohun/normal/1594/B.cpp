#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int P = 1e9 + 7;
    int t;
    cin >> t;
    while (t--) {
	ll n, k;
	cin >> n >> k;
	ll res = 0, p = 1;
	rep(i, 0, 30) {
	    if (k >> i & 1)
		res = (res + p) % P;
	    p = p * n % P;
	}
	cout << res << endl;
    }

    return 0;
}