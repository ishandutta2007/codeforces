#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(char c : s) {
		if(c == 'o') ++a;
		else ++b;
	}
	if(a == 0 || b%a == 0) cout << "YES\n";
	else cout << "NO\n";
}