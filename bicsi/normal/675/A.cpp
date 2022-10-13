#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if(c == 0) {
		if(a == b) {cout << "YES";}
		else {cout << "NO";}
	} else {
		b -= a;
		if(c < 0) {c = -c, b = -b;}
		if(b < 0 || b % c) {cout << "NO";}
		else cout << "YES";
	}


	return 0;
}