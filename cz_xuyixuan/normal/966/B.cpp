#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct info {int val, home; };
info a[MAXN];
bool cmp(info a, info b) {return a.val < b.val; }
int main() {
	int n, x, y;
	read(n), read(x), read(y);
	for (int i = 1; i <= n; i++)
		read(a[i].val), a[i].home = i;
	sort(a + 1, a + n + 1, cmp);
	int posx = 0, posy = 0;
	for (int i = n; i >= 1; i--) {
		int cnt = x / a[i].val + (x % a[i].val != 0);
		if (i + cnt - 1 <= n) {
			posx = i;
			break;
		}
	}
	if (posx == 0) {
		printf("No\n");
		return 0;
	}
	for (int i = n; i >= 1; i--) {
		int cnt = y / a[i].val + (y % a[i].val != 0);
		if (i + cnt - 1 <= n) {
			posy = i;
			break;
		}
	}
	if (posy == 0) {
		printf("No\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int cntx = x / a[i].val + (x % a[i].val != 0);
		if (i + cntx <= posy) {
			printf("Yes\n%d %d\n", cntx, n - posy + 1);
			for (int j = 1; j <= cntx; j++)
				printf("%d ", a[i + j - 1].home);
			printf("\n");
			for (int j = posy; j <= n; j++)
				printf("%d ", a[j].home);
			printf("\n");
			return 0;
		}
		int cnty = y / a[i].val + (y % a[i].val != 0);
		if (i + cnty <= posx) {
			printf("Yes\n%d %d\n", n - posx + 1, cnty);
			for (int j = posx; j <= n; j++)
				printf("%d ", a[j].home);
			printf("\n");
			for (int j = 1; j <= cnty; j++)
				printf("%d ", a[i + j - 1].home);
			printf("\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}