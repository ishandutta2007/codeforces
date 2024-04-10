#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int c0 = 0, c1 = 0;
	for(char c : s) {
		if(c == '0') {
			printf("%d %d\n", c0 + 1, 1);
			c0 = (c0 + 2) % 4;
		}else {
			printf("%d %d\n", c1 + 1, 2);
			c1 = (c1 + 1) % 4;
		}
	}
}