#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

int n, m;
map <string ,int> ma, byl;
string s;

vector <string> l, mid1, mid2, r;

int main() {	
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> s;
		ma[s]++;
	}
	
	for (auto it : ma) {
		if (byl[it.fi] == 1) continue;
		string rev = it.fi;
		reverse(rev.begin(), rev.end());
		if (rev == it.fi) {
			int x = it.se;
			while (x >= 2) {
				l.pb(it.fi);
				r.pb(it.fi);
				x -= 2;
			}
			if (x == 1) mid1.pb(it.fi);
		}
		else {
			rep(i, 1, min(it.se, ma[rev])) {
				l.pb(it.fi);
				r.pb(rev);
			}
		}
		byl[rev] = 1;
	}
	
	while (ss(mid1) > 1) mid1.pop_back();
	
	cout << m * (ss(l) + ss(mid1) + ss(r)) << endl;
	for (auto it : l)
		cout << it;
	for (auto it : mid1)
		cout << it;
	reverse(r.begin(), r.end());
	for (auto it : r)
		cout << it;
	
	
	return 0;
}