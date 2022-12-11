#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void output(int x, int y) {
	printf("%d %d\n", x, y);
	fflush(stdout);
}

int n;
char buf[1000];
int main() {
	scanf("%d", &n);
	output(0, 500);
	int l = 1, r = 1000000000;
	scanf("%s", buf);
	bool t = *buf == 'b';
	for (int i = 2; i <= n; ++i) {
		int mid = l + r + 1 >> 1;
		output(mid, 500);
		scanf("%s", buf);
		if ((*buf == 'b') ^ t) r = mid;
		else l = mid;
	}
	/*
	for (int i = 1; i <= n; ++i) {
		int mid = l + r >> 1;
		output(mid, 50);
		scanf("%s", buf);
		if (*buf == 'b') l = mid;
		else r = mid;
	}
	*/
	cout << l << " " << 0 << " " << r << " " << 10000 << endl;
	return 0;
}