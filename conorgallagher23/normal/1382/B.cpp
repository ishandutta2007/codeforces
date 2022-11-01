#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int T = read();
	while (T--) {
		int n = read(); int fir = -1;
		for (int i = 1; i <= n; i++) {
			int x = read();
			if (x != 1 && fir == -1) fir = i - 1; 
		}
		if (fir == -1) {
			if (n & 1) puts("First"); else puts("Second");
		} else {
			if (fir & 1) puts("Second"); else puts("First"); 
		}
	}
	return 0;
}