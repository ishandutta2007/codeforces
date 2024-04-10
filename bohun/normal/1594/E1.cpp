#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

ll power(ll a, ll b, ll P) {
    ll res = 1;
    while (b) {
	if (b % 2)
	    res = res * a % P;
	a = a * a % P;
	b /= 2;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int P = 1e9 + 7;
    int k;
    cin >> k;
    ll exp = (power(2, k, P - 1) + (P - 1) - 2) % (P - 1);
    cout << 6LL * power(4, exp, P) % P;

    return 0;
}