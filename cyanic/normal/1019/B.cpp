#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 100005;
const int inf = 1e9 + 99;
int f[maxn], n, l, r, mid;

void query(int x) {
	if (f[x] < inf) return;
	printf("? %d\n", x); fflush(stdout);
	scanf("%d", &f[x]);	
}

void chk(int x) {
	if (f[x] == f[x+n]) {
		printf("! %d\n", x); fflush(stdout);
		exit(0);
	}
}

int main() {
	memset(f, 0x3f, sizeof f);
	scanf("%d", &n); n /= 2;
	l = 1; r = n;
	query(l); query(l + n); chk(l);
	query(r); query(r + n); chk(r);
	while (r - l >= 3) {
		mid = (l + r) >> 1;
		query(mid); query(mid + n);
		chk(mid);
		if (1ll * (f[l] - f[l+n]) * (f[mid] - f[mid+n]) < 0)
			r = mid;
		else
			l = mid;
	}
	rep (i, l, r) {
		query(i); query(i + n);
		chk(i);
	}
	puts("! -1"); fflush(stdout);
	return 0;
}