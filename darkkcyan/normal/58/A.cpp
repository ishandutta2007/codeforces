#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	string t = "hello";
	
	int p = -1;
	for (int i = 0; i < t.size(); ++i) {
		p = s.find(t[i], p + 1);
		if (p == string::npos) return cout << "NO", 0;
	}
	cout << "YES";
	return 0;
}