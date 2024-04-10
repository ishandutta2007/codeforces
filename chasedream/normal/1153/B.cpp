%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define For(i, l, r) rep(i, l, r - 1)

void read(int &x) {
    x = 0; int f = 1;
    char op = getchar();
    while (!isdigit(op)) {
        if (op == '-') f = -1;
        op = getchar();
    }
    while (isdigit(op)) {
        x = 10 * x + op - '0';
        op = getchar();
    }
    x *= f;
}

int a[105], b[150];
int g[105][105];
int n, m, h;

int main() {
	read(n),read(m),read(h);
	rep(i,1,m)read(a[i]);
	rep(j,1,n)read(b[j]);
	rep(i,1,n)rep(j,1,m)read(g[i][j]);
	rep(i,1,n) {
		rep(j,1,m){
			if (g[i][j]==0) printf("0 ");
			else printf("%d ", min(a[j], b[i]));
		}
		putchar('\n');
	}
	return 0;
}