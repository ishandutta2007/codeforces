#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cassert>

const int N = 2e5 + 7;

int n, t;
char digit[N];

void round(int n) {
	assert(digit[n] >= '5');
	for (int i = n - 1; ; i--) {
		if (digit[i] == '.') {
			continue;
		} else if (digit[i] == '9') {
			digit[i] = '0';
		} else {
			digit[i]++;
			break;
		}
	}
}

int main() {
	scanf("%d %d", &n, &t);
	scanf("%s", digit + 1);
	int dot = 0;
	digit[0] = '0';
	for (int i = 1; i <= n; i++) {
		if (digit[i] == '.') {
			dot = i;
			break;
		}
	}
	for (int i = dot; i <= n && t; i++) {
		if (digit[i] >= '5') {
			n = i;
			while (t) {
				int nn = n;
				while (digit[n] != '.' && digit[n] < '5') {
					n--;
				}
				if (digit[n] != '.') {
					t--;
					round(n);
					n--;
				} else {
					n = nn;
					break;
				}
			}
			break;
		}
	}
	int start = (digit[0] == '0' ? 1 : 0);
	if (digit[n] == '.') n--;
	for (int i = start; i <= n; i++) {
		printf("%c", digit[i]);
	}
	puts("");
	return 0;
}