#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E5+8;

_ tc, n;
char a[maxn];
set<char> st;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf(" %s", a+1);
		n = strlen(a+1);
		st.clear();
		for(_ i = 1; i <= n; ++i) st.insert(a[i]);
		bool ok = true;
		for(char i : st) for(char j : st) if(i != j) {
//			printf("i = %c, j = %c\n", i, j);
			_ c = 0, ci = 0, cj = 0;
			for(_ k = 1; k <= n; ++k) {
				if(a[k] == i) ++ci;
				if(a[k] == j) ++cj;
//				printf("ci = %lld, cj = %lld, c = %lld\n", ci, cj, c);
				if(ci-cj+c > 1) {
					ok = false;
					break;
				}
				c = max(c, -ci+cj);
			}
		}
		puts(ok ? "YES" : "NO");
	}

	return 0;
}