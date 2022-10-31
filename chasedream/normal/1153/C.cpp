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

int n, m, xx, yy;
char s[1000005];

void work() {
	int x = 0, y = 0;
	rep(i, 1, n)
		if (s[i] == '(') x++;
		else if (s[i] == ')') y++;
	if (x > (n / 2) || y > (n / 2)) {
		puts(":("); exit(0);
	}

	rep(i, 1, n) {
		if (s[i] == '?') {
			if (x >= (n / 2)) {
				s[i] = ')';
				xx++;
			}
			else {
				s[i] = '(';
				yy++;
				x++;
			}
		}
		else if (s[i] == '(') {
			yy++;
		}
		else xx++;
		
		if (xx >= yy && i != n) {
			puts(":("); exit(0);
		}
	}
}

int main() {
	read(n);
	scanf("%s", s + 1);
	if (n % 2 == 1) return puts(":(") & 0;
	work();
	printf("%s\n", s + 1);
	return 0;
}