#include <bits/stdc++.h>

using namespace std;

char S[303030];

vector<int> v;
int a, b;

int main() {
	int Q; scanf("%d", &Q);
	while(Q--) {
		v.clear();

		scanf("%d%d", &a, &b);
		scanf("%s", S + 1);
		int N = strlen(S + 1);
		S[N + 1] = 'X';

		int c = 0;
		for(int i = 1; i <= N + 1; i++) {
			if(S[i] == 'X') {
				if(c >= b) v.push_back(c);
				c = 0;
			}
			else c++;
		}

		if(2 * b <= a) {
			if(v.size() == 1) {
				if(a <= v[0] && v[0] <= a + 2 * (b - 1)) puts("YES");
				else puts("NO");
			}
			else puts("NO");
		}
		else {
			int c0 = 0, c1 = 0, c2 = 0, t;
			for(int i : v) {
				if(b <= i && i < a) c0++;
				else if(i < 2 * b) c1++;
				else { c2++; t = i; }
			}
			if(c2 >= 2) { puts("NO"); continue; }
			if(c0) { puts("NO"); continue; }
			if(!c2) { puts((c1 & 1) ? "YES" : "NO"); continue; }
			if(c1 & 1) {
				puts((2 * a <= t && t <= a + 3 * b - 2) ? "YES" : "NO");
			}
			else {
				if(a <= t && t <= a + 2 * b - 2) puts("YES");
				else if(3 * a <= t && t <= a + 4 * b - 2) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}