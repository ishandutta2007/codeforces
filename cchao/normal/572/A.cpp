#include <bits/stdc++.h>
using namespace std;
int main() {
	int aa, bb; 
	cin >> aa >> bb;
	int a, b; cin >> a >> b;

	int na = 0, nb = 0;
	for(int i = 1; i <= aa; ++i) {
		int x; cin >> x;
		if(i == a)
			na = x;
	}
	for(int i = 1; i <= bb; ++i) {
		int x; cin >> x;
		if(i + b - 1  == bb)
			nb = x;
	}
	puts(na < nb ? "YES" : "NO");

	return 0;
}