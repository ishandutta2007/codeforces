#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n; cin >> n >> ws;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		char a; cin >> a; a -= 48;
		switch (a) {
			case 0:
			case 1:
				break;
			case 2:
			case 3:
			case 5:
			case 7:
				ans.push_back(a);
				break;
			case 4:
				ans.push_back(2);
				ans.push_back(2);
				ans.push_back(3);
				break;
			case 6:
				ans.push_back(3);
				ans.push_back(5);
				break;
			case 8:
				ans.push_back(7);
				ans.push_back(2);
				ans.push_back(2);
				ans.push_back(2);
				break;
			case 9:
				ans.push_back(7);
				ans.push_back(2);
				ans.push_back(3);
				ans.push_back(3);
				break;
		}
	}
	sort(ans.rbegin(), ans.rend());
	for (auto i: ans) cout << i;
	
	return 0;
}