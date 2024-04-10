#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		int p, c;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			if(a < b) ok = false;
			if(i > 1) {
				if(p > a) ok = false;
				if(c > b) ok = false;
				if(b - c > a - p) ok = false;
			}
			p = a; c = b;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}