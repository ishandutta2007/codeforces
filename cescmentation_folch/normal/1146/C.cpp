#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

int main() {
	cout.flush();
	int cas;
	cin >> cas;
	while (cas--) {
		int n;
		cin >> n;
		int res = 0;
		for (int i = 0; i < 7; ++i) {
			vi u[2];
			for (int j = 1; j <= n; ++j) {
				if (j&(1<<i)) u[1].push_back(j);
				else u[0].push_back(j);
			}
			if (u[0].size() == 0 or u[1].size() == 0) continue;
			cout << u[0].size() << ' ' << u[1].size();
			for (auto x : u[0]) cout << ' ' << x;
			for (auto x : u[1]) cout << ' ' << x;
			cout << endl;
			int rr;
			cin >> rr;
			res = max(res, rr);
		}
		cout << -1 << ' ' << res << endl;
	}
}