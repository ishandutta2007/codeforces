#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	int n;
	cin >> n >> s;
	cout << (s.end() - unique(s.begin(), s.end()));
	return 0;
}