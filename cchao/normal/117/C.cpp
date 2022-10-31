#include <bits/stdc++.h>
using namespace std;

int n;
char s[5010][5010] = {{}};
bool v[5010] = {};

void go(int x, int p) {
	v[x] = true;
	for(int i = 1; i <= n; ++i) if(s[x][i] == '1') {
		if(s[i][p] == '1') {
			printf("%d %d %d\n", p, x, i);
			exit(0);
		}
		if(!v[i]) go(i, x);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; ++i) if(!v[i]) go(i, 0);
	puts("-1");
	return 0;
}