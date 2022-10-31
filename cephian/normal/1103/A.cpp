#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int a = 0, b = 0;
	string s;
	cin >> s;
	for(int i = 0; i < (int)s.size(); ++i) {
		if(s[i] == '0') {
			cout << "1 " << ++a << "\n";
			a %= 4;
		} else {
			cout << "3 " << 2*b+1 << "\n";
			b = (b+1)%2;
		}
	}
}