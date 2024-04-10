#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int win = 0, draw = 0, lose = 0;
	for(int i = 1; i <= 6; ++i) {
		int da = abs(i - a);
		int db = abs(i - b);
		if(da < db) win++;
		else if(da == db) draw++;
		else lose++;
	}
	printf("%d %d %d\n", win, draw, lose);
	return 0;
}