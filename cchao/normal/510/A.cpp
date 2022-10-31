#include <bits/stdc++.h>
using namespace std;

char a[55][55] = {{}};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) a[i][j] = '.';
	int i = 0;
	while(i < n) {
		int j, dir;
		if(i % 4 == 0) j = 0, dir = 1;
		else j = m - 1, dir = -1;
		while(j >= 0 && j < m) {
			a[i][j] = '#';
			j += dir;
		}
		j -= dir;
		if(i + 1 < n) a[i+1][j] = '#';
		i += 2;
	}
	for(int i = 0; i < n; ++i) puts(a[i]);

	return 0;
}