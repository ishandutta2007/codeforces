#include <bits/stdc++.h>
using namespace std;

int main() {	
	int n;
	cin >> n;
	int a = 1, b = 2;
	while(n--) {
		int c;
		cin >> c;
		if(c == a) {
			b = 6-a-b;
		} else if(c == b) {
			a = 6-a-b;
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}