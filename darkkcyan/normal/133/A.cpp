#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.find('H') != string::npos or 
	    s.find('Q') != string::npos or
	    s.find('9') != string::npos
	) cout << "YES";
	else cout << "NO";
	return 0;
}