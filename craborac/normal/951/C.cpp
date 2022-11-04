
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(a) (int)a.size()
#define mp make_pair	

using namespace std;

typedef long long ll;

int n;

int main() {
	cin >> n;
	string ans = "";
	int qx = 0, qy = 0;
	vector<pair<int, int> > a;
	a.push_back(mp(qx, qy));
	while ((n - 1 - qx) + (n - 1 - qy) > n - 1) {
		if (qx + 1 < n) {
			cout << "? " << qx + 2 << " " << qy + 1 << " " << n << " " << n << endl;
			string p;
			cin >> p;
			if (p == "YES") {
				qx++;
				ans += "D";
			} else {
				qy++;
				ans += "R";
			}
		} else {
			qy++;
			ans += "R";
		}
		a.push_back(mp(qx, qy));
	}
	string tans = "";
	int cd = n - 2;
	int qqx = n - 1, qqy = n - 1;
	for (int j = 0; sz(ans) + sz(tans) < 2 * n - 2; j++) {
		a.pop_back();
		if (qqy > 0) {
			cout << "? " << 1 << " " << 1 << " " << qqx + 1 << " " << qqy << endl;
			string p;
			cin >> p;
			if (p != "YES") {
				tans += "D";
				qqx--;
			} else {
				tans += "R";
				qqy--;
			}
		} else {
			tans += "D";
			qqy--;
		}
	}
	reverse(tans.begin(), tans.end());
	cout << "! " << ans << tans << endl;
	re 0;
}