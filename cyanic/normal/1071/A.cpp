#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a),_E=(b); i<=_E; i++)
#define per(i,a,b) for (int i=(a),_E=(b); i>=_E; i--)
#define REP(i,a,b) for (int i=0,_E=(n); i<_E; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int n, m, t;
vi a, b;

int main() {
	cin >> n >> m;
	while (1ll * t * (t + 1) / 2 <= n + m) t++;
	t--;
	per (i, t, 1)
		if (n >= i) {
			a.pb(i); n -= i;
		}
		else b.pb(i);
	cout << a.size() << endl;
	for (auto x : a) cout << x << " ";
	cout << endl;
	cout << b.size() << endl;
	for (auto x : b) cout << x << " ";

	return 0;
}