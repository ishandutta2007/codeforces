#include <iostream>

using namespace std;

const int N = 2e5 + 7;

char s[N];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int l = n, r = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '>') {
			l = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '<') {
			r = i;
			break;
		}
	}
	if (l > r) {
		printf("%d\n", n);
	} else if (l < r) {
		printf("%d\n", l + n - 1 - r);
	}
	return 0;
}