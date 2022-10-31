#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for(char c : s) {
		if('0' <= c && c <= '9') {
			ans += (c-'0')%2;
		} else {
			switch(c) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					++ans;
					break;
			}
		}
	}
	cout << ans << "\n";
}