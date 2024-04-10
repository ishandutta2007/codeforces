#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	char now = 'a';
	string big;
	cin >> big;

	int rem = 0;
	while(big.size()) {
		char top = big.front();

		if(top > 'z') {
			cout << "NO\n";
			return 0;
		}

		if(top != now) {
			cout << "NO\n";
			return 0;
		}

		string nw = "";
		for(auto &c : big) 
			if(c != top) 
				nw += c;
		big = nw;
		++now;
	}

	cout << "YES\n";
	return 0;

	return 0;
}