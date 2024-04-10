#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

string a, b, c, d, x, y;

map <string, int> m[2];

void go(string s, int q) {
	if (m[q].find(s) != m[q].end()) return;
	m[q][s] = 1;
	if (m[!q].find(s) != m[!q].end()) {
		printf ("YES\n");
		exit(0);
	}
	rep(i, 0, 3) rep(j, 0, 3) {
		if ((i ^ j) != 3 && (s[i] == 'X' || s[j] == 'X')) {
			swap(s[i], s[j]);
			go(s, q);
			swap(s[i], s[j]);
		}
	}
}
			

int main() {
	cin >> a >> b >> c >> d;
	x = a + b;
	y = c + d;
	go(x, 0);
	go(y, 1);
	printf ("NO\n");
	return 0;
}