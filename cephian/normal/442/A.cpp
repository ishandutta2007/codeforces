#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int col(char c) {
	if(c == 'R') return 0;
	if(c == 'G') return 1;
	if(c == 'B') return 2;
	if(c == 'Y') return 3;
	return 4;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	set<string> s;
	for(int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		s.insert(t);
	}
	vector<string> v(s.begin(), s.end());

	int ok = 0x7fffffff;
	for(int i = (1<<10)-1; i >= 0; --i) {
		vector<int> id(v.size(), 0);
		int count = 0;
		for(int j = 0; j < 10; ++j) {
			if(!((1<<j)&i)) continue;
			++count;
			if(j < 5) {
				for(int k = 0; k < (int)v.size(); ++k) {
					if(col(v[k][0]) == j)
						id[k] += j+1;
				}
			} else {
				for(int k = 0; k < (int)v.size(); ++k) {
					if(v[k][1]-'1' == j-5)
						id[k] += 6*(j+1);
				}
			}
		}
		set<int> all;
		for(int x : id) 
			all.insert(x);
		if(all.size() == id.size())
			ok = min(ok, count);
	}
	cout << ok << "\n";
}