#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

ll k;
string s = "codeforces";
int t[10];

int main() {
	scanf ("%lld", &k);
	rep(i, 0, 9) t[i] = 1;
	ll mam = 1;
	while (mam < k) {
		pair<int, int> mini = {1e9, 1e9};
		rep(i, 0, 9)
			mini = min(mini, {t[i], i});
		mam /= t[mini.se];
		t[mini.se]++;
		mam *= t[mini.se];
	}
	rep(i, 0, 9) 
		rep(j, 1, t[i])
			cout << s[i];
	return 0;
}