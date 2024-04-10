#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>

#define foreach(e, x) for(__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)

using namespace std;

const int N = 111111;

int n, x, y;
int a[N], l;

bool exist(int v) {
	int p = lower_bound(a, a + n, v) - a;
	return p < n && a[p] == v;
}

void check(int v) {
	if (v < 0 || v > l) {
		return ;
	}
	
	if ((exist(v - x) || exist(v + x)) && (exist(v - y) || exist(v + y))) {
		printf("1\n");
		printf("%d\n", v);
		exit(0);
	}
}

int main() {
	scanf("%d %d %d %d", &n, &l, &x, &y);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	bool ok1 = false, ok2 = false;
	
	// 0
	for(int i = 0; i < n; i++) {
		if (a[i] - x >= 0 && exist(a[i] - x)) {
			ok1 = true;
		}
		if (a[i] - y >= 0 && exist(a[i] - y)) {
			ok2 = true;
		}
	}
	
	if (ok1 && ok2) {
		printf("0\n");
		return 0;
	}
	
	// 1
	
	if (ok2) {
		swap(x, y);
		swap(ok1, ok2);
	}
	
	if (ok1) {
		printf("1\n");
		printf("%d\n", y);
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		check(a[i] + x);
		check(a[i] - x);
		check(a[i] + y);
		check(a[i] - y);
	}
	
	printf("2\n");
	printf("%d %d\n", x, y);
	return 0;
}