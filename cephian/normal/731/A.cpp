#include <bits/stdc++.h>

using namespace std;

int m(int a) {
	return (a%26+26)%26;
}

int main() {
	string s;
	cin >> s;
	s = "a"+s;
	int a = 0;
	for(int i = 1; i < s.size(); ++i) {
		a += min(m(s[i]-s[i-1]),m(s[i-1]-s[i]));
	}
	cout << a << "\n";
	return 0;
}