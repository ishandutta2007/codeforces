#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	while (n --) {
		cin >> ws >> s;
		if (s.size() <= 10) cout << s;
		else cout << s[0] << (s.size() - 2) << s[s.size() - 1];
		cout << '\n';
	}
	
	return 0;
}