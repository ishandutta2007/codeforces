#include <iostream>
using namespace std;

bool has(string& s, const string& a, const string& b) {
	int t = s.find(a);
	if (t == string::npos) return false;
	return s.find(b, t + 2) != string::npos;
}

int main() {
	string s;
	cin >> s;
	if (has(s, "AB", "BA") or has(s, "BA", "AB")) cout << "YES";
	else cout << "NO";
	return 0;
}