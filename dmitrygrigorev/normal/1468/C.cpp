#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	int u = 0;
	set<pair<int, int> > money, time;

	vector<int> guys;

	for (int i = 0; i < q; ++i) {

		int t;
		cin >> t;

		if (t == 1) {
			int x;
			cin >> x;
			money.insert(mp(-x, u));
			time.insert(mp(u, x));
			guys.pb(x);
			u++;
		}

		else if (t == 2) {
			auto p = (*time.begin());
			time.erase(time.begin());

			int index = p.x;

			money.erase(money.find(mp(-guys[index], index)));
			cout << index + 1 << ' ';
		}

		else {
			auto p = (*money.begin());
			money.erase(money.begin());

			int index = p.y;

			time.erase(time.find(mp(index, guys[index])));
			cout << index + 1 << ' ';
		}

	}

}