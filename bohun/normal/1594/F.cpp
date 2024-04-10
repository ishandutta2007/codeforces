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

    int t;
    cin >> t;
    while (t--) {
	// consider prefix sums
	// there can not be both x and x + k in sequence
	// decompose into the chains modulo k
	// see how many elements you can get
	ll s, n, k;
	cin >> s >> n >> k;
	if (s == k) {
	    cout << "YES\n";
	    continue;
	}
	ll cnt = s / k;
	ll diff = k * ((cnt + 1) / 2);
	if (cnt % 2 == 0)
	    diff += s % k + 1;
	cout << (n + 1 <= diff ? "NO\n" : "YES\n");
    }

    return 0;
}