#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

string s;

vector <string> a, b;

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> s;
		a.pb(s);
	}
	for(int i = 1; i <= m; ++i) {
		cin >> s;
		b.pb(s);
	}
	int q;
	cin >> q;
	while(q--) {
		int k;
		cin >> k;
		k--;
		int k1 = k % n;
		int k2 = k % m;
		cout << a[k1];
		cout << b[k2];
		cout << endl;
	}



	return 0;
}