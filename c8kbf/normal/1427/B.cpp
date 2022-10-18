#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, cnt, tc;
struct pr {
	_ l, r;
	bool operator < (const pr &b) const {
		return r-l < b.r-b.l;
	}
} a[maxn], st, ed;
char b[maxn];

int main() {
	
	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &n, &m);
		_ p = 1;
		cnt = 0;
		st = ed = (pr){-1, -2};
		for(_ i = 1; i <= n; ++i) {
			scanf(" %c", &b[i]);
			if(i == 1) continue;
			if(b[i] != b[i-1]) {
				if(b[i-1] == 'L') {
					if(p == 1) st = (pr){p, i-1};
					else a[++cnt] = (pr){p, i-1};
				}
				p = i;
			}
		}
		if(b[n] == 'L') ed = (pr){p, n};
		if(cnt) sort(a+1, a+1+cnt);
		for(_ i = 1; i <= cnt; ++i) for(_ j = a[i].l; j <= a[i].r; ++j) if(m) {
			--m;
			b[j] = 'W';
		}
		for(_ i = st.r; i >= st.l; --i) if(m) {
			--m;
			b[i] = 'W';
		}
		for(_ i = ed.l; i <= ed.r; ++i) if(m) {
			--m;
			b[i] = 'W';
		}
		//printf("b: %s, m: %lld\n", b+1, m);
		_ c = 0;
		for(_ i = 1; i <= n; ++i) if(b[i] == 'W') {
			++c;
			if(b[i-1] == 'W') ++c;
		}
		printf("%lld\n", c);
	}
		
	return 0;
}
/*
1
5 2
WLWLL

*/