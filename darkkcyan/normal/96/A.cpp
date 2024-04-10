#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int c = 1;
	for (int i = 1; i < (int) s.size(); ++i) {
		if (s[i] == s[i - 1]) ++c;
		else c = 1;
		if (c >= 7) break;
	}
	if (c >= 7) cout << "YES";
	else cout << "NO";
	return 0;
}