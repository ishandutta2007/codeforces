#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int x[maxn], y[maxn], n;
char s[55];

bool query(int X1, int Y1, int X2, int Y2) {
	printf("? %d %d %d %d\n", X1, Y1, X2, Y2);
	fflush(stdout);
	scanf("%s", s);
	return s[0] == 'Y';
}

int main() {
	scanf("%d", &n);
	x[1] = y[1] = 1;
	x[2*n-1] = y[2*n-1] = n;
	rep (i, 2, n) {
		if (x[i-1]+1 <= n &&  query(x[i-1]+1, y[i-1], n, n))
			x[i] = x[i-1]+1, y[i] = y[i-1];
		else
			x[i] = x[i-1], y[i] = y[i-1]+1;
	}
	per (i,  2 * n - 2, n + 1) {
		if (y[i+1]-1 >= 1 && query(1, 1, x[i+1], y[i+1]-1))
			x[i] = x[i+1], y[i] = y[i+1]-1;
		else
			x[i] = x[i+1]-1, y[i] = y[i+1];
	}
	putchar('!'); putchar(' ');
	rep (i, 1, 2 * n - 2)
		if (x[i+1] == x[i] + 1) putchar('D');
		else putchar('R');
	return 0;
}