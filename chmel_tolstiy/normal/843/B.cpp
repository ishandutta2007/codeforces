#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int go(int s, int tr, int x) {
	while (tr > 0 && s != -1) {
		cout << "? " << s << endl; cout.flush();
		int vl, nx; cin >> vl >> nx;
		if (vl >= x) return vl;
		s = nx;
		--tr;
	}
	return -1;
}

bool solve() {
	srand(time(0));
	int n, s, x;
	cin >> n >> s >> x;	
	int r = go(s, 1, x);
	if (r >= 0) {
		cout << "! " << r << endl;
		return false;
	}

	if (n <= 1000) {
		int res = go(s, 2000, x);	
		cout << "! " << res << endl;
	} else {
		vector<int> ps(1, s); for (int i = 0; i < n; ++i) ps.push_back(i + 1);
		random_shuffle(ps.begin() + 1, ps.end());
		vector<pii> vl;
		for (int i = 0; i < 999; ++i) {
			int v, nx;
			cout << "? " << ps[i] << endl; cout.flush();
			cin >> v >> nx;
			vl.push_back(pii(v, ps[i]));
		}
		vl.push_back(pii(x + 1, n + 1));
		sort(vl.begin(), vl.end());
		for (int i = 0; i + 1 < vl.size(); ++i) if (vl[i + 1].first >= x) {
			int r = go(vl[i].second, 999, x);
			cout << "! " << r << endl;
			return false;
		}
		cout << "! -1" << endl;
	}

    return false;
}

int main() {

    while (solve());
    
    return 0;
}