#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int add(int x, set<int> &a, set<int> &b) {
	if (a.count(x)) {
		a.erase(a.find(x));
		int Q = 0;
		for (int i = x-1; i <= x+1; ++i) {
			if (b.count(i)) Q++;
		}
		return -Q;
	}
	a.insert(x);
	int Q = 0;
	for (int i = x-1; i <= x+1; ++i) {
		if (b.count(i)) Q++;
	}
	return Q;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	set<int> a, b;

	ll tot = 0;

	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;

		if (x == 1) tot += add(y, a, b);
		else tot += add(y, b, a);
		if (tot == 0) cout << "Yes\n";
		else cout << "No\n";
	}

}