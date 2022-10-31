#include <iostream>

using namespace std;

string a, b;

char g(string& s, int i) {
	if(i < 0) return '0';
	return s[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin >> a >> b;
	int m = max(a.size(), b.size());
	for(int i = -m; i < 0; ++i) {
		char c = g(a, a.size()+i);
		char d = g(b, b.size()+i);
		if(c == d) continue;
		if(c < d) {
			cout << "<\n";
			return 0;
		}
		cout << ">\n";
		return 0;
	}
	cout << "=\n";
	return 0;
}