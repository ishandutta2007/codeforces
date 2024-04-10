#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

bool solve() {
	int n;
	cin >> n;
	vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
	vector<int> b = a;
	sort(b.begin(), b.end());
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	}

	vector<int> u(n);
	vector< vector<int> > ans;
	for (int i = 0; i < n; i++) if (u[i] == 0) {
		int x = i;
		vector<int> r;
		while (u[x] == 0) {
			u[x] = 1;
			r.push_back(x);
			x = a[x];
		}
		ans.push_back(r);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].size();
		for (int j = 0; j < ans[i].size(); ++j)
			cout << ' ' << ans[i][j] + 1;
		cout << endl;
	}

    return false;
}

int main() {

    while (solve());
    
    return 0;
}