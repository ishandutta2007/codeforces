#include <bits/stdc++.h>
using namespace std;

string s;
set<int> S;

int main() {
	int n;
	cin >> n >> s;
	if(n > 26) {
		cout << "-1\n";
		return 0;
	}
	int a = 0;
	for(char c : s) {
		if(S.count(c)) ++a;
		else S.insert(c);
	}
	cout << a << "\n";
}