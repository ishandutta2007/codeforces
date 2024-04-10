#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int n;
deque <int> v;
int cnt = 0;

bool query(int a, int b) {
	// range of indices
	cnt++;
	cout << "? " << (b - a + 1) << ' ';
	for(int i = a; i <= b; i++) cout << v[i] << ' ';
	cout << endl;
	string t; cin >> t;
	if(t == "YES") return true;
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	v.resize(n);
	iota(v.begin(), v.end(), 1);
	while(sz(v) > 2) {
		int tmp = sz(v);
		// cout << cnt << ' ' << sz(v) << '\n';
		int x = tmp/3;
		bool a = query(0, x - 1);
		if(!a) {
			bool b = query(0, x - 1);
			if(!b) {
				// remove first one-third.
				for(int i = 0; i < x; i++) v.pop_front();
				continue;
			}
			a = b;
		}
		// first one-third gave result TRUE
		int y = 2*x;
		bool b = query(x, y - 1);
		if(b) {
			// last one-third removed.
			for(int i = y; i < tmp; i++) v.pop_back();
		} else {
			// middle portion removed.
			deque <int> left;
			for(int i = 0; i < x; i++) left.push_back(v[i]);
			for(int i = y; i < tmp; i++) left.push_back(v[i]);
			v = left;
		}
	}
	// cout << cnt << '\n';
	if(sz(v) == 2) {
		cout << "! " << v.back() << endl;
		string t; cin >> t;
		if(t == ":)") return 0;
		v.pop_back();
	}
	assert(sz(v) == 1);
	cout << "! " << v.back() << endl;
	
	return 0;
}