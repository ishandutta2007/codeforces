#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int ok(pii x, pii y) {
	map<int,int> S;
	++S[x.first];
	++S[x.second];
	++S[y.first];
	++S[y.second];
	if(S.size() != 3) return 0;
	for(auto x : S)
		if(x.second == 2)
			return x.first;
	assert(false);
	return -1;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pii> a(n), b(m);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for(int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
	}
	// do i know?
	set<int> possible;
	for(auto x : a) {
		for(auto y : b) {
			int d = ok(x, y);
			if(d) {
				possible.insert(d);
			}
		}
	}
	if(possible.size() == 1) {
		cout << *possible.begin() << "\n";
		return 0;
	}
	//do they know?
	bool yes = true;
	for(auto x : a) {
		for(auto y : b) {
			int d = ok(x, y);
			if(d) {
				set<int> pa, pb;
				for(auto x2 : a) {
					int t = ok(y, x2);
					if(t) pa.insert(t);
				}

				for(auto y2 : b) {
					int t = ok(x, y2);
					if(t) pb.insert(t);
				}
				bool b = pa.size() == 1 && pb.size() == 1;
				yes &= b;
			}
		}
	}
	if(yes) cout << "0\n";
	else cout << "-1\n";

}