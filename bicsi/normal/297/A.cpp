#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x<<" "<<x<<'\n'

string a, b;

int main() {
	cin >> a >> b;

	int ca = 0, cb = 0;
	for(auto c : a) {
		if(c == '1') ca += 1;
	}
	for(auto c : b) {
		if(c == '1') cb += 1;
	}

	if(ca % 2) ca += 1;
	if(ca >= cb) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}