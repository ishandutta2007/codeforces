#include <bits/stdc++.h>

using namespace std;

string t;
string s[10];

int main() {
	cin >> t;
	for(int i = 0; i < 5; i++) cin >> s[i];
	for(int i = 0; i < 5; i++) {
		if(s[i][0] == t[0] || s[i][1] == t[1]) {
			puts("YES"); return 0;
		}
	}
	puts("NO"); return 0;
}