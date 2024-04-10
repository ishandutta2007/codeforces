#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	while(1) {
		cin >> s;
		if(s == "end") break;
		if(s == "mistake") break;

		int i = 1;
		for(i = 1; i <= 30; i++) {
			printf("? %d %d\n", (1 << (i)), (1 << (i - 1))); fflush(stdout);
			cin >> s;
			if(s == "e") return 0;
			if(s == "y") break;
		}

		if(i > 30) { printf("! 1\n"); fflush(stdout); continue; }

		int l = (1 << (i - 1)) + 1;
		int r = (1 << i);
		int X = r;

		while(l <= r) {
			int m = l + r >> 1;
			printf("? %d %d\n", X, m); fflush(stdout);
			cin >> s;
			if(s == "e") return 0;
			if(s == "y") l = m + 1;
			else r = m - 1;
		}
		printf("! %d\n", l); fflush(stdout);
	}
	return 0;
}