#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 2e5;
int t, n, a[N], b[N], x;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> t;
    while (t--) {
	cin >> n >> x;
	rep(i, 1, n)
	    cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	bool res = 1;
	rep(i, 1, n) {
	    if (abs(1 - i) < x && abs(n - i) < x && a[i] != b[i])
		res = 0;
	}
	cout << (res ? "YES\n" : "NO\n");
    }

    return 0;
}