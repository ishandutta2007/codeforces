#include <bits/stdc++.h>

using namespace std;

bool chk[11];

bool f(int n) {
	for(int i = 0; i < 10; i++) chk[i] = false;
	while(n) {
		if(chk[n % 10]) return false;
		chk[n % 10] = true;
		n /= 10;
	}
	return true;
}

int main() {
	int a, b; scanf("%d%d", &a, &b);
	for(int i = a; i <= b; i++) {
		if(f(i)) { printf("%d\n", i); return 0; }
	}
	puts("-1");
	return 0;
}