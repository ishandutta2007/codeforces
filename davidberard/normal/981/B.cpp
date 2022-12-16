#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<bool, bool> pbb;

struct num {
	int n, v;
	bool A, B;
	num() {}
	num(int a, int d, bool b, bool c) : n(a), v(d), A(b), B(c) {}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<num> v;
	//
	//map<int, pair<bool, bool>> mp;
	map<int, int> mp;
	int N, M, x, a;
	cin >> N;
	for(int i=0;i<N;++i) {
		cin >> a;
		cin >> x;
		mp[a] = x;
		//mp[x] = pbb(true, false);
	}
	cin >> M;
	for(int i=0;i<M;++i) {
		cin >> a;
		cin >> x;
		if(mp.count(a) == 0) {
			mp[a] = 0;
		}
		mp[a] = max(mp[a], x);
	}
	ll tot = 0;
	for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
		//cerr << it->first << ": " << it->second << endl;
		int v = it->second;
		tot += v;
	}
	cout << tot << endl;
	return 0;
}