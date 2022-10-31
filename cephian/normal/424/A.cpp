#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
string s;

int main() {
	cin >> n;
	cin >> s;
	int u=0;
	for(int i = 0; i < n; ++i) {
		u += s[i]=='x';
	}
	cout << abs(u-n/2) << "\n";
	for(int i = 0; i < n; ++i) {
		if(u == n/2) break;
		if(u < n/2 && s[i] == 'X') {
			++u;
			s[i] = 'x';
		}
		else if(u > n/2 && s[i] == 'x'){
			--u;
			 s[i] = 'X';
		 }
	}
	cout << s << "\n";
	return 0;
}