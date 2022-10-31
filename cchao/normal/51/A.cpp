#include <bits/stdc++.h>
using namespace std;

unordered_set<int> f;

char s[22];
void read() {
	int sz = 0;
	for(; sz < 4; ) {
		int c = getchar();
		if(isdigit(c)) {
			s[sz++] = c;
		}
	}

	swap(s[2], s[3]);
	s[sz] = 0;
	int mi = 12345678;

	for(int i = 0; i < 4; ++i) {
		mi = min(mi, atoi(s));
		char tmp = s[0];
		s[0] = s[1];
		s[1] = s[2];
		s[2] = s[3];
		s[3] = tmp;
	}

	f.insert(mi);
}


int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		read();
		if(i != n - 1) scanf("%s", s);
	}

	cout << f.size() << endl;

	return 0;
}