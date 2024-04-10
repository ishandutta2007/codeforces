#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

long long a, d;
int n;
long long x, y, step;

void read(long long &a) {
	a = 0;
	char ch = getchar();
	for(; (ch < '0' || ch > '9') && ch != '.'; ch = getchar());
	for(; ch >= '0' && ch <= '9'; ch = getchar()) {
		a = a * 10 + ch - '0';
	}
	
	if (ch == '.') {
		int cnt = 4;
		for(ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) {
			cnt--;
			a = a * 10 + ch - '0';
		}
		
		while(cnt--) {
			a *= 10;
		}
	} else {
		a *= 10000;
	}
}

int main() {
	read(a);
	read(d);
	scanf("%d", &n);
	d %= 4 * a;
	x = y = 0;
	step = d;
	for(int i = 1; i <= n; i++) {
		if (step == 0) {
			printf("%.6f %.6f\n", x / 10000.0, y / 10000.0);
			step = d;
			continue;
		} else if (y == 0 && x < a) {
			if (x + step >= a) {
				step -= a - x;
				x = a;
			} else {
				x += step;
				step = 0;
			}
		} else if (x == a && y < a) {
			if (y + step >= a) {
				step -= (a - y);
				y = a;
			} else {
				y += step;
				step = 0;
			}
		} else if (x > 0 && y == a) {
			if (x - step <= 0) {
				step -= x;
				x = 0;
			} else {
				x -= step;
				step = 0;
			}
		} else if (x == 0 && y > 0) {
			if (y - step <= 0) {
				step -= y;
				y = 0;
			} else {
				y -= step;
				step = 0;
			}
		}
		i--;
	}
	return 0;
}