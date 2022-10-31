#include <bits/stdc++.h>
using namespace std;

const int N= 5100;

char str[N];

int main() {
	gets(str);
	int len = strlen(str), ans = 0;
	for (int i = 0; i < len; i++) {
		int st = 0, en = 0;
		for (int j = i; j < len; j++) {
			if (str[j] == '(') {
				st++, en++;
			} else if (str[j] == ')') {
				st--, en--;
				if (st == -1) st = 1;
				if (en == -1) break;
			} else {
				if (st > 0) {
					st--, en++;
				} else {
					st++; en++;
				}
			}
			if(st == 0) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}