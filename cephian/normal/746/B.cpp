#include <iostream>

using namespace std;

string s;
int main() {
	int n;
	cin >> n >> s;
	for(int i = s.size()-2; i>=0; i-=2)
		cout << s[i];
	for(int i = 1&(s.size()-1); i < n; i+=2)
		cout << s[i];
	cout << "\n";
	return 0;
}