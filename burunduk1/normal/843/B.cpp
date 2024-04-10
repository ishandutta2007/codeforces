/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

std::mt19937 gen(time(NULL)); // seed = const
int n, s, x;

int main() {
	scanf("%d%d%d", &n, &s, &x), s--;

	// int A[n], B[n];
	// forn(i, n) scanf("%d%d", &A[i], &B[i]);

	int opt_i = s, value;
	auto query = [&]( int i ) {
		printf("? %d\n", i + 1);
		fflush(stdout);
		int a, b;
		scanf("%d%d", &a, &b);
		return make_pair(a, b);
		// return make_pair(A[i], B[i]);
	};
	value = query(s).first;
	forn(_, 1100) {
		int i = gen() % n;
		int t = query(i).first;
		if (t <= x && t > value)
			opt_i = i, value = t;
	}
	// fprintf(stderr, "opt : i=%d, value=%d\n", opt_i, value);
	int i = opt_i, cnt = 0;;
	auto p = query(i);
	while (p.first < x) {
		// fprintf(stderr, "opt : i=%d, p=%d %d\n", i, p.first, p.second);
		// if (++cnt > 10) return 0;
		if (p.second == -1) {
			puts("! -1");
			return 0;
		}
		p = query(p.second - 1);
	}
	printf("! %d\n", p.first);
}