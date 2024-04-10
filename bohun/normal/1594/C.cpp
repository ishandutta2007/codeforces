#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int n;
string s;
char c;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
	cin >> n >> c >> s;
	if (count(s.begin(), s.end(), c) == n) {
	    cout << 0 << endl;
	    continue;
	}
	int res = -1;
	rep(i, 1, n) {
	    int cnt = 0;
	    rep(j, 1, n / i)
		cnt += (s[i * j - 1] != c);
	    if (cnt == 0) 
		res = i;
	}
	if (res != -1)
	    cout << 1 << endl << res << endl;
	else
	    cout << 2 << endl << n - 1 << ' ' << n << endl;
    }

    return 0;
}