#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n; set<int> s;
	for(int i = 0; i < 2; ++i) {
		int m; cin >> m;
		int t; while(m--) {
			cin >> t;
			s.insert(t);
		}
	}
	puts(s.size() == n ? "I become the guy." : "Oh, my keyboard!");
	return 0;
}