#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> ws >> s;
	int l = count_if(s.begin(), s.end(), ::islower);
	transform(s.begin(), s.end(), s.begin(), l >= s.size() - l ? ::tolower : ::toupper);
	cout << s;
	return 0;
}